// Generated by gencpp from file rft_sensor_serial/rft_operation.msg
// DO NOT EDIT!


#ifndef RFT_SENSOR_SERIAL_MESSAGE_RFT_OPERATION_H
#define RFT_SENSOR_SERIAL_MESSAGE_RFT_OPERATION_H

#include <ros/service_traits.h>


#include <rft_sensor_serial/rft_operationRequest.h>
#include <rft_sensor_serial/rft_operationResponse.h>


namespace rft_sensor_serial
{

struct rft_operation
{

typedef rft_operationRequest Request;
typedef rft_operationResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct rft_operation
} // namespace rft_sensor_serial


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::rft_sensor_serial::rft_operation > {
  static const char* value()
  {
    return "5b818d3a3d5cb051d3d33d376492250b";
  }

  static const char* value(const ::rft_sensor_serial::rft_operation&) { return value(); }
};

template<>
struct DataType< ::rft_sensor_serial::rft_operation > {
  static const char* value()
  {
    return "rft_sensor_serial/rft_operation";
  }

  static const char* value(const ::rft_sensor_serial::rft_operation&) { return value(); }
};


// service_traits::MD5Sum< ::rft_sensor_serial::rft_operationRequest> should match
// service_traits::MD5Sum< ::rft_sensor_serial::rft_operation >
template<>
struct MD5Sum< ::rft_sensor_serial::rft_operationRequest>
{
  static const char* value()
  {
    return MD5Sum< ::rft_sensor_serial::rft_operation >::value();
  }
  static const char* value(const ::rft_sensor_serial::rft_operationRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::rft_sensor_serial::rft_operationRequest> should match
// service_traits::DataType< ::rft_sensor_serial::rft_operation >
template<>
struct DataType< ::rft_sensor_serial::rft_operationRequest>
{
  static const char* value()
  {
    return DataType< ::rft_sensor_serial::rft_operation >::value();
  }
  static const char* value(const ::rft_sensor_serial::rft_operationRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::rft_sensor_serial::rft_operationResponse> should match
// service_traits::MD5Sum< ::rft_sensor_serial::rft_operation >
template<>
struct MD5Sum< ::rft_sensor_serial::rft_operationResponse>
{
  static const char* value()
  {
    return MD5Sum< ::rft_sensor_serial::rft_operation >::value();
  }
  static const char* value(const ::rft_sensor_serial::rft_operationResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::rft_sensor_serial::rft_operationResponse> should match
// service_traits::DataType< ::rft_sensor_serial::rft_operation >
template<>
struct DataType< ::rft_sensor_serial::rft_operationResponse>
{
  static const char* value()
  {
    return DataType< ::rft_sensor_serial::rft_operation >::value();
  }
  static const char* value(const ::rft_sensor_serial::rft_operationResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // RFT_SENSOR_SERIAL_MESSAGE_RFT_OPERATION_H
