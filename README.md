Node_With_C--_Example
=====================

A fun little spike on how to push data from C++ source to a website using Node as a middle ware connection.

Requirements
============
You must install the following frameworks and modules:
[*] Boost
[*] Node
[*] node-protobuf ( npm install node-protobuf )
[*] websocket ( npm install websocket )

The application assumes standard boost install directory if you installed the headers in a special location you will need to modify the Makefile.


To Run
======
Navigate to node_server directory and type:
     node tcp_server.js
     
This will start the node middle ware server.

Navigate to c++_client directory and type:
     make

This will start a command line c++ message broadcaster that you can tell to send as many messages as you desire.

In a browser open the WebSocketClient.html which will connect to the node server.

Start sending messages and watch the WebSocketClient receive the messages.
