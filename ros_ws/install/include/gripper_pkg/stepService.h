// Generated by gencpp from file gripper_pkg/stepService.msg
// DO NOT EDIT!


#ifndef GRIPPER_PKG_MESSAGE_STEPSERVICE_H
#define GRIPPER_PKG_MESSAGE_STEPSERVICE_H

#include <ros/service_traits.h>


#include <gripper_pkg/stepServiceRequest.h>
#include <gripper_pkg/stepServiceResponse.h>


namespace gripper_pkg
{

struct stepService
{

typedef stepServiceRequest Request;
typedef stepServiceResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct stepService
} // namespace gripper_pkg


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::gripper_pkg::stepService > {
  static const char* value()
  {
    return "eddfa10760234970c83c5339187b1c40";
  }

  static const char* value(const ::gripper_pkg::stepService&) { return value(); }
};

template<>
struct DataType< ::gripper_pkg::stepService > {
  static const char* value()
  {
    return "gripper_pkg/stepService";
  }

  static const char* value(const ::gripper_pkg::stepService&) { return value(); }
};


// service_traits::MD5Sum< ::gripper_pkg::stepServiceRequest> should match 
// service_traits::MD5Sum< ::gripper_pkg::stepService > 
template<>
struct MD5Sum< ::gripper_pkg::stepServiceRequest>
{
  static const char* value()
  {
    return MD5Sum< ::gripper_pkg::stepService >::value();
  }
  static const char* value(const ::gripper_pkg::stepServiceRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::gripper_pkg::stepServiceRequest> should match 
// service_traits::DataType< ::gripper_pkg::stepService > 
template<>
struct DataType< ::gripper_pkg::stepServiceRequest>
{
  static const char* value()
  {
    return DataType< ::gripper_pkg::stepService >::value();
  }
  static const char* value(const ::gripper_pkg::stepServiceRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::gripper_pkg::stepServiceResponse> should match 
// service_traits::MD5Sum< ::gripper_pkg::stepService > 
template<>
struct MD5Sum< ::gripper_pkg::stepServiceResponse>
{
  static const char* value()
  {
    return MD5Sum< ::gripper_pkg::stepService >::value();
  }
  static const char* value(const ::gripper_pkg::stepServiceResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::gripper_pkg::stepServiceResponse> should match 
// service_traits::DataType< ::gripper_pkg::stepService > 
template<>
struct DataType< ::gripper_pkg::stepServiceResponse>
{
  static const char* value()
  {
    return DataType< ::gripper_pkg::stepService >::value();
  }
  static const char* value(const ::gripper_pkg::stepServiceResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // GRIPPER_PKG_MESSAGE_STEPSERVICE_H
