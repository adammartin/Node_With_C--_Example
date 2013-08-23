var net = require('net');
var fs = require('fs');
var proto = require('node-protobuf').Protobuf;
var serverPort = 8124;

var server = net.createServer(function(socket) {
  var lastMessageId = 0;
  var lostMessageCount = 0;
  var protobuf = new proto(fs.readFileSync("../c++_client/message.desc"));

  console.log('server connected');
  socket.on('end', function() {
    console.log('server disconnected');
  });

  socket.addListener("data", function (data) {
    if(data.length == 8) {
      console.log("Message chain complete resetting last messageId.");
      lastMessageId = 0;
      return;
    }
    var dataPacket = protobuf.Parse(data, "example.DataPacket");
    if(!(dataPacket.id != 0 && lastMessageId == 0) && (dataPacket.id != lastMessageId + 1))
    {
      lostMessageCount += dataPacket.id - lastMessageId;
    }
    lastMessageId = dataPacket.id;
    console.log(JSON.stringify(dataPacket));
    console.log("\nLostMessageCount: " + lostMessageCount + "\n");
    console.log("dataPacket.id = " + dataPacket.id + "\n");

    socket.write("ack");
  });
});

server.listen(serverPort, function() {
  console.log('server bound');
});
