// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:action/ArmKinovaPose.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__ACTION__DETAIL__ARM_KINOVA_POSE__STRUCT_H_
#define KINOVA_MSGS__ACTION__DETAIL__ARM_KINOVA_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'kinova_pose'
#include "kinova_msgs/msg/detail/kinova_pose__struct.h"

/// Struct defined in action/ArmKinovaPose in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmKinovaPose_Goal
{
  kinova_msgs__msg__KinovaPose kinova_pose;
} kinova_msgs__action__ArmKinovaPose_Goal;

// Struct for a sequence of kinova_msgs__action__ArmKinovaPose_Goal.
typedef struct kinova_msgs__action__ArmKinovaPose_Goal__Sequence
{
  kinova_msgs__action__ArmKinovaPose_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmKinovaPose_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'kinova_pose'
// already included above
// #include "kinova_msgs/msg/detail/kinova_pose__struct.h"

/// Struct defined in action/ArmKinovaPose in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmKinovaPose_Result
{
  kinova_msgs__msg__KinovaPose kinova_pose;
} kinova_msgs__action__ArmKinovaPose_Result;

// Struct for a sequence of kinova_msgs__action__ArmKinovaPose_Result.
typedef struct kinova_msgs__action__ArmKinovaPose_Result__Sequence
{
  kinova_msgs__action__ArmKinovaPose_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmKinovaPose_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'kinova_pose'
// already included above
// #include "kinova_msgs/msg/detail/kinova_pose__struct.h"

/// Struct defined in action/ArmKinovaPose in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmKinovaPose_Feedback
{
  kinova_msgs__msg__KinovaPose kinova_pose;
} kinova_msgs__action__ArmKinovaPose_Feedback;

// Struct for a sequence of kinova_msgs__action__ArmKinovaPose_Feedback.
typedef struct kinova_msgs__action__ArmKinovaPose_Feedback__Sequence
{
  kinova_msgs__action__ArmKinovaPose_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmKinovaPose_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "kinova_msgs/action/detail/arm_kinova_pose__struct.h"

/// Struct defined in action/ArmKinovaPose in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmKinovaPose_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  kinova_msgs__action__ArmKinovaPose_Goal goal;
} kinova_msgs__action__ArmKinovaPose_SendGoal_Request;

// Struct for a sequence of kinova_msgs__action__ArmKinovaPose_SendGoal_Request.
typedef struct kinova_msgs__action__ArmKinovaPose_SendGoal_Request__Sequence
{
  kinova_msgs__action__ArmKinovaPose_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmKinovaPose_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ArmKinovaPose in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmKinovaPose_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} kinova_msgs__action__ArmKinovaPose_SendGoal_Response;

// Struct for a sequence of kinova_msgs__action__ArmKinovaPose_SendGoal_Response.
typedef struct kinova_msgs__action__ArmKinovaPose_SendGoal_Response__Sequence
{
  kinova_msgs__action__ArmKinovaPose_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmKinovaPose_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ArmKinovaPose in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmKinovaPose_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} kinova_msgs__action__ArmKinovaPose_GetResult_Request;

// Struct for a sequence of kinova_msgs__action__ArmKinovaPose_GetResult_Request.
typedef struct kinova_msgs__action__ArmKinovaPose_GetResult_Request__Sequence
{
  kinova_msgs__action__ArmKinovaPose_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmKinovaPose_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "kinova_msgs/action/detail/arm_kinova_pose__struct.h"

/// Struct defined in action/ArmKinovaPose in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmKinovaPose_GetResult_Response
{
  int8_t status;
  kinova_msgs__action__ArmKinovaPose_Result result;
} kinova_msgs__action__ArmKinovaPose_GetResult_Response;

// Struct for a sequence of kinova_msgs__action__ArmKinovaPose_GetResult_Response.
typedef struct kinova_msgs__action__ArmKinovaPose_GetResult_Response__Sequence
{
  kinova_msgs__action__ArmKinovaPose_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmKinovaPose_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "kinova_msgs/action/detail/arm_kinova_pose__struct.h"

/// Struct defined in action/ArmKinovaPose in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmKinovaPose_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  kinova_msgs__action__ArmKinovaPose_Feedback feedback;
} kinova_msgs__action__ArmKinovaPose_FeedbackMessage;

// Struct for a sequence of kinova_msgs__action__ArmKinovaPose_FeedbackMessage.
typedef struct kinova_msgs__action__ArmKinovaPose_FeedbackMessage__Sequence
{
  kinova_msgs__action__ArmKinovaPose_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmKinovaPose_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__ACTION__DETAIL__ARM_KINOVA_POSE__STRUCT_H_
