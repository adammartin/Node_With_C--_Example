#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include "message.pb.h"
#include "ProtoEqModel.pb.h"

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
  std::time_t now = std::time(0);
  return std::ctime(&now);
}

std::string SerializeDataAsString(int id, std::string& timestamp)
{
  example::DataPacket dataPacket;
  dataPacket.set_id(id+1);
  for(int k = 0; k < 500; k++ )
  {
    dataPacket.add_payload()->set_timestamp(timestamp);
  }

  return dataPacket.SerializeAsString();
}

std::string SerializeModelAsString(int id, std::string& timestamp)
{
  EqModel::ProtoEquipmentModel model;
  model.set_key(boost::lexical_cast<std::string>(id));

  EqModel::ProtoFrame* frame = model.add_frames();
  frame->set_key("tractor_key");
  frame->set_description("A sample tractor example");
  frame->set_releasedate(std::time(0));
  frame->set_lastmodifieddate(std::time(0));
  frame->set_frametype(::EqModel::FT_MACHINE);

  return model.SerializeAsString();
}

void transmit_data(tcp::socket& mySocket) 
{
  boost::system::error_code ignored_error;
  while(true)
  {
    int messageCount = 0;
    std::cout << "Please input number of messages to send (enter 0 to quit): \n";
    std::cin >> messageCount;
    if(messageCount == 0) break;
    std::string timestamp = make_daytime_string();
    for(int i = 0; i < messageCount; i++)
    {
      std::string asString = SerializeModelAsString(i, timestamp);
      boost::asio::write(mySocket, boost::asio::buffer(asString, asString.size()), boost::asio::transfer_all(), ignored_error);

      boost::asio::streambuf response;
      boost::asio::read_until(mySocket, response, "ack");
    }

    std::string complete = "complete";
    boost::asio::write(mySocket, boost::asio::buffer(complete, complete.size()), boost::asio::transfer_all(), ignored_error);
  }
}

int main(int argc, char* argv[])
{
  try
  {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    if (argc != 3)
    {
      std::cerr << "Usage: <App_Name_Here> <host> <port>\n";
      return 1;
    }

    boost::asio::io_service io_service;

    tcp::resolver resolver(io_service);
    tcp::resolver::query query(tcp::v4(), argv[1], argv[2]);
    tcp::resolver::iterator iterator = resolver.resolve(query);

    tcp::socket mySocket(io_service);
    mySocket.connect(*iterator);

    transmit_data(mySocket);

    mySocket.close();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}