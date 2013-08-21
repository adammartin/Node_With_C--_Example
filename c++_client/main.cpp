#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include "message.pb.h"

using boost::asio::ip::tcp;

std::string make_daytime_string()
{
  std::time_t now = std::time(0);
  return std::ctime(&now);
}

int main(int argc, char* argv[])
{
  int count = 1;
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

    tcp::socket s(io_service);
    s.connect(*iterator);

    example::DataPacket dataPacket;
    dataPacket.set_id(count++);
    dataPacket.add_payload()->set_timestamp(make_daytime_string());
    dataPacket.add_payload()->set_timestamp(make_daytime_string());
    dataPacket.add_payload()->set_timestamp(make_daytime_string());
    dataPacket.add_payload()->set_timestamp(make_daytime_string());
    dataPacket.add_payload()->set_timestamp(make_daytime_string());
    dataPacket.add_payload()->set_timestamp(make_daytime_string());

    boost::system::error_code ignored_error;
    boost::asio::write(s, boost::asio::buffer(dataPacket.SerializeAsString()), boost::asio::transfer_all(), ignored_error);

    usleep(2000); // why do I need a usleep?
    s.close();
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}