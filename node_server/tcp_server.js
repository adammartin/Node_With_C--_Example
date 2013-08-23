var net = require('net');
var fs = require('fs');
var proto = require('node-protobuf').Protobuf;

var server = net.createServer(function(connection) {
  var lastMessageId = 0;
  var protobuf = new proto(fs.readFileSync("../c++_client/message.desc"));
  var lostMessageCount = 0;

  console.log('server connected');
  connection.on('end', function() {
    console.log('server disconnected');
  });

  connection.addListener("data", function (data) {
    var dataPacket = protobuf.Parse(data, "example.DataPacket");
    if(!(dataPacket.id != 0 && lastMessageId == 0) && (dataPacket.id != lastMessageId + 1))
    {
      lostMessageCount++;
    }
    lastMessageId = dataPacket.id;
    console.log(JSON.stringify(dataPacket));
    console.log("\nLostMessageCount: " + lostMessageCount + "\n");
    console.log("dataPacket.id = " + dataPacket.id + "\n");
  });
});

server.listen(8124, function() {
  console.log('server bound');
});
