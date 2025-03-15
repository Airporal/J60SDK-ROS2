// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from j60interfaces:msg/MoveJ60.idl
// generated code does not contain a copyright notice
#include "j60interfaces/msg/detail/move_j60__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
j60interfaces__msg__MoveJ60__init(j60interfaces__msg__MoveJ60 * msg)
{
  if (!msg) {
    return false;
  }
  // position
  // velocity
  // kp
  // kd
  // torque
  return true;
}

void
j60interfaces__msg__MoveJ60__fini(j60interfaces__msg__MoveJ60 * msg)
{
  if (!msg) {
    return;
  }
  // position
  // velocity
  // kp
  // kd
  // torque
}

bool
j60interfaces__msg__MoveJ60__are_equal(const j60interfaces__msg__MoveJ60 * lhs, const j60interfaces__msg__MoveJ60 * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // position
  if (lhs->position != rhs->position) {
    return false;
  }
  // velocity
  if (lhs->velocity != rhs->velocity) {
    return false;
  }
  // kp
  if (lhs->kp != rhs->kp) {
    return false;
  }
  // kd
  if (lhs->kd != rhs->kd) {
    return false;
  }
  // torque
  if (lhs->torque != rhs->torque) {
    return false;
  }
  return true;
}

bool
j60interfaces__msg__MoveJ60__copy(
  const j60interfaces__msg__MoveJ60 * input,
  j60interfaces__msg__MoveJ60 * output)
{
  if (!input || !output) {
    return false;
  }
  // position
  output->position = input->position;
  // velocity
  output->velocity = input->velocity;
  // kp
  output->kp = input->kp;
  // kd
  output->kd = input->kd;
  // torque
  output->torque = input->torque;
  return true;
}

j60interfaces__msg__MoveJ60 *
j60interfaces__msg__MoveJ60__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  j60interfaces__msg__MoveJ60 * msg = (j60interfaces__msg__MoveJ60 *)allocator.allocate(sizeof(j60interfaces__msg__MoveJ60), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(j60interfaces__msg__MoveJ60));
  bool success = j60interfaces__msg__MoveJ60__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
j60interfaces__msg__MoveJ60__destroy(j60interfaces__msg__MoveJ60 * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    j60interfaces__msg__MoveJ60__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
j60interfaces__msg__MoveJ60__Sequence__init(j60interfaces__msg__MoveJ60__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  j60interfaces__msg__MoveJ60 * data = NULL;

  if (size) {
    data = (j60interfaces__msg__MoveJ60 *)allocator.zero_allocate(size, sizeof(j60interfaces__msg__MoveJ60), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = j60interfaces__msg__MoveJ60__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        j60interfaces__msg__MoveJ60__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
j60interfaces__msg__MoveJ60__Sequence__fini(j60interfaces__msg__MoveJ60__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      j60interfaces__msg__MoveJ60__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

j60interfaces__msg__MoveJ60__Sequence *
j60interfaces__msg__MoveJ60__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  j60interfaces__msg__MoveJ60__Sequence * array = (j60interfaces__msg__MoveJ60__Sequence *)allocator.allocate(sizeof(j60interfaces__msg__MoveJ60__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = j60interfaces__msg__MoveJ60__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
j60interfaces__msg__MoveJ60__Sequence__destroy(j60interfaces__msg__MoveJ60__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    j60interfaces__msg__MoveJ60__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
j60interfaces__msg__MoveJ60__Sequence__are_equal(const j60interfaces__msg__MoveJ60__Sequence * lhs, const j60interfaces__msg__MoveJ60__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!j60interfaces__msg__MoveJ60__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
j60interfaces__msg__MoveJ60__Sequence__copy(
  const j60interfaces__msg__MoveJ60__Sequence * input,
  j60interfaces__msg__MoveJ60__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(j60interfaces__msg__MoveJ60);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    j60interfaces__msg__MoveJ60 * data =
      (j60interfaces__msg__MoveJ60 *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!j60interfaces__msg__MoveJ60__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          j60interfaces__msg__MoveJ60__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!j60interfaces__msg__MoveJ60__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
