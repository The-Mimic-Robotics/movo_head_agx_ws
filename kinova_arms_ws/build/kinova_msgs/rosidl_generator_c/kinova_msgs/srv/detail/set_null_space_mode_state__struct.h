// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:srv/SetNullSpaceModeState.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__SET_NULL_SPACE_MODE_STATE__STRUCT_H_
#define KINOVA_MSGS__SRV__DETAIL__SET_NULL_SPACE_MODE_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/SetNullSpaceModeState in the package kinova_msgs.
typedef struct kinova_msgs__srv__SetNullSpaceModeState_Request
{
  uint16_t state;
} kinova_msgs__srv__SetNullSpaceModeState_Request;

// Struct for a sequence of kinova_msgs__srv__SetNullSpaceModeState_Request.
typedef struct kinova_msgs__srv__SetNullSpaceModeState_Request__Sequence
{
  kinova_msgs__srv__SetNullSpaceModeState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__srv__SetNullSpaceModeState_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetNullSpaceModeState in the package kinova_msgs.
typedef struct kinova_msgs__srv__SetNullSpaceModeState_Response
{
  uint8_t structure_needs_at_least_one_member;
} kinova_msgs__srv__SetNullSpaceModeState_Response;

// Struct for a sequence of kinova_msgs__srv__SetNullSpaceModeState_Response.
typedef struct kinova_msgs__srv__SetNullSpaceModeState_Response__Sequence
{
  kinova_msgs__srv__SetNullSpaceModeState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__srv__SetNullSpaceModeState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__SRV__DETAIL__SET_NULL_SPACE_MODE_STATE__STRUCT_H_
