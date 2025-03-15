// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from j60interfaces:msg/StateJ60.idl
// generated code does not contain a copyright notice

#ifndef J60INTERFACES__MSG__DETAIL__STATE_J60__STRUCT_HPP_
#define J60INTERFACES__MSG__DETAIL__STATE_J60__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__j60interfaces__msg__StateJ60 __attribute__((deprecated))
#else
# define DEPRECATED__j60interfaces__msg__StateJ60 __declspec(deprecated)
#endif

namespace j60interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct StateJ60_
{
  using Type = StateJ60_<ContainerAllocator>;

  explicit StateJ60_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->cmd = 0;
      this->position = 0.0f;
      this->velocity = 0.0f;
      this->torque = 0.0f;
      this->temp = 0.0f;
      this->flag = false;
    }
  }

  explicit StateJ60_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->motor_id = 0;
      this->cmd = 0;
      this->position = 0.0f;
      this->velocity = 0.0f;
      this->torque = 0.0f;
      this->temp = 0.0f;
      this->flag = false;
    }
  }

  // field types and members
  using _motor_id_type =
    uint8_t;
  _motor_id_type motor_id;
  using _cmd_type =
    uint8_t;
  _cmd_type cmd;
  using _position_type =
    float;
  _position_type position;
  using _velocity_type =
    float;
  _velocity_type velocity;
  using _torque_type =
    float;
  _torque_type torque;
  using _temp_type =
    float;
  _temp_type temp;
  using _flag_type =
    bool;
  _flag_type flag;

  // setters for named parameter idiom
  Type & set__motor_id(
    const uint8_t & _arg)
  {
    this->motor_id = _arg;
    return *this;
  }
  Type & set__cmd(
    const uint8_t & _arg)
  {
    this->cmd = _arg;
    return *this;
  }
  Type & set__position(
    const float & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__velocity(
    const float & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__torque(
    const float & _arg)
  {
    this->torque = _arg;
    return *this;
  }
  Type & set__temp(
    const float & _arg)
  {
    this->temp = _arg;
    return *this;
  }
  Type & set__flag(
    const bool & _arg)
  {
    this->flag = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    j60interfaces::msg::StateJ60_<ContainerAllocator> *;
  using ConstRawPtr =
    const j60interfaces::msg::StateJ60_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<j60interfaces::msg::StateJ60_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<j60interfaces::msg::StateJ60_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      j60interfaces::msg::StateJ60_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<j60interfaces::msg::StateJ60_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      j60interfaces::msg::StateJ60_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<j60interfaces::msg::StateJ60_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<j60interfaces::msg::StateJ60_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<j60interfaces::msg::StateJ60_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__j60interfaces__msg__StateJ60
    std::shared_ptr<j60interfaces::msg::StateJ60_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__j60interfaces__msg__StateJ60
    std::shared_ptr<j60interfaces::msg::StateJ60_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const StateJ60_ & other) const
  {
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->cmd != other.cmd) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->torque != other.torque) {
      return false;
    }
    if (this->temp != other.temp) {
      return false;
    }
    if (this->flag != other.flag) {
      return false;
    }
    return true;
  }
  bool operator!=(const StateJ60_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct StateJ60_

// alias to use template instance with default allocator
using StateJ60 =
  j60interfaces::msg::StateJ60_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace j60interfaces

#endif  // J60INTERFACES__MSG__DETAIL__STATE_J60__STRUCT_HPP_
