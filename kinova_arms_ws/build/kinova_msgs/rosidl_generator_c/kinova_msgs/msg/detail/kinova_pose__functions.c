// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kinova_msgs:msg/KinovaPose.idl
// generated code does not contain a copyright notice
#include "kinova_msgs/msg/detail/kinova_pose__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
kinova_msgs__msg__KinovaPose__init(kinova_msgs__msg__KinovaPose * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // z
  // theta_x
  // theta_y
  // theta_z
  return true;
}

void
kinova_msgs__msg__KinovaPose__fini(kinova_msgs__msg__KinovaPose * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // z
  // theta_x
  // theta_y
  // theta_z
}

bool
kinova_msgs__msg__KinovaPose__are_equal(const kinova_msgs__msg__KinovaPose * lhs, const kinova_msgs__msg__KinovaPose * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // theta_x
  if (lhs->theta_x != rhs->theta_x) {
    return false;
  }
  // theta_y
  if (lhs->theta_y != rhs->theta_y) {
    return false;
  }
  // theta_z
  if (lhs->theta_z != rhs->theta_z) {
    return false;
  }
  return true;
}

bool
kinova_msgs__msg__KinovaPose__copy(
  const kinova_msgs__msg__KinovaPose * input,
  kinova_msgs__msg__KinovaPose * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // z
  output->z = input->z;
  // theta_x
  output->theta_x = input->theta_x;
  // theta_y
  output->theta_y = input->theta_y;
  // theta_z
  output->theta_z = input->theta_z;
  return true;
}

kinova_msgs__msg__KinovaPose *
kinova_msgs__msg__KinovaPose__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__msg__KinovaPose * msg = (kinova_msgs__msg__KinovaPose *)allocator.allocate(sizeof(kinova_msgs__msg__KinovaPose), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__msg__KinovaPose));
  bool success = kinova_msgs__msg__KinovaPose__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__msg__KinovaPose__destroy(kinova_msgs__msg__KinovaPose * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__msg__KinovaPose__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__msg__KinovaPose__Sequence__init(kinova_msgs__msg__KinovaPose__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__msg__KinovaPose * data = NULL;

  if (size) {
    data = (kinova_msgs__msg__KinovaPose *)allocator.zero_allocate(size, sizeof(kinova_msgs__msg__KinovaPose), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__msg__KinovaPose__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__msg__KinovaPose__fini(&data[i - 1]);
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
kinova_msgs__msg__KinovaPose__Sequence__fini(kinova_msgs__msg__KinovaPose__Sequence * array)
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
      kinova_msgs__msg__KinovaPose__fini(&array->data[i]);
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

kinova_msgs__msg__KinovaPose__Sequence *
kinova_msgs__msg__KinovaPose__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__msg__KinovaPose__Sequence * array = (kinova_msgs__msg__KinovaPose__Sequence *)allocator.allocate(sizeof(kinova_msgs__msg__KinovaPose__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__msg__KinovaPose__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__msg__KinovaPose__Sequence__destroy(kinova_msgs__msg__KinovaPose__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__msg__KinovaPose__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__msg__KinovaPose__Sequence__are_equal(const kinova_msgs__msg__KinovaPose__Sequence * lhs, const kinova_msgs__msg__KinovaPose__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__msg__KinovaPose__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__msg__KinovaPose__Sequence__copy(
  const kinova_msgs__msg__KinovaPose__Sequence * input,
  kinova_msgs__msg__KinovaPose__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__msg__KinovaPose);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__msg__KinovaPose * data =
      (kinova_msgs__msg__KinovaPose *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__msg__KinovaPose__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__msg__KinovaPose__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__msg__KinovaPose__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
