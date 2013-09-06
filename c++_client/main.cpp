#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/lexical_cast.hpp>
#include "ProtoEqModel.pb.h"

using boost::asio::ip::tcp;

const static std::string MACHINE_SERIAL_NUMBER = "123456789";
const static double LATITUDE = 41.600397;
const static double LONGITUDE = -93.608982;

std::string SerializeModelAsString(int originalId)
{
  int id = originalId; 
  EqModel::ProtoEquipmentModel model;
  model.set_key(boost::lexical_cast<std::string>(++id));

  EqModel::Offset* offsets = new EqModel::Offset();
  offsets->set_inline_(0.0);
  offsets->set_lateral(0.0);
  offsets->set_height(117.0);

  EqModel::Offset* connectionOffsets = new EqModel::Offset();
  connectionOffsets->set_inline_(100.0);
  connectionOffsets->set_lateral(100.0);
  connectionOffsets->set_height(10.0);

  EqModel::ProtoFrame* frame = model.add_frames();
  frame->set_key("tractor_key");
  frame->set_description("A sample tractor example");
  frame->set_releasedate(std::time(0));
  frame->set_lastmodifieddate(std::time(0));
  frame->set_frametype(::EqModel::FT_MACHINE);
  frame->set_receiverid(id++);
  frame->set_frontoffset(0.0011);
  frame->set_turnradius(0.0012);
  frame->set_turnsensitivity(0.0013);
  frame->set_allocated_serialnumber(new std::string(MACHINE_SERIAL_NUMBER));
  frame->set_wheelbaseamount(0.0014);
  frame->set_allocated_configurationglobalid(new std::string(MACHINE_SERIAL_NUMBER));
  frame->set_allocated_model(new std::string("FT4"));
  frame->set_allocated_gps(new std::string(boost::lexical_cast<std::string>(LATITUDE+(0.000001*id))
    + ", " + boost::lexical_cast<std::string>(LONGITUDE+(0.00000025*id))));
  frame->set_allocated_receiveroffset(offsets);
  frame->set_nonsteeringaxle(EqModel::AL_REAR_AXLE);

  EqModel::ProtoConnection* connection = frame->add_connections();
  connection->set_allocated_connectionoffset(connectionOffsets);
  connection->set_connectionposition(EqModel::CP_REAR);
  connection->set_hitchtype(EqModel::HT_TRACTOR_DRAWBAR);

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

    for(int i = 0; i < messageCount; i++)
    {
      std::string asString = SerializeModelAsString(i);
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