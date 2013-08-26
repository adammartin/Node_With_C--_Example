#!/usr/bin/env node

/*
* Need to look into BSON for encoding the message structure to the client.
*/
var net = require('net');
var fs = require('fs');
var proto = require('node-protobuf').Protobuf;
var WebSocketServer = require('websocket').server;
var http = require('http');
var tcpServerPort = 8124;
var httpServerPort = 8080;
var wsConnection = null;

/**** WebServer Connection Stuff ****/

var myHttpServer = http.createServer(function(request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
    response.writeHead(404);
    response.end();
});

myHttpServer.listen(httpServerPort, function() {
    console.log((new Date()) + ' Server is listening on port ' + httpServerPort);
});

wsServer = new WebSocketServer({
    httpServer: myHttpServer,
    // You should not use autoAcceptConnections for production
    // applications, as it defeats all standard cross-origin protection
    // facilities built into the protocol and the browser.  You should
    // *always* verify the connection's origin and decide whether or not
    // to accept it.
    autoAcceptConnections: false
});

function originIsAllowed(origin) {
  // put logic here to detect whether the specified origin is allowed.
  return true;
}

wsServer.on('request', function(request) {
    if (!originIsAllowed(request.origin)) {
      // Make sure we only accept requests from an allowed origin
      request.reject();
      console.log((new Date()) + ' Connection from origin ' + request.origin + ' rejected.');
      return;
    }

    wsConnection = request.accept('echo-protocol', request.origin);
    console.log((new Date()) + ' Connection accepted.');

    wsConnection.on('close', function(reasonCode, description) {
      console.log((new Date()) + ' Peer ' + wsConnection.remoteAddress + ' disconnected.');
      wsConnection = null;
    });
});

/**** TCP SERVER CONNECTION STUFF ****/

var tcpServer = net.createServer(function(socket) {
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
    if(!(dataPacket.id != 0 && lastMessageId == 0) && (dataPacket.id != lastMessageId + 1)) {
      lostMessageCount += dataPacket.id - lastMessageId;
    }
    lastMessageId = dataPacket.id;
    if(wsConnection != null) {
      wsConnection.sendUTF(JSON.stringify(dataPacket));
    }
    // console.log(JSON.stringify(dataPacket));
    console.log("\nLostMessageCount: " + lostMessageCount + "\n");
    console.log("dataPacket.id = " + dataPacket.id + "\n");

    socket.write("ack");
  });
});

tcpServer.listen(tcpServerPort, function() {
  console.log('server bound');
});
