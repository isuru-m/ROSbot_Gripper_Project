// Generated by gencpp from file gripper_pkg/servoServiceResponse.msg
// DO NOT EDIT!


#ifndef GRIPPER_PKG_MESSAGE_SERVOSERVICERESPONSE_H
#define GRIPPER_PKG_MESSAGE_SERVOSERVICERESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace gripper_pkg
{
template <class ContainerAllocator>
struct servoServiceResponse_
{
  typedef servoServiceResponse_<ContainerAllocator> Type;

  servoServiceResponse_()
    : success(false)  {
    }
  servoServiceResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> const> ConstPtr;

}; // struct servoServiceResponse_

typedef ::gripper_pkg::servoServiceResponse_<std::allocator<void> > servoServiceResponse;

typedef boost::shared_ptr< ::gripper_pkg::servoServiceResponse > servoServiceResponsePtr;
typedef boost::shared_ptr< ::gripper_pkg::servoServiceResponse const> servoServiceResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gripper_pkg::servoServiceResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace gripper_pkg

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'gripper_pkg': ['/home/husarion/ros_ws/devel/share/gripper_pkg/msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::gripper_pkg::servoServiceResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gripper_pkg/servoServiceResponse";
  }

  static const char* value(const ::gripper_pkg::servoServiceResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n\
\n\
";
  }

  static const char* value(const ::gripper_pkg::servoServiceResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct servoServiceResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gripper_pkg::servoServiceResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gripper_pkg::servoServiceResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GRIPPER_PKG_MESSAGE_SERVOSERVICERESPONSE_H
