// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from kinova_msgs:action/ArmJointAngles.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__ACTION__DETAIL__ARM_JOINT_ANGLES__FUNCTIONS_H_
#define KINOVA_MSGS__ACTION__DETAIL__ARM_JOINT_ANGLES__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "kinova_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "kinova_msgs/action/detail/arm_joint_angles__struct.h"

/// Initialize action/ArmJointAngles message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__action__ArmJointAngles_Goal
 * )) before or use
 * kinova_msgs__action__ArmJointAngles_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Goal__init(kinova_msgs__action__ArmJointAngles_Goal * msg);

/// Finalize action/ArmJointAngles message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Goal__fini(kinova_msgs__action__ArmJointAngles_Goal * msg);

/// Create action/ArmJointAngles message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__action__ArmJointAngles_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_Goal *
kinova_msgs__action__ArmJointAngles_Goal__create();

/// Destroy action/ArmJointAngles message.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Goal__destroy(kinova_msgs__action__ArmJointAngles_Goal * msg);

/// Check for action/ArmJointAngles message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Goal__are_equal(const kinova_msgs__action__ArmJointAngles_Goal * lhs, const kinova_msgs__action__ArmJointAngles_Goal * rhs);

/// Copy a action/ArmJointAngles message.
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
kinova_msgs__action__ArmJointAngles_Goal__copy(
  const kinova_msgs__action__ArmJointAngles_Goal * input,
  kinova_msgs__action__ArmJointAngles_Goal * output);

/// Initialize array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__action__ArmJointAngles_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Goal__Sequence__init(kinova_msgs__action__ArmJointAngles_Goal__Sequence * array, size_t size);

/// Finalize array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Goal__Sequence__fini(kinova_msgs__action__ArmJointAngles_Goal__Sequence * array);

/// Create array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__action__ArmJointAngles_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_Goal__Sequence *
kinova_msgs__action__ArmJointAngles_Goal__Sequence__create(size_t size);

/// Destroy array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Goal__Sequence__destroy(kinova_msgs__action__ArmJointAngles_Goal__Sequence * array);

/// Check for action/ArmJointAngles message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Goal__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_Goal__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_Goal__Sequence * rhs);

/// Copy an array of action/ArmJointAngles messages.
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
kinova_msgs__action__ArmJointAngles_Goal__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_Goal__Sequence * input,
  kinova_msgs__action__ArmJointAngles_Goal__Sequence * output);

/// Initialize action/ArmJointAngles message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__action__ArmJointAngles_Result
 * )) before or use
 * kinova_msgs__action__ArmJointAngles_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Result__init(kinova_msgs__action__ArmJointAngles_Result * msg);

/// Finalize action/ArmJointAngles message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Result__fini(kinova_msgs__action__ArmJointAngles_Result * msg);

/// Create action/ArmJointAngles message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__action__ArmJointAngles_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_Result *
kinova_msgs__action__ArmJointAngles_Result__create();

/// Destroy action/ArmJointAngles message.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Result__destroy(kinova_msgs__action__ArmJointAngles_Result * msg);

/// Check for action/ArmJointAngles message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Result__are_equal(const kinova_msgs__action__ArmJointAngles_Result * lhs, const kinova_msgs__action__ArmJointAngles_Result * rhs);

/// Copy a action/ArmJointAngles message.
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
kinova_msgs__action__ArmJointAngles_Result__copy(
  const kinova_msgs__action__ArmJointAngles_Result * input,
  kinova_msgs__action__ArmJointAngles_Result * output);

/// Initialize array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__action__ArmJointAngles_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Result__Sequence__init(kinova_msgs__action__ArmJointAngles_Result__Sequence * array, size_t size);

/// Finalize array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Result__Sequence__fini(kinova_msgs__action__ArmJointAngles_Result__Sequence * array);

/// Create array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__action__ArmJointAngles_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_Result__Sequence *
kinova_msgs__action__ArmJointAngles_Result__Sequence__create(size_t size);

/// Destroy array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Result__Sequence__destroy(kinova_msgs__action__ArmJointAngles_Result__Sequence * array);

/// Check for action/ArmJointAngles message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Result__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_Result__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_Result__Sequence * rhs);

/// Copy an array of action/ArmJointAngles messages.
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
kinova_msgs__action__ArmJointAngles_Result__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_Result__Sequence * input,
  kinova_msgs__action__ArmJointAngles_Result__Sequence * output);

/// Initialize action/ArmJointAngles message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__action__ArmJointAngles_Feedback
 * )) before or use
 * kinova_msgs__action__ArmJointAngles_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Feedback__init(kinova_msgs__action__ArmJointAngles_Feedback * msg);

/// Finalize action/ArmJointAngles message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Feedback__fini(kinova_msgs__action__ArmJointAngles_Feedback * msg);

