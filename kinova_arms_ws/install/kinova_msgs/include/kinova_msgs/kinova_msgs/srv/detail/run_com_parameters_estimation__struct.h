// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:srv/RunCOMParametersEstimation.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__RUN_COM_PARAMETERS_ESTIMATION__STRUCT_H_
#define KINOVA_MSGS__SRV__DETAIL__RUN_COM_PARAMETERS_ESTIMATION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/RunCOMParametersEstimation in the package kinova_msgs.
typedef struct kinova_msgs__srv__RunCOMParametersEstimation_Request
{
  uint8_t structure_needs_at_least_one_member;
} kinova_msgs__srv__RunCOMParametersEstimation_Request;

// Struct for a sequence of kinova_msgs__srv__RunCOMParametersEstimation_Request.
typedef struct kinova_msgs__srv__RunCOMParametersEstimation_Request__Sequence
{
  kinova_msgs__srv__RunCOMParametersEstimation_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__srv__RunCOMParametersEstimation_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RunCOMParametersEstimation in the package kinova_msgs.
typedef struct kinova_msgs__srv__RunCOMParametersEstimation_Response
{
  rosidl_runtime_c__String result;
} kinova_msgs__srv__RunCOMParametersEstimation_Response;

// Struct for a sequence of kinova_msgs__srv__RunCOMParametersEstimation_Response.
typedef struct kinova_msgs__srv__RunCOMParametersEstimation_Response__Sequence
{
  kinova_msgs__srv__RunCOMParametersEstimation_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__srv__RunCOMParametersEstimation_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__SRV__DETAIL__RUN_COM_PARAMETERS_ESTIMATION__STRUCT_H_
