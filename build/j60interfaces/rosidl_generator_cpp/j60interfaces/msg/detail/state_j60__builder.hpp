// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from j60interfaces:msg/StateJ60.idl
// generated code does not contain a copyright notice

#ifndef J60INTERFACES__MSG__DETAIL__STATE_J60__BUILDER_HPP_
#define J60INTERFACES__MSG__DETAIL__STATE_J60__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "j60interfaces/msg/detail/state_j60__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace j60interfaces
{

namespace msg
{

namespace builder
{

class Init_StateJ60_flag
{
public:
  explicit Init_StateJ60_flag(::j60interfaces::msg::StateJ60 & msg)
  : msg_(msg)
  {}
  ::j60interfaces::msg::StateJ60 flag(::j60interfaces::msg::StateJ60::_flag_type arg)
  {
    msg_.flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::j60interfaces::msg::StateJ60 msg_;
};

class Init_StateJ60_temp
{
public:
  explicit Init_StateJ60_temp(::j60interfaces::msg::StateJ60 & msg)
  : msg_(msg)
  {}
  Init_StateJ60_flag temp(::j60interfaces::msg::StateJ60::_temp_type arg)
  {
    msg_.temp = std::move(arg);
    return Init_StateJ60_flag(msg_);
  }

private:
  ::j60interfaces::msg::StateJ60 msg_;
};

class Init_StateJ60_torque
{
public:
  explicit Init_StateJ60_torque(::j60interfaces::msg::StateJ60 & msg)
  : msg_(msg)
  {}
  Init_StateJ60_temp torque(::j60interfaces::msg::StateJ60::_torque_type arg)
  {
    msg_.torque = std::move(arg);
    return Init_StateJ60_temp(msg_);
  }

private:
  ::j60interfaces::msg::StateJ60 msg_;
};

class Init_StateJ60_velocity
{
public:
  explicit Init_StateJ60_velocity(::j60interfaces::msg::StateJ60 & msg)
  : msg_(msg)
  {}
  Init_StateJ60_torque velocity(::j60interfaces::msg::StateJ60::_velocity_type arg)
  {
    msg_.velocity = std::move(arg);
    return Init_StateJ60_torque(msg_);
  }

private:
  ::j60interfaces::msg::StateJ60 msg_;
};

class Init_StateJ60_position
{
public:
  explicit Init_StateJ60_position(::j60interfaces::msg::StateJ60 & msg)
  : msg_(msg)
  {}
  Init_StateJ60_velocity position(::j60interfaces::msg::StateJ60::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_StateJ60_velocity(msg_);
  }

private:
  ::j60interfaces::msg::StateJ60 msg_;
};

class Init_StateJ60_cmd
{
public:
  explicit Init_StateJ60_cmd(::j60interfaces::msg::StateJ60 & msg)
  : msg_(msg)
  {}
  Init_StateJ60_position cmd(::j60interfaces::msg::StateJ60::_cmd_type arg)
  {
    msg_.cmd = std::move(arg);
    return Init_StateJ60_position(msg_);
  }

private:
  ::j60interfaces::msg::StateJ60 msg_;
};

class Init_StateJ60_motor_id
{
public:
  Init_StateJ60_motor_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_StateJ60_cmd motor_id(::j60interfaces::msg::StateJ60::_motor_id_type arg)
  {
    msg_.motor_id = std::move(arg);
    return Init_StateJ60_cmd(msg_);
  }

private:
  ::j60interfaces::msg::StateJ60 msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::j60interfaces::msg::StateJ60>()
{
  return j60interfaces::msg::builder::Init_StateJ60_motor_id();
}

}  // namespace j60interfaces

#endif  // J60INTERFACES__MSG__DETAIL__STATE_J60__BUILDER_HPP_