/// Create action/ArmJointAngles message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__action__ArmJointAngles_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_Feedback *
kinova_msgs__action__ArmJointAngles_Feedback__create();

/// Destroy action/ArmJointAngles message.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Feedback__destroy(kinova_msgs__action__ArmJointAngles_Feedback * msg);

/// Check for action/ArmJointAngles message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Feedback__are_equal(const kinova_msgs__action__ArmJointAngles_Feedback * lhs, const kinova_msgs__action__ArmJointAngles_Feedback * rhs);

/// Copy a action/ArmJointAngles message.
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
kinova_msgs__action__ArmJointAngles_Feedback__copy(
  const kinova_msgs__action__ArmJointAngles_Feedback * input,
  kinova_msgs__action__ArmJointAngles_Feedback * output);

/// Initialize array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__action__ArmJointAngles_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__init(kinova_msgs__action__ArmJointAngles_Feedback__Sequence * array, size_t size);

/// Finalize array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__fini(kinova_msgs__action__ArmJointAngles_Feedback__Sequence * array);

/// Create array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__action__ArmJointAngles_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_Feedback__Sequence *
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__create(size_t size);

/// Destroy array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__destroy(kinova_msgs__action__ArmJointAngles_Feedback__Sequence * array);

/// Check for action/ArmJointAngles message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_Feedback__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_Feedback__Sequence * rhs);

/// Copy an array of action/ArmJointAngles messages.
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
kinova_msgs__action__ArmJointAngles_Feedback__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_Feedback__Sequence * input,
  kinova_msgs__action__ArmJointAngles_Feedback__Sequence * output);

/// Initialize action/ArmJointAngles message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__action__ArmJointAngles_SendGoal_Request
 * )) before or use
 * kinova_msgs__action__ArmJointAngles_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__init(kinova_msgs__action__ArmJointAngles_SendGoal_Request * msg);

/// Finalize action/ArmJointAngles message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini(kinova_msgs__action__ArmJointAngles_SendGoal_Request * msg);

/// Create action/ArmJointAngles message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_SendGoal_Request *
kinova_msgs__action__ArmJointAngles_SendGoal_Request__create();

/// Destroy action/ArmJointAngles message.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_SendGoal_Request__destroy(kinova_msgs__action__ArmJointAngles_SendGoal_Request * msg);

/// Check for action/ArmJointAngles message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__are_equal(const kinova_msgs__action__ArmJointAngles_SendGoal_Request * lhs, const kinova_msgs__action__ArmJointAngles_SendGoal_Request * rhs);

/// Copy a action/ArmJointAngles message.
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
kinova_msgs__action__ArmJointAngles_SendGoal_Request__copy(
  const kinova_msgs__action__ArmJointAngles_SendGoal_Request * input,
  kinova_msgs__action__ArmJointAngles_SendGoal_Request * output);

/// Initialize array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__init(kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__fini(kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * array);

/// Create array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence *
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__destroy(kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * array);

/// Check for action/ArmJointAngles message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/ArmJointAngles messages.
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
kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * input,
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence * output);

/// Initialize action/ArmJointAngles message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__action__ArmJointAngles_SendGoal_Response
 * )) before or use
 * kinova_msgs__action__ArmJointAngles_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__init(kinova_msgs__action__ArmJointAngles_SendGoal_Response * msg);

/// Finalize action/ArmJointAngles message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini(kinova_msgs__action__ArmJointAngles_SendGoal_Response * msg);

/// Create action/ArmJointAngles message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_SendGoal_Response *
kinova_msgs__action__ArmJointAngles_SendGoal_Response__create();

/// Destroy action/ArmJointAngles message.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_SendGoal_Response__destroy(kinova_msgs__action__ArmJointAngles_SendGoal_Response * msg);

/// Check for action/ArmJointAngles message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__are_equal(const kinova_msgs__action__ArmJointAngles_SendGoal_Response * lhs, const kinova_msgs__action__ArmJointAngles_SendGoal_Response * rhs);

/// Copy a action/ArmJointAngles message.
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
kinova_msgs__action__ArmJointAngles_SendGoal_Response__copy(
  const kinova_msgs__action__ArmJointAngles_SendGoal_Response * input,
  kinova_msgs__action__ArmJointAngles_SendGoal_Response * output);

/// Initialize array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__init(kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__fini(kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * array);

/// Create array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence *
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__destroy(kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * array);

/// Check for action/ArmJointAngles message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/ArmJointAngles messages.
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
kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * input,
  kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence * output);

/// Initialize action/ArmJointAngles message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__action__ArmJointAngles_GetResult_Request
 * )) before or use
 * kinova_msgs__action__ArmJointAngles_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__init(kinova_msgs__action__ArmJointAngles_GetResult_Request * msg);

