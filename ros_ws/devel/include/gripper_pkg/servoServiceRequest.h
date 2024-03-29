// Generated by gencpp from file gripper_pkg/servoServiceRequest.msg
// DO NOT EDIT!


#ifndef GRIPPER_PKG_MESSAGE_SERVOSERVICEREQUEST_H
#define GRIPPER_PKG_MESSAGE_SERVOSERVICEREQUEST_H


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
struct servoServiceRequest_
{
  typedef servoServiceRequest_<ContainerAllocator> Type;

  servoServiceRequest_()
    : radius(0.0)  {
    }
  servoServiceRequest_(const ContainerAllocator& _alloc)
    : radius(0.0)  {
  (void)_alloc;
    }



   typedef float _radius_type;
  _radius_type radius;





  typedef boost::shared_ptr< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> const> ConstPtr;

}; // struct servoServiceRequest_

typedef ::gripper_pkg::servoServiceRequest_<std::allocator<void> > servoServiceRequest;

typedef boost::shared_ptr< ::gripper_pkg::servoServiceRequest > servoServiceRequestPtr;
typedef boost::shared_ptr< ::gripper_pkg::servoServiceRequest const> servoServiceRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::gripper_pkg::servoServiceRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0b690044065f2210effb664cc7a28125";
  }

  static const char* value(const ::gripper_pkg::servoServiceRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0b690044065f2210ULL;
  static const uint64_t static_value2 = 0xeffb664cc7a28125ULL;
};

template<class ContainerAllocator>
struct DataType< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "gripper_pkg/servoServiceRequest";
  }

  static const char* value(const ::gripper_pkg::servoServiceRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 radius\n\
";
  }

  static const char* value(const ::gripper_pkg::servoServiceRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.radius);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct servoServiceRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::gripper_pkg::servoServiceRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::gripper_pkg::servoServiceRequest_<ContainerAllocator>& v)
  {
    s << indent << "radius: ";
    Printer<float>::stream(s, indent + "  ", v.radius);
  }
};

} // namespace message_operations
} // namespace ros

#endif // GRIPPER_PKG_MESSAGE_SERVOSERVICEREQUEST_H
