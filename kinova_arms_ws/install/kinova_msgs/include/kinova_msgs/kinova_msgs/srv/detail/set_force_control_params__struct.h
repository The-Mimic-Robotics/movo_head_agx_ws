// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:srv/SetForceControlParams.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__STRUCT_H_
#define KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'inertia_linear'
// Member 'inertia_angular'
// Member 'damping_linear'
// Member 'damping_angular'
// Member 'force_min_linear'
// Member 'force_min_angular'
// Member 'force_max_linear'
// Member 'force_max_angular'
#include "geometry_msgs/msg/detail/vector3__struct.h"

/// Struct defined in srv/SetForceControlParams in the package kinova_msgs.
typedef struct kinova_msgs__srv__SetForceControlParams_Request
{
  geometry_msgs__msg__Vector3 inertia_linear;
  geometry_msgs__msg__Vector3 inertia_angular;
  geometry_msgs__msg__Vector3 damping_linear;
  geometry_msgs__msg__Vector3 damping_angular;
  geometry_msgs__msg__Vector3 force_min_linear;
  geometry_msgs__msg__Vector3 force_min_angular;
  geometry_msgs__msg__Vector3 force_max_linear;
  geometry_msgs__msg__Vector3 force_max_angular;
} kinova_msgs__srv__SetForceControlParams_Request;

// Struct for a sequence of kinova_msgs__srv__SetForceControlParams_Request.
typedef struct kinova_msgs__srv__SetForceControlParams_Request__Sequence
{
  kinova_msgs__srv__SetForceControlParams_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__srv__SetForceControlParams_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetForceControlParams in the package kinova_msgs.
typedef struct kinova_msgs__srv__SetForceControlParams_Response
{
  uint8_t structure_needs_at_least_one_member;
} kinova_msgs__srv__SetForceControlParams_Response;

// Struct for a sequence of kinova_msgs__srv__SetForceControlParams_Response.
typedef struct kinova_msgs__srv__SetForceControlParams_Response__Sequence
{
  kinova_msgs__srv__SetForceControlParams_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__srv__SetForceControlParams_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__STRUCT_H_
