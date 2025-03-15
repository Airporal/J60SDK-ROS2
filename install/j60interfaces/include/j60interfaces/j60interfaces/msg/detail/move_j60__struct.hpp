// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from j60interfaces:msg/MoveJ60.idl
// generated code does not contain a copyright notice

#ifndef J60INTERFACES__MSG__DETAIL__MOVE_J60__STRUCT_HPP_
#define J60INTERFACES__MSG__DETAIL__MOVE_J60__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__j60interfaces__msg__MoveJ60 __attribute__((deprecated))
#else
# define DEPRECATED__j60interfaces__msg__MoveJ60 __declspec(deprecated)
#endif

namespace j60interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MoveJ60_
{
  using Type = MoveJ60_<ContainerAllocator>;

  explicit MoveJ60_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0.0f;
      this->velocity = 0.0f;
      this->kp = 0.0f;
      this->kd = 0.0f;
      this->torque = 0.0f;
    }
  }

  explicit MoveJ60_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->position = 0.0f;
      this->velocity = 0.0f;
      this->kp = 0.0f;
      this->kd = 0.0f;
      this->torque = 0.0f;
    }
  }

  // field types and members
  using _position_type =
    float;
  _position_type position;
  using _velocity_type =
    float;
  _velocity_type velocity;
  using _kp_type =
    float;
  _kp_type kp;
  using _kd_type =
    float;
  _kd_type kd;
  using _torque_type =
    float;
  _torque_type torque;

  // setters for named parameter idiom
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
  Type & set__kp(
    const float & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const float & _arg)
  {
    this->kd = _arg;
    return *this;
  }
  Type & set__torque(
    const float & _arg)
  {
    this->torque = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    j60interfaces::msg::MoveJ60_<ContainerAllocator> *;
  using ConstRawPtr =
    const j60interfaces::msg::MoveJ60_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<j60interfaces::msg::MoveJ60_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<j60interfaces::msg::MoveJ60_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      j60interfaces::msg::MoveJ60_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<j60interfaces::msg::MoveJ60_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      j60interfaces::msg::MoveJ60_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<j60interfaces::msg::MoveJ60_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<j60interfaces::msg::MoveJ60_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<j60interfaces::msg::MoveJ60_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__j60interfaces__msg__MoveJ60
    std::shared_ptr<j60interfaces::msg::MoveJ60_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__j60interfaces__msg__MoveJ60
    std::shared_ptr<j60interfaces::msg::MoveJ60_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveJ60_ & other) const
  {
    if (this->position != other.position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->kp != other.kp) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    if (this->torque != other.torque) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveJ60_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveJ60_

// alias to use template instance with default allocator
using MoveJ60 =
  j60interfaces::msg::MoveJ60_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace j60interfaces

#endif  // J60INTERFACES__MSG__DETAIL__MOVE_J60__STRUCT_HPP_
