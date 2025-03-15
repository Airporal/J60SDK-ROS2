// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from j60interfaces:msg/StateJ60.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "j60interfaces/msg/detail/state_j60__rosidl_typesupport_introspection_c.h"
#include "j60interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "j60interfaces/msg/detail/state_j60__functions.h"
#include "j60interfaces/msg/detail/state_j60__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  j60interfaces__msg__StateJ60__init(message_memory);
}

void j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_fini_function(void * message_memory)
{
  j60interfaces__msg__StateJ60__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_message_member_array[7] = {
  {
    "motor_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(j60interfaces__msg__StateJ60, motor_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "cmd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(j60interfaces__msg__StateJ60, cmd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(j60interfaces__msg__StateJ60, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "velocity",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(j60interfaces__msg__StateJ60, velocity),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "torque",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(j60interfaces__msg__StateJ60, torque),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "temp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(j60interfaces__msg__StateJ60, temp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(j60interfaces__msg__StateJ60, flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_message_members = {
  "j60interfaces__msg",  // message namespace
  "StateJ60",  // message name
  7,  // number of fields
  sizeof(j60interfaces__msg__StateJ60),
  j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_message_member_array,  // message members
  j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_init_function,  // function to initialize message memory (memory has to be allocated)
  j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_message_type_support_handle = {
  0,
  &j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_j60interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, j60interfaces, msg, StateJ60)() {
  if (!j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_message_type_support_handle.typesupport_identifier) {
    j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &j60interfaces__msg__StateJ60__rosidl_typesupport_introspection_c__StateJ60_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
