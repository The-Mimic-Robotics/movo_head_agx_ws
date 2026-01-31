// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from kinova_msgs:action/ArmJointAngles.idl
// generated code does not contain a copyright notice
#include "kinova_msgs/action/detail/arm_joint_angles__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `angles`
#include "kinova_msgs/msg/detail/joint_angles__functions.h"

bool
kinova_msgs__action__ArmJointAngles_Goal__init(kinova_msgs__action__ArmJointAngles_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // angles
  if (!kinova_msgs__msg__JointAngles__init(&msg->angles)) {
    kinova_msgs__action__ArmJointAngles_Goal__fini(msg);
    return false;
  }
  return true;
}

void
kinova_msgs__action__ArmJointAngles_Goal__fini(kinova_msgs__action__ArmJointAngles_Goal * msg)
{
  if (!msg) {
    return;
  }
  // angles
  kinova_msgs__msg__JointAngles__fini(&msg->angles);
}

bool
kinova_msgs__action__ArmJointAngles_Goal__are_equal(const kinova_msgs__action__ArmJointAngles_Goal * lhs, const kinova_msgs__action__ArmJointAngles_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // angles
  if (!kinova_msgs__msg__JointAngles__are_equal(
      &(lhs->angles), &(rhs->angles)))
  {
    return false;
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_Goal__copy(
  const kinova_msgs__action__ArmJointAngles_Goal * input,
  kinova_msgs__action__ArmJointAngles_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // angles
  if (!kinova_msgs__msg__JointAngles__copy(
      &(input->angles), &(output->angles)))
  {
    return false;
  }
  return true;
}

kinova_msgs__action__ArmJointAngles_Goal *
kinova_msgs__action__ArmJointAngles_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_Goal * msg = (kinova_msgs__action__ArmJointAngles_Goal *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__action__ArmJointAngles_Goal));
  bool success = kinova_msgs__action__ArmJointAngles_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__action__ArmJointAngles_Goal__destroy(kinova_msgs__action__ArmJointAngles_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__action__ArmJointAngles_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__action__ArmJointAngles_Goal__Sequence__init(kinova_msgs__action__ArmJointAngles_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_Goal * data = NULL;

  if (size) {
    data = (kinova_msgs__action__ArmJointAngles_Goal *)allocator.zero_allocate(size, sizeof(kinova_msgs__action__ArmJointAngles_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__action__ArmJointAngles_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__action__ArmJointAngles_Goal__fini(&data[i - 1]);
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
kinova_msgs__action__ArmJointAngles_Goal__Sequence__fini(kinova_msgs__action__ArmJointAngles_Goal__Sequence * array)
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
      kinova_msgs__action__ArmJointAngles_Goal__fini(&array->data[i]);
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

kinova_msgs__action__ArmJointAngles_Goal__Sequence *
kinova_msgs__action__ArmJointAngles_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_Goal__Sequence * array = (kinova_msgs__action__ArmJointAngles_Goal__Sequence *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__action__ArmJointAngles_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__action__ArmJointAngles_Goal__Sequence__destroy(kinova_msgs__action__ArmJointAngles_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__action__ArmJointAngles_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__action__ArmJointAngles_Goal__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_Goal__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_Goal__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_Goal__Sequence * input,
  kinova_msgs__action__ArmJointAngles_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__action__ArmJointAngles_Goal);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__action__ArmJointAngles_Goal * data =
      (kinova_msgs__action__ArmJointAngles_Goal *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__action__ArmJointAngles_Goal__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__action__ArmJointAngles_Goal__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `angles`
// already included above
// #include "kinova_msgs/msg/detail/joint_angles__functions.h"

bool
kinova_msgs__action__ArmJointAngles_Result__init(kinova_msgs__action__ArmJointAngles_Result * msg)
{
  if (!msg) {
    return false;
  }
  // angles
  if (!kinova_msgs__msg__JointAngles__init(&msg->angles)) {
    kinova_msgs__action__ArmJointAngles_Result__fini(msg);
    return false;
  }
  return true;
}

void
kinova_msgs__action__ArmJointAngles_Result__fini(kinova_msgs__action__ArmJointAngles_Result * msg)
{
  if (!msg) {
    return;
  }
  // angles
  kinova_msgs__msg__JointAngles__fini(&msg->angles);
}

bool
kinova_msgs__action__ArmJointAngles_Result__are_equal(const kinova_msgs__action__ArmJointAngles_Result * lhs, const kinova_msgs__action__ArmJointAngles_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // angles
  if (!kinova_msgs__msg__JointAngles__are_equal(
      &(lhs->angles), &(rhs->angles)))
  {
    return false;
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_Result__copy(
  const kinova_msgs__action__ArmJointAngles_Result * input,
  kinova_msgs__action__ArmJointAngles_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // angles
  if (!kinova_msgs__msg__JointAngles__copy(
      &(input->angles), &(output->angles)))
  {
    return false;
  }
  return true;
}

kinova_msgs__action__ArmJointAngles_Result *
kinova_msgs__action__ArmJointAngles_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_Result * msg = (kinova_msgs__action__ArmJointAngles_Result *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__action__ArmJointAngles_Result));
  bool success = kinova_msgs__action__ArmJointAngles_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__action__ArmJointAngles_Result__destroy(kinova_msgs__action__ArmJointAngles_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__action__ArmJointAngles_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__action__ArmJointAngles_Result__Sequence__init(kinova_msgs__action__ArmJointAngles_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_Result * data = NULL;

  if (size) {
    data = (kinova_msgs__action__ArmJointAngles_Result *)allocator.zero_allocate(size, sizeof(kinova_msgs__action__ArmJointAngles_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__action__ArmJointAngles_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__action__ArmJointAngles_Result__fini(&data[i - 1]);
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
kinova_msgs__action__ArmJointAngles_Result__Sequence__fini(kinova_msgs__action__ArmJointAngles_Result__Sequence * array)
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
      kinova_msgs__action__ArmJointAngles_Result__fini(&array->data[i]);
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

kinova_msgs__action__ArmJointAngles_Result__Sequence *
kinova_msgs__action__ArmJointAngles_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_Result__Sequence * array = (kinova_msgs__action__ArmJointAngles_Result__Sequence *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__action__ArmJointAngles_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__action__ArmJointAngles_Result__Sequence__destroy(kinova_msgs__action__ArmJointAngles_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__action__ArmJointAngles_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__action__ArmJointAngles_Result__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_Result__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_Result__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_Result__Sequence * input,
  kinova_msgs__action__ArmJointAngles_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__action__ArmJointAngles_Result);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__action__ArmJointAngles_Result * data =
      (kinova_msgs__action__ArmJointAngles_Result *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__action__ArmJointAngles_Result__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__action__ArmJointAngles_Result__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `angles`
// already included above
// #include "kinova_msgs/msg/detail/joint_angles__functions.h"

bool
kinova_msgs__action__ArmJointAngles_Feedback__init(kinova_msgs__action__ArmJointAngles_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // angles
  if (!kinova_msgs__msg__JointAngles__init(&msg->angles)) {
    kinova_msgs__action__ArmJointAngles_Feedback__fini(msg);
    return false;
  }
  return true;
}

void
kinova_msgs__action__ArmJointAngles_Feedback__fini(kinova_msgs__action__ArmJointAngles_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // angles
  kinova_msgs__msg__JointAngles__fini(&msg->angles);
}

bool
kinova_msgs__action__ArmJointAngles_Feedback__are_equal(const kinova_msgs__action__ArmJointAngles_Feedback * lhs, const kinova_msgs__action__ArmJointAngles_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // angles
  if (!kinova_msgs__msg__JointAngles__are_equal(
      &(lhs->angles), &(rhs->angles)))
  {
    return false;
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_Feedback__copy(
  const kinova_msgs__action__ArmJointAngles_Feedback * input,
  kinova_msgs__action__ArmJointAngles_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // angles
  if (!kinova_msgs__msg__JointAngles__copy(
      &(input->angles), &(output->angles)))
  {
    return false;
  }
  return true;
}

kinova_msgs__action__ArmJointAngles_Feedback *
kinova_msgs__action__ArmJointAngles_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_Feedback * msg = (kinova_msgs__action__ArmJointAngles_Feedback *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__action__ArmJointAngles_Feedback));
  bool success = kinova_msgs__action__ArmJointAngles_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__action__ArmJointAngles_Feedback__destroy(kinova_msgs__action__ArmJointAngles_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__action__ArmJointAngles_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__init(kinova_msgs__action__ArmJointAngles_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_Feedback * data = NULL;

  if (size) {
    data = (kinova_msgs__action__ArmJointAngles_Feedback *)allocator.zero_allocate(size, sizeof(kinova_msgs__action__ArmJointAngles_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__action__ArmJointAngles_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__action__ArmJointAngles_Feedback__fini(&data[i - 1]);
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
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__fini(kinova_msgs__action__ArmJointAngles_Feedback__Sequence * array)
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
      kinova_msgs__action__ArmJointAngles_Feedback__fini(&array->data[i]);
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

kinova_msgs__action__ArmJointAngles_Feedback__Sequence *
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_Feedback__Sequence * array = (kinova_msgs__action__ArmJointAngles_Feedback__Sequence *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__action__ArmJointAngles_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__destroy(kinova_msgs__action__ArmJointAngles_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__action__ArmJointAngles_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_Feedback__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_Feedback__Sequence * input,
  kinova_msgs__action__ArmJointAngles_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__action__ArmJointAngles_Feedback);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__action__ArmJointAngles_Feedback * data =
      (kinova_msgs__action__ArmJointAngles_Feedback *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__action__ArmJointAngles_Feedback__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__action__ArmJointAngles_Feedback__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__init(kinova_msgs__action__ArmJointAngles_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!kinova_msgs__action__ArmJointAngles_Goal__init(&msg->goal)) {
    kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini(kinova_msgs__action__ArmJointAngles_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  kinova_msgs__action__ArmJointAngles_Goal__fini(&msg->goal);
}

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__are_equal(const kinova_msgs__action__ArmJointAngles_SendGoal_Request * lhs, const kinova_msgs__action__ArmJointAngles_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!kinova_msgs__action__ArmJointAngles_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__copy(
  const kinova_msgs__action__ArmJointAngles_SendGoal_Request * input,
  kinova_msgs__action__ArmJointAngles_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!kinova_msgs__action__ArmJointAngles_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

kinova_msgs__action__ArmJointAngles_SendGoal_Request *
kinova_msgs__action__ArmJointAngles_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_SendGoal_Request * msg = (kinova_msgs__action__ArmJointAngles_SendGoal_Request *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Request));
  bool success = kinova_msgs__action__ArmJointAngles_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__action__ArmJointAngles_SendGoal_Request__destroy(kinova_msgs__action__ArmJointAngles_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__init(kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_SendGoal_Request * data = NULL;

  if (size) {
    data = (kinova_msgs__action__ArmJointAngles_SendGoal_Request *)allocator.zero_allocate(size, sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__action__ArmJointAngles_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini(&data[i - 1]);
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
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__fini(kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * array)
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
      kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini(&array->data[i]);
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

kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence *
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * array = (kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__destroy(kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * input,
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__action__ArmJointAngles_SendGoal_Request * data =
      (kinova_msgs__action__ArmJointAngles_SendGoal_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__action__ArmJointAngles_SendGoal_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__init(kinova_msgs__action__ArmJointAngles_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini(kinova_msgs__action__ArmJointAngles_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__are_equal(const kinova_msgs__action__ArmJointAngles_SendGoal_Response * lhs, const kinova_msgs__action__ArmJointAngles_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__copy(
  const kinova_msgs__action__ArmJointAngles_SendGoal_Response * input,
  kinova_msgs__action__ArmJointAngles_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

kinova_msgs__action__ArmJointAngles_SendGoal_Response *
kinova_msgs__action__ArmJointAngles_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_SendGoal_Response * msg = (kinova_msgs__action__ArmJointAngles_SendGoal_Response *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Response));
  bool success = kinova_msgs__action__ArmJointAngles_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__action__ArmJointAngles_SendGoal_Response__destroy(kinova_msgs__action__ArmJointAngles_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__init(kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_SendGoal_Response * data = NULL;

  if (size) {
    data = (kinova_msgs__action__ArmJointAngles_SendGoal_Response *)allocator.zero_allocate(size, sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__action__ArmJointAngles_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini(&data[i - 1]);
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
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__fini(kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * array)
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
      kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini(&array->data[i]);
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

kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence *
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * array = (kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__destroy(kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * input,
  kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__action__ArmJointAngles_SendGoal_Response * data =
      (kinova_msgs__action__ArmJointAngles_SendGoal_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__action__ArmJointAngles_SendGoal_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__init(kinova_msgs__action__ArmJointAngles_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    kinova_msgs__action__ArmJointAngles_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
kinova_msgs__action__ArmJointAngles_GetResult_Request__fini(kinova_msgs__action__ArmJointAngles_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__are_equal(const kinova_msgs__action__ArmJointAngles_GetResult_Request * lhs, const kinova_msgs__action__ArmJointAngles_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__copy(
  const kinova_msgs__action__ArmJointAngles_GetResult_Request * input,
  kinova_msgs__action__ArmJointAngles_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

kinova_msgs__action__ArmJointAngles_GetResult_Request *
kinova_msgs__action__ArmJointAngles_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_GetResult_Request * msg = (kinova_msgs__action__ArmJointAngles_GetResult_Request *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Request));
  bool success = kinova_msgs__action__ArmJointAngles_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__action__ArmJointAngles_GetResult_Request__destroy(kinova_msgs__action__ArmJointAngles_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__action__ArmJointAngles_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__init(kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_GetResult_Request * data = NULL;

  if (size) {
    data = (kinova_msgs__action__ArmJointAngles_GetResult_Request *)allocator.zero_allocate(size, sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__action__ArmJointAngles_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__action__ArmJointAngles_GetResult_Request__fini(&data[i - 1]);
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
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__fini(kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * array)
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
      kinova_msgs__action__ArmJointAngles_GetResult_Request__fini(&array->data[i]);
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

kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence *
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * array = (kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__destroy(kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * input,
  kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__action__ArmJointAngles_GetResult_Request * data =
      (kinova_msgs__action__ArmJointAngles_GetResult_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__action__ArmJointAngles_GetResult_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__action__ArmJointAngles_GetResult_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"

bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__init(kinova_msgs__action__ArmJointAngles_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!kinova_msgs__action__ArmJointAngles_Result__init(&msg->result)) {
    kinova_msgs__action__ArmJointAngles_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
kinova_msgs__action__ArmJointAngles_GetResult_Response__fini(kinova_msgs__action__ArmJointAngles_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  kinova_msgs__action__ArmJointAngles_Result__fini(&msg->result);
}

bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__are_equal(const kinova_msgs__action__ArmJointAngles_GetResult_Response * lhs, const kinova_msgs__action__ArmJointAngles_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!kinova_msgs__action__ArmJointAngles_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__copy(
  const kinova_msgs__action__ArmJointAngles_GetResult_Response * input,
  kinova_msgs__action__ArmJointAngles_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!kinova_msgs__action__ArmJointAngles_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

kinova_msgs__action__ArmJointAngles_GetResult_Response *
kinova_msgs__action__ArmJointAngles_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_GetResult_Response * msg = (kinova_msgs__action__ArmJointAngles_GetResult_Response *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Response));
  bool success = kinova_msgs__action__ArmJointAngles_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__action__ArmJointAngles_GetResult_Response__destroy(kinova_msgs__action__ArmJointAngles_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__action__ArmJointAngles_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__init(kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_GetResult_Response * data = NULL;

  if (size) {
    data = (kinova_msgs__action__ArmJointAngles_GetResult_Response *)allocator.zero_allocate(size, sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__action__ArmJointAngles_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__action__ArmJointAngles_GetResult_Response__fini(&data[i - 1]);
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
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__fini(kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * array)
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
      kinova_msgs__action__ArmJointAngles_GetResult_Response__fini(&array->data[i]);
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

kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence *
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * array = (kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__destroy(kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * input,
  kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__action__ArmJointAngles_GetResult_Response * data =
      (kinova_msgs__action__ArmJointAngles_GetResult_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__action__ArmJointAngles_GetResult_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__action__ArmJointAngles_GetResult_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"

bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__init(kinova_msgs__action__ArmJointAngles_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!kinova_msgs__action__ArmJointAngles_Feedback__init(&msg->feedback)) {
    kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini(kinova_msgs__action__ArmJointAngles_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  kinova_msgs__action__ArmJointAngles_Feedback__fini(&msg->feedback);
}

bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__are_equal(const kinova_msgs__action__ArmJointAngles_FeedbackMessage * lhs, const kinova_msgs__action__ArmJointAngles_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!kinova_msgs__action__ArmJointAngles_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__copy(
  const kinova_msgs__action__ArmJointAngles_FeedbackMessage * input,
  kinova_msgs__action__ArmJointAngles_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!kinova_msgs__action__ArmJointAngles_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

kinova_msgs__action__ArmJointAngles_FeedbackMessage *
kinova_msgs__action__ArmJointAngles_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_FeedbackMessage * msg = (kinova_msgs__action__ArmJointAngles_FeedbackMessage *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(kinova_msgs__action__ArmJointAngles_FeedbackMessage));
  bool success = kinova_msgs__action__ArmJointAngles_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
kinova_msgs__action__ArmJointAngles_FeedbackMessage__destroy(kinova_msgs__action__ArmJointAngles_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__init(kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_FeedbackMessage * data = NULL;

  if (size) {
    data = (kinova_msgs__action__ArmJointAngles_FeedbackMessage *)allocator.zero_allocate(size, sizeof(kinova_msgs__action__ArmJointAngles_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = kinova_msgs__action__ArmJointAngles_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini(&data[i - 1]);
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
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__fini(kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * array)
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
      kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini(&array->data[i]);
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

kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence *
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * array = (kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence *)allocator.allocate(sizeof(kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__destroy(kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * input,
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(kinova_msgs__action__ArmJointAngles_FeedbackMessage);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    kinova_msgs__action__ArmJointAngles_FeedbackMessage * data =
      (kinova_msgs__action__ArmJointAngles_FeedbackMessage *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!kinova_msgs__action__ArmJointAngles_FeedbackMessage__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!kinova_msgs__action__ArmJointAngles_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
