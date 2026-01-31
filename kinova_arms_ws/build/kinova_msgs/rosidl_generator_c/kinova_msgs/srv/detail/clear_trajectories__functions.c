// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kinova_msgs:srv/ClearTrajectories.idl
// generated code does not contain a copyright notice
#include "kinova_msgs/srv/detail/clear_trajectories__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
kinova_msgs__srv__ClearTrajectories_Request__init(kinova_msgs__srv__ClearTrajectories_Request * msg)
{
  if (!msg) {
    return false;
  }
  // structure_needs_at_least_one_member
  return true;
}

void
kinova_msgs__srv__ClearTrajectories_Request__fini(kinova_msgs__srv__ClearTrajectories_Request * msg)
{
  if (!msg) {
    return;
  }
  // structure_needs_at_least_one_member
}

bool
kinova_msgs__srv__ClearTrajectories_Request__are_equal(const kinova_msgs__srv__ClearTrajectories_Request * lhs, const kinova_msgs__srv__ClearTrajectories_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // structure_needs_at_least_one_member
  if (lhs->structure_needs_at_least_one_member != rhs->structure_needs_at_least_one_member) {
    return false;
  }
  return true;
}

bool
kinova_msgs__srv__ClearTrajectories_Request__copy(
  const kinova_msgs__srv__ClearTrajectories_Request * input,
  kinova_msgs__srv__ClearTrajectories_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // structure_needs_at_least_one_member
  output->structure_needs_at_least_one_member = input->structure_needs_at_least_one_member;
  return true;
}

kinova_msgs__srv__ClearTrajectories_Request *
kinova_msgs__srv__ClearTrajectories_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__srv__ClearTrajectories_Request * msg = (kinova_msgs__srv__ClearTrajectories_Request *)allocator.allocate(sizeof(kinova_msgs__srv__ClearTrajectories_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__srv__ClearTrajectories_Request));
  bool success = kinova_msgs__srv__ClearTrajectories_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__srv__ClearTrajectories_Request__destroy(kinova_msgs__srv__ClearTrajectories_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__srv__ClearTrajectories_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__srv__ClearTrajectories_Request__Sequence__init(kinova_msgs__srv__ClearTrajectories_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__srv__ClearTrajectories_Request * data = NULL;

  if (size) {
    data = (kinova_msgs__srv__ClearTrajectories_Request *)allocator.zero_allocate(size, sizeof(kinova_msgs__srv__ClearTrajectories_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__srv__ClearTrajectories_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__srv__ClearTrajectories_Request__fini(&data[i - 1]);
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
kinova_msgs__srv__ClearTrajectories_Request__Sequence__fini(kinova_msgs__srv__ClearTrajectories_Request__Sequence * array)
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
      kinova_msgs__srv__ClearTrajectories_Request__fini(&array->data[i]);
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

kinova_msgs__srv__ClearTrajectories_Request__Sequence *
kinova_msgs__srv__ClearTrajectories_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__srv__ClearTrajectories_Request__Sequence * array = (kinova_msgs__srv__ClearTrajectories_Request__Sequence *)allocator.allocate(sizeof(kinova_msgs__srv__ClearTrajectories_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__srv__ClearTrajectories_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__srv__ClearTrajectories_Request__Sequence__destroy(kinova_msgs__srv__ClearTrajectories_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__srv__ClearTrajectories_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__srv__ClearTrajectories_Request__Sequence__are_equal(const kinova_msgs__srv__ClearTrajectories_Request__Sequence * lhs, const kinova_msgs__srv__ClearTrajectories_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__srv__ClearTrajectories_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__srv__ClearTrajectories_Request__Sequence__copy(
  const kinova_msgs__srv__ClearTrajectories_Request__Sequence * input,
  kinova_msgs__srv__ClearTrajectories_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__srv__ClearTrajectories_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__srv__ClearTrajectories_Request * data =
      (kinova_msgs__srv__ClearTrajectories_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__srv__ClearTrajectories_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__srv__ClearTrajectories_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__srv__ClearTrajectories_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
#include "rosidl_runtime_c/string_functions.h"

bool
kinova_msgs__srv__ClearTrajectories_Response__init(kinova_msgs__srv__ClearTrajectories_Response * msg)
{
  if (!msg) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__init(&msg->result)) {
    kinova_msgs__srv__ClearTrajectories_Response__fini(msg);
    return false;
  }
  return true;
}

void
kinova_msgs__srv__ClearTrajectories_Response__fini(kinova_msgs__srv__ClearTrajectories_Response * msg)
{
  if (!msg) {
    return;
  }
  // result
  rosidl_runtime_c__String__fini(&msg->result);
}

bool
kinova_msgs__srv__ClearTrajectories_Response__are_equal(const kinova_msgs__srv__ClearTrajectories_Response * lhs, const kinova_msgs__srv__ClearTrajectories_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
kinova_msgs__srv__ClearTrajectories_Response__copy(
  const kinova_msgs__srv__ClearTrajectories_Response * input,
  kinova_msgs__srv__ClearTrajectories_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // result
  if (!rosidl_runtime_c__String__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

kinova_msgs__srv__ClearTrajectories_Response *
kinova_msgs__srv__ClearTrajectories_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__srv__ClearTrajectories_Response * msg = (kinova_msgs__srv__ClearTrajectories_Response *)allocator.allocate(sizeof(kinova_msgs__srv__ClearTrajectories_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__srv__ClearTrajectories_Response));
  bool success = kinova_msgs__srv__ClearTrajectories_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__srv__ClearTrajectories_Response__destroy(kinova_msgs__srv__ClearTrajectories_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__srv__ClearTrajectories_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__srv__ClearTrajectories_Response__Sequence__init(kinova_msgs__srv__ClearTrajectories_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__srv__ClearTrajectories_Response * data = NULL;

  if (size) {
    data = (kinova_msgs__srv__ClearTrajectories_Response *)allocator.zero_allocate(size, sizeof(kinova_msgs__srv__ClearTrajectories_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__srv__ClearTrajectories_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__srv__ClearTrajectories_Response__fini(&data[i - 1]);
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
kinova_msgs__srv__ClearTrajectories_Response__Sequence__fini(kinova_msgs__srv__ClearTrajectories_Response__Sequence * array)
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
      kinova_msgs__srv__ClearTrajectories_Response__fini(&array->data[i]);
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

kinova_msgs__srv__ClearTrajectories_Response__Sequence *
kinova_msgs__srv__ClearTrajectories_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__srv__ClearTrajectories_Response__Sequence * array = (kinova_msgs__srv__ClearTrajectories_Response__Sequence *)allocator.allocate(sizeof(kinova_msgs__srv__ClearTrajectories_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__srv__ClearTrajectories_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__srv__ClearTrajectories_Response__Sequence__destroy(kinova_msgs__srv__ClearTrajectories_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__srv__ClearTrajectories_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__srv__ClearTrajectories_Response__Sequence__are_equal(const kinova_msgs__srv__ClearTrajectories_Response__Sequence * lhs, const kinova_msgs__srv__ClearTrajectories_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__srv__ClearTrajectories_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__srv__ClearTrajectories_Response__Sequence__copy(
  const kinova_msgs__srv__ClearTrajectories_Response__Sequence * input,
  kinova_msgs__srv__ClearTrajectories_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__srv__ClearTrajectories_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__srv__ClearTrajectories_Response * data =
      (kinova_msgs__srv__ClearTrajectories_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__srv__ClearTrajectories_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__srv__ClearTrajectories_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__srv__ClearTrajectories_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
