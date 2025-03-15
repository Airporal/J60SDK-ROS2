// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from j60interfaces:msg/StateJ60.idl
// generated code does not contain a copyright notice

#ifndef J60INTERFACES__MSG__DETAIL__STATE_J60__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define J60INTERFACES__MSG__DETAIL__STATE_J60__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "j60interfaces/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "j60interfaces/msg/detail/state_j60__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace j60interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_j60interfaces
cdr_serialize(
  const j60interfaces::msg::StateJ60 & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_j60interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  j60interfaces::msg::StateJ60 & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_j60interfaces
get_serialized_size(
  const j60interfaces::msg::StateJ60 & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_j60interfaces
max_serialized_size_StateJ60(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace j60interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_j60interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, j60interfaces, msg, StateJ60)();

#ifdef __cplusplus
}
#endif

#endif  // J60INTERFACES__MSG__DETAIL__STATE_J60__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
