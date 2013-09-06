INCPATH = -I/usr/include/boost 
LIBS = -lboost_system -lboost_thread -lpthread -lprotobuf
SOURCES = main.cpp ProtoEqModel.pb.h ProtoEqModel.pb.cc

Client:
	g++ $(SOURCES) $(INCPATH) $(LIBS) -o client.o
	./client.o localhost 8124
	rm client.o