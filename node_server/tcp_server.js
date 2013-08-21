var net = require('net');
var fs = require('fs');
var proto = require('node-protobuf').Protobuf;

var server = net.createServer(function(connection) {
  var protobuf = new proto(fs.readFileSync("../c++_client/message.desc"));

  console.log('server connected');
  connection.on('end', function() {
    console.log('server disconnected');
  });

  connection.addListener("data", function (data) {
  	var payload = protobuf.Parse(data, "example.DataPacket");
    console.log("Data received from client: " + JSON.stringify(protobuf.Parse(data, "example.DataPacket")));
  });
});

server.listen(8124, function() {
  console.log('server bound');
});
