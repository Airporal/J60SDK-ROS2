// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from j60interfaces:msg/MoveJ60.idl
// generated code does not contain a copyright notice

#ifndef J60INTERFACES__MSG__DETAIL__MOVE_J60__BUILDER_HPP_
#define J60INTERFACES__MSG__DETAIL__MOVE_J60__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "j60interfaces/msg/detail/move_j60__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace j60interfaces
{

namespace msg
{

namespace builder
{

class Init_MoveJ60_torque
{
public:
  explicit Init_MoveJ60_torque(::j60interfaces::msg::MoveJ60 & msg)
  : msg_(msg)
  {}
  ::j60interfaces::msg::MoveJ60 torque(::j60interfaces::msg::MoveJ60::_torque_type arg)
  {
    msg_.torque = std::move(arg);
    return std::move(msg_);
  }

private:
  ::j60interfaces::msg::MoveJ60 msg_;
};

class Init_MoveJ60_kd
{
public:
  explicit Init_MoveJ60_kd(::j60interfaces::msg::MoveJ60 & msg)
  : msg_(msg)
  {}
  Init_MoveJ60_torque kd(::j60interfaces::msg::MoveJ60::_kd_type arg)
  {
    msg_.kd = std::move(arg);
    return Init_MoveJ60_torque(msg_);
  }

private:
  ::j60interfaces::msg::MoveJ60 msg_;
};

class Init_MoveJ60_kp
{
public:
  explicit Init_MoveJ60_kp(::j60interfaces::msg::MoveJ60 & msg)
  : msg_(msg)
  {}
  Init_MoveJ60_kd kp(::j60interfaces::msg::MoveJ60::_kp_type arg)
  {
    msg_.kp = std::move(arg);
    return Init_MoveJ60_kd(msg_);
  }

private:
  ::j60interfaces::msg::MoveJ60 msg_;
};

class Init_MoveJ60_velocity
{
public:
  explicit Init_MoveJ60_velocity(::j60interfaces::msg::MoveJ60 & msg)
  : msg_(msg)
  {}
  Init_MoveJ60_kp velocity(::j60interfaces::msg::MoveJ60::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_MoveJ60_kp(msg_);
  }

private:
  ::j60interfaces::msg::MoveJ60 msg_;
};

class Init_MoveJ60_position
{
public:
  Init_MoveJ60_position()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MoveJ60_velocity position(::j60interfaces::msg::MoveJ60::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_MoveJ60_velocity(msg_);
  }

private:
  ::j60interfaces::msg::MoveJ60 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::j60interfaces::msg::MoveJ60>()
{
  return j60interfaces::msg::builder::Init_MoveJ60_position();
}

}  // namespace j60interfaces

#endif  // J60INTERFACES__MSG__DETAIL__MOVE_J60__BUILDER_HPP_