/// Finalize action/ArmJointAngles message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_GetResult_Request__fini(kinova_msgs__action__ArmJointAngles_GetResult_Request * msg);

/// Create action/ArmJointAngles message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_GetResult_Request *
kinova_msgs__action__ArmJointAngles_GetResult_Request__create();

/// Destroy action/ArmJointAngles message.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_GetResult_Request__destroy(kinova_msgs__action__ArmJointAngles_GetResult_Request * msg);

/// Check for action/ArmJointAngles message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__are_equal(const kinova_msgs__action__ArmJointAngles_GetResult_Request * lhs, const kinova_msgs__action__ArmJointAngles_GetResult_Request * rhs);

/// Copy a action/ArmJointAngles message.
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
kinova_msgs__action__ArmJointAngles_GetResult_Request__copy(
  const kinova_msgs__action__ArmJointAngles_GetResult_Request * input,
  kinova_msgs__action__ArmJointAngles_GetResult_Request * output);

/// Initialize array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__init(kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__fini(kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * array);

/// Create array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence *
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__destroy(kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * array);

/// Check for action/ArmJointAngles message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * rhs);

/// Copy an array of action/ArmJointAngles messages.
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
kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * input,
  kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence * output);

/// Initialize action/ArmJointAngles message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__action__ArmJointAngles_GetResult_Response
 * )) before or use
 * kinova_msgs__action__ArmJointAngles_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__init(kinova_msgs__action__ArmJointAngles_GetResult_Response * msg);

/// Finalize action/ArmJointAngles message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_GetResult_Response__fini(kinova_msgs__action__ArmJointAngles_GetResult_Response * msg);

/// Create action/ArmJointAngles message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_GetResult_Response *
kinova_msgs__action__ArmJointAngles_GetResult_Response__create();

/// Destroy action/ArmJointAngles message.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_GetResult_Response__destroy(kinova_msgs__action__ArmJointAngles_GetResult_Response * msg);

/// Check for action/ArmJointAngles message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__are_equal(const kinova_msgs__action__ArmJointAngles_GetResult_Response * lhs, const kinova_msgs__action__ArmJointAngles_GetResult_Response * rhs);

/// Copy a action/ArmJointAngles message.
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
kinova_msgs__action__ArmJointAngles_GetResult_Response__copy(
  const kinova_msgs__action__ArmJointAngles_GetResult_Response * input,
  kinova_msgs__action__ArmJointAngles_GetResult_Response * output);

/// Initialize array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__init(kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__fini(kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * array);

/// Create array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence *
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__destroy(kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * array);

/// Check for action/ArmJointAngles message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * rhs);

/// Copy an array of action/ArmJointAngles messages.
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
kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * input,
  kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence * output);

/// Initialize action/ArmJointAngles message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * kinova_msgs__action__ArmJointAngles_FeedbackMessage
 * )) before or use
 * kinova_msgs__action__ArmJointAngles_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__init(kinova_msgs__action__ArmJointAngles_FeedbackMessage * msg);

/// Finalize action/ArmJointAngles message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini(kinova_msgs__action__ArmJointAngles_FeedbackMessage * msg);

/// Create action/ArmJointAngles message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * kinova_msgs__action__ArmJointAngles_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_FeedbackMessage *
kinova_msgs__action__ArmJointAngles_FeedbackMessage__create();

/// Destroy action/ArmJointAngles message.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_FeedbackMessage__destroy(kinova_msgs__action__ArmJointAngles_FeedbackMessage * msg);

/// Check for action/ArmJointAngles message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__are_equal(const kinova_msgs__action__ArmJointAngles_FeedbackMessage * lhs, const kinova_msgs__action__ArmJointAngles_FeedbackMessage * rhs);

/// Copy a action/ArmJointAngles message.
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
kinova_msgs__action__ArmJointAngles_FeedbackMessage__copy(
  const kinova_msgs__action__ArmJointAngles_FeedbackMessage * input,
  kinova_msgs__action__ArmJointAngles_FeedbackMessage * output);

/// Initialize array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the number of elements and calls
 * kinova_msgs__action__ArmJointAngles_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__init(kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__fini(kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * array);

/// Create array of action/ArmJointAngles messages.
/**
 * It allocates the memory for the array and calls
 * kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence *
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/ArmJointAngles messages.
/**
 * It calls
 * kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
void
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__destroy(kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * array);

/// Check for action/ArmJointAngles message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_kinova_msgs
bool
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__are_equal(const kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * lhs, const kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/ArmJointAngles messages.
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
kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence__copy(
  const kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * input,
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__ACTION__DETAIL__ARM_JOINT_ANGLES__FUNCTIONS_H_
