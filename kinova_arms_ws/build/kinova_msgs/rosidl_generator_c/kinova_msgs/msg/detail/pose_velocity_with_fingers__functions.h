// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from kinova_msgs:msg/PoseVelocityWithFingers.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY_WITH_FINGERS__FUNCTIONS_H_
#define KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY_WITH_FINGERS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "kinova_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "kinova_msgs/msg/detail/pose_velocity_with_fingers__struct.h"

/// Initialize msg/PoseVelocityWithFingers message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__msg__PoseVelocityWithFingers
 * )) before or use
 * kinova_msgs__msg__PoseVelocityWithFingers__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocityWithFingers__init(kinova_msgs__msg__PoseVelocityWithFingers * msg);

/// Finalize msg/PoseVelocityWithFingers message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__msg__PoseVelocityWithFingers__fini(kinova_msgs__msg__PoseVelocityWithFingers * msg);

/// Create msg/PoseVelocityWithFingers message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__msg__PoseVelocityWithFingers__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__msg__PoseVelocityWithFingers *
kinova_msgs__msg__PoseVelocityWithFingers__create();

/// Destroy msg/PoseVelocityWithFingers message.
/**
 * It calls
 * kinova_msgs__msg__PoseVelocityWithFingers__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__msg__PoseVelocityWithFingers__destroy(kinova_msgs__msg__PoseVelocityWithFingers * msg);

/// Check for msg/PoseVelocityWithFingers message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocityWithFingers__are_equal(const kinova_msgs__msg__PoseVelocityWithFingers * lhs, const kinova_msgs__msg__PoseVelocityWithFingers * rhs);

/// Copy a msg/PoseVelocityWithFingers message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocityWithFingers__copy(
  const kinova_msgs__msg__PoseVelocityWithFingers * input,
  kinova_msgs__msg__PoseVelocityWithFingers * output);

/// Initialize array of msg/PoseVelocityWithFingers messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__msg__PoseVelocityWithFingers__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocityWithFingers__Sequence__init(kinova_msgs__msg__PoseVelocityWithFingers__Sequence * array, size_t size);

/// Finalize array of msg/PoseVelocityWithFingers messages.
/**
 * It calls
 * kinova_msgs__msg__PoseVelocityWithFingers__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__msg__PoseVelocityWithFingers__Sequence__fini(kinova_msgs__msg__PoseVelocityWithFingers__Sequence * array);

/// Create array of msg/PoseVelocityWithFingers messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__msg__PoseVelocityWithFingers__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__msg__PoseVelocityWithFingers__Sequence *
kinova_msgs__msg__PoseVelocityWithFingers__Sequence__create(size_t size);

/// Destroy array of msg/PoseVelocityWithFingers messages.
/**
 * It calls
 * kinova_msgs__msg__PoseVelocityWithFingers__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__msg__PoseVelocityWithFingers__Sequence__destroy(kinova_msgs__msg__PoseVelocityWithFingers__Sequence * array);

/// Check for msg/PoseVelocityWithFingers message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocityWithFingers__Sequence__are_equal(const kinova_msgs__msg__PoseVelocityWithFingers__Sequence * lhs, const kinova_msgs__msg__PoseVelocityWithFingers__Sequence * rhs);

/// Copy an array of msg/PoseVelocityWithFingers messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocityWithFingers__Sequence__copy(
  const kinova_msgs__msg__PoseVelocityWithFingers__Sequence * input,
  kinova_msgs__msg__PoseVelocityWithFingers__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY_WITH_FINGERS__FUNCTIONS_H_
