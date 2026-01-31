// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kinova_msgs:msg/PoseVelocityWithFingerVelocity.idl
// generated code does not contain a copyright notice
#include "kinova_msgs/msg/detail/pose_velocity_with_finger_velocity__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
kinova_msgs__msg__PoseVelocityWithFingerVelocity__init(kinova_msgs__msg__PoseVelocityWithFingerVelocity * msg)
{
  if (!msg) {
    return false;
  }
  // twist_linear_x
  // twist_linear_y
  // twist_linear_z
  // twist_angular_x
  // twist_angular_y
  // twist_angular_z
  // finger1
  // finger2
  // finger3
  return true;
}

void
kinova_msgs__msg__PoseVelocityWithFingerVelocity__fini(kinova_msgs__msg__PoseVelocityWithFingerVelocity * msg)
{
  if (!msg) {
    return;
  }
  // twist_linear_x
  // twist_linear_y
  // twist_linear_z
  // twist_angular_x
  // twist_angular_y
  // twist_angular_z
  // finger1
  // finger2
  // finger3
}

bool
kinova_msgs__msg__PoseVelocityWithFingerVelocity__are_equal(const kinova_msgs__msg__PoseVelocityWithFingerVelocity * lhs, const kinova_msgs__msg__PoseVelocityWithFingerVelocity * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // twist_linear_x
  if (lhs->twist_linear_x != rhs->twist_linear_x) {
    return false;
  }
  // twist_linear_y
  if (lhs->twist_linear_y != rhs->twist_linear_y) {
    return false;
  }
  // twist_linear_z
  if (lhs->twist_linear_z != rhs->twist_linear_z) {
    return false;
  }
  // twist_angular_x
  if (lhs->twist_angular_x != rhs->twist_angular_x) {
    return false;
  }
  // twist_angular_y
  if (lhs->twist_angular_y != rhs->twist_angular_y) {
    return false;
  }
  // twist_angular_z
  if (lhs->twist_angular_z != rhs->twist_angular_z) {
    return false;
  }
  // finger1
  if (lhs->finger1 != rhs->finger1) {
    return false;
  }
  // finger2
  if (lhs->finger2 != rhs->finger2) {
    return false;
  }
  // finger3
  if (lhs->finger3 != rhs->finger3) {
    return false;
  }
  return true;
}

bool
kinova_msgs__msg__PoseVelocityWithFingerVelocity__copy(
  const kinova_msgs__msg__PoseVelocityWithFingerVelocity * input,
  kinova_msgs__msg__PoseVelocityWithFingerVelocity * output)
{
  if (!input || !output) {
    return false;
  }
  // twist_linear_x
  output->twist_linear_x = input->twist_linear_x;
  // twist_linear_y
  output->twist_linear_y = input->twist_linear_y;
  // twist_linear_z
  output->twist_linear_z = input->twist_linear_z;
  // twist_angular_x
  output->twist_angular_x = input->twist_angular_x;
  // twist_angular_y
  output->twist_angular_y = input->twist_angular_y;
  // twist_angular_z
  output->twist_angular_z = input->twist_angular_z;
  // finger1
  output->finger1 = input->finger1;
  // finger2
  output->finger2 = input->finger2;
  // finger3
  output->finger3 = input->finger3;
  return true;
}

kinova_msgs__msg__PoseVelocityWithFingerVelocity *
kinova_msgs__msg__PoseVelocityWithFingerVelocity__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__msg__PoseVelocityWithFingerVelocity * msg = (kinova_msgs__msg__PoseVelocityWithFingerVelocity *)allocator.allocate(sizeof(kinova_msgs__msg__PoseVelocityWithFingerVelocity), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__msg__PoseVelocityWithFingerVelocity));
  bool success = kinova_msgs__msg__PoseVelocityWithFingerVelocity__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__msg__PoseVelocityWithFingerVelocity__destroy(kinova_msgs__msg__PoseVelocityWithFingerVelocity * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__msg__PoseVelocityWithFingerVelocity__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence__init(kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__msg__PoseVelocityWithFingerVelocity * data = NULL;

  if (size) {
    data = (kinova_msgs__msg__PoseVelocityWithFingerVelocity *)allocator.zero_allocate(size, sizeof(kinova_msgs__msg__PoseVelocityWithFingerVelocity), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__msg__PoseVelocityWithFingerVelocity__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__msg__PoseVelocityWithFingerVelocity__fini(&data[i - 1]);
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
kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence__fini(kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence * array)
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
      kinova_msgs__msg__PoseVelocityWithFingerVelocity__fini(&array->data[i]);
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

kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence *
kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence * array = (kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence *)allocator.allocate(sizeof(kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence__destroy(kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence__are_equal(const kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence * lhs, const kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__msg__PoseVelocityWithFingerVelocity__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence__copy(
  const kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence * input,
  kinova_msgs__msg__PoseVelocityWithFingerVelocity__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__msg__PoseVelocityWithFingerVelocity);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__msg__PoseVelocityWithFingerVelocity * data =
      (kinova_msgs__msg__PoseVelocityWithFingerVelocity *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__msg__PoseVelocityWithFingerVelocity__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__msg__PoseVelocityWithFingerVelocity__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__msg__PoseVelocityWithFingerVelocity__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
