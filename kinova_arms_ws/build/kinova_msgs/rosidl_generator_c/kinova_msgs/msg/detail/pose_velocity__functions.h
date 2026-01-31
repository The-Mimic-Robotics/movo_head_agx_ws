// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from kinova_msgs:msg/PoseVelocity.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY__FUNCTIONS_H_
#define KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "kinova_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "kinova_msgs/msg/detail/pose_velocity__struct.h"

/// Initialize msg/PoseVelocity message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__msg__PoseVelocity
 * )) before or use
 * kinova_msgs__msg__PoseVelocity__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocity__init(kinova_msgs__msg__PoseVelocity * msg);

/// Finalize msg/PoseVelocity message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__msg__PoseVelocity__fini(kinova_msgs__msg__PoseVelocity * msg);

/// Create msg/PoseVelocity message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__msg__PoseVelocity__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__msg__PoseVelocity *
kinova_msgs__msg__PoseVelocity__create();

/// Destroy msg/PoseVelocity message.
/**
 * It calls
 * kinova_msgs__msg__PoseVelocity__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__msg__PoseVelocity__destroy(kinova_msgs__msg__PoseVelocity * msg);

/// Check for msg/PoseVelocity message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocity__are_equal(const kinova_msgs__msg__PoseVelocity * lhs, const kinova_msgs__msg__PoseVelocity * rhs);

/// Copy a msg/PoseVelocity message.
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
kinova_msgs__msg__PoseVelocity__copy(
  const kinova_msgs__msg__PoseVelocity * input,
  kinova_msgs__msg__PoseVelocity * output);

/// Initialize array of msg/PoseVelocity messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__msg__PoseVelocity__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocity__Sequence__init(kinova_msgs__msg__PoseVelocity__Sequence * array, size_t size);

/// Finalize array of msg/PoseVelocity messages.
/**
 * It calls
 * kinova_msgs__msg__PoseVelocity__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__msg__PoseVelocity__Sequence__fini(kinova_msgs__msg__PoseVelocity__Sequence * array);

/// Create array of msg/PoseVelocity messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__msg__PoseVelocity__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__msg__PoseVelocity__Sequence *
kinova_msgs__msg__PoseVelocity__Sequence__create(size_t size);

/// Destroy array of msg/PoseVelocity messages.
/**
 * It calls
 * kinova_msgs__msg__PoseVelocity__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__msg__PoseVelocity__Sequence__destroy(kinova_msgs__msg__PoseVelocity__Sequence * array);

/// Check for msg/PoseVelocity message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__msg__PoseVelocity__Sequence__are_equal(const kinova_msgs__msg__PoseVelocity__Sequence * lhs, const kinova_msgs__msg__PoseVelocity__Sequence * rhs);

/// Copy an array of msg/PoseVelocity messages.
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
kinova_msgs__msg__PoseVelocity__Sequence__copy(
  const kinova_msgs__msg__PoseVelocity__Sequence * input,
  kinova_msgs__msg__PoseVelocity__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY__FUNCTIONS_H_
