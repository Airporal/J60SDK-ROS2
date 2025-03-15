// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from j60interfaces:msg/MoveJ60.idl
// generated code does not contain a copyright notice

#ifndef J60INTERFACES__MSG__DETAIL__MOVE_J60__STRUCT_H_
#define J60INTERFACES__MSG__DETAIL__MOVE_J60__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MoveJ60 in the package j60interfaces.
typedef struct j60interfaces__msg__MoveJ60
{
  float position;
  float velocity;
  float kp;
  float kd;
  float torque;
} j60interfaces__msg__MoveJ60;

// Struct for a sequence of j60interfaces__msg__MoveJ60.
typedef struct j60interfaces__msg__MoveJ60__Sequence
{
  j60interfaces__msg__MoveJ60 * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} j60interfaces__msg__MoveJ60__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // J60INTERFACES__MSG__DETAIL__MOVE_J60__STRUCT_H_
