// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from j60interfaces:msg/StateJ60.idl
// generated code does not contain a copyright notice

#ifndef J60INTERFACES__MSG__DETAIL__STATE_J60__TRAITS_HPP_
#define J60INTERFACES__MSG__DETAIL__STATE_J60__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "j60interfaces/msg/detail/state_j60__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace j60interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const StateJ60 & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_id
  {
    out << "motor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_id, out);
    out << ", ";
  }

  // member: cmd
  {
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
    out << ", ";
  }

  // member: position
  {
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << ", ";
  }

  // member: velocity
  {
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << ", ";
  }

  // member: torque
  {
    out << "torque: ";
    rosidl_generator_traits::value_to_yaml(msg.torque, out);
    out << ", ";
  }

  // member: temp
  {
    out << "temp: ";
    rosidl_generator_traits::value_to_yaml(msg.temp, out);
    out << ", ";
  }

  // member: flag
  {
    out << "flag: ";
    rosidl_generator_traits::value_to_yaml(msg.flag, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const StateJ60 & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "motor_id: ";
    rosidl_generator_traits::value_to_yaml(msg.motor_id, out);
    out << "\n";
  }

  // member: cmd
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cmd: ";
    rosidl_generator_traits::value_to_yaml(msg.cmd, out);
    out << "\n";
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position: ";
    rosidl_generator_traits::value_to_yaml(msg.position, out);
    out << "\n";
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "velocity: ";
    rosidl_generator_traits::value_to_yaml(msg.velocity, out);
    out << "\n";
  }

  // member: torque
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "torque: ";
    rosidl_generator_traits::value_to_yaml(msg.torque, out);
    out << "\n";
  }

  // member: temp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temp: ";
    rosidl_generator_traits::value_to_yaml(msg.temp, out);
    out << "\n";
  }

  // member: flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flag: ";
    rosidl_generator_traits::value_to_yaml(msg.flag, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const StateJ60 & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace j60interfaces

namespace rosidl_generator_traits
{

[[deprecated("use j60interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const j60interfaces::msg::StateJ60 & msg,
  std::ostream & out, size_t indentation = 0)
{
  j60interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use j60interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const j60interfaces::msg::StateJ60 & msg)
{
  return j60interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<j60interfaces::msg::StateJ60>()
{
  return "j60interfaces::msg::StateJ60";
}

template<>
inline const char * name<j60interfaces::msg::StateJ60>()
{
  return "j60interfaces/msg/StateJ60";
}

template<>
struct has_fixed_size<j60interfaces::msg::StateJ60>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<j60interfaces::msg::StateJ60>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<j60interfaces::msg::StateJ60>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // J60INTERFACES__MSG__DETAIL__STATE_J60__TRAITS_HPP_
