INCPATH = -I/usr/local/lib/boost_1_47_0/boost
LIBS = -lboost_system -lboost_thread -lpthread
SOURCES = main.cpp

Client:
	g++ $(INCPATH) $(LIBS) $(SOURCES) -o client.o
	./client.o localhost 8124
	rm client.o