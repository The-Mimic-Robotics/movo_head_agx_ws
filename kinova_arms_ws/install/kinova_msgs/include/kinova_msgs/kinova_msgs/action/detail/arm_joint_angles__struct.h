// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from kinova_msgs:action/ArmJointAngles.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__ACTION__DETAIL__ARM_JOINT_ANGLES__STRUCT_H_
#define KINOVA_MSGS__ACTION__DETAIL__ARM_JOINT_ANGLES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'angles'
#include "kinova_msgs/msg/detail/joint_angles__struct.h"

/// Struct defined in action/ArmJointAngles in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmJointAngles_Goal
{
  kinova_msgs__msg__JointAngles angles;
} kinova_msgs__action__ArmJointAngles_Goal;

// Struct for a sequence of kinova_msgs__action__ArmJointAngles_Goal.
typedef struct kinova_msgs__action__ArmJointAngles_Goal__Sequence
{
  kinova_msgs__action__ArmJointAngles_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmJointAngles_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'angles'
// already included above
// #include "kinova_msgs/msg/detail/joint_angles__struct.h"

/// Struct defined in action/ArmJointAngles in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmJointAngles_Result
{
  kinova_msgs__msg__JointAngles angles;
} kinova_msgs__action__ArmJointAngles_Result;

// Struct for a sequence of kinova_msgs__action__ArmJointAngles_Result.
typedef struct kinova_msgs__action__ArmJointAngles_Result__Sequence
{
  kinova_msgs__action__ArmJointAngles_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmJointAngles_Result__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'angles'
// already included above
// #include "kinova_msgs/msg/detail/joint_angles__struct.h"

/// Struct defined in action/ArmJointAngles in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmJointAngles_Feedback
{
  kinova_msgs__msg__JointAngles angles;
} kinova_msgs__action__ArmJointAngles_Feedback;

// Struct for a sequence of kinova_msgs__action__ArmJointAngles_Feedback.
typedef struct kinova_msgs__action__ArmJointAngles_Feedback__Sequence
{
  kinova_msgs__action__ArmJointAngles_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmJointAngles_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "kinova_msgs/action/detail/arm_joint_angles__struct.h"

/// Struct defined in action/ArmJointAngles in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmJointAngles_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  kinova_msgs__action__ArmJointAngles_Goal goal;
} kinova_msgs__action__ArmJointAngles_SendGoal_Request;

// Struct for a sequence of kinova_msgs__action__ArmJointAngles_SendGoal_Request.
typedef struct kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence
{
  kinova_msgs__action__ArmJointAngles_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmJointAngles_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/ArmJointAngles in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmJointAngles_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} kinova_msgs__action__ArmJointAngles_SendGoal_Response;

// Struct for a sequence of kinova_msgs__action__ArmJointAngles_SendGoal_Response.
typedef struct kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence
{
  kinova_msgs__action__ArmJointAngles_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmJointAngles_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/ArmJointAngles in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmJointAngles_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} kinova_msgs__action__ArmJointAngles_GetResult_Request;

// Struct for a sequence of kinova_msgs__action__ArmJointAngles_GetResult_Request.
typedef struct kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence
{
  kinova_msgs__action__ArmJointAngles_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmJointAngles_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__struct.h"

/// Struct defined in action/ArmJointAngles in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmJointAngles_GetResult_Response
{
  int8_t status;
  kinova_msgs__action__ArmJointAngles_Result result;
} kinova_msgs__action__ArmJointAngles_GetResult_Response;

// Struct for a sequence of kinova_msgs__action__ArmJointAngles_GetResult_Response.
typedef struct kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence
{
  kinova_msgs__action__ArmJointAngles_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmJointAngles_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__struct.h"

/// Struct defined in action/ArmJointAngles in the package kinova_msgs.
typedef struct kinova_msgs__action__ArmJointAngles_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  kinova_msgs__action__ArmJointAngles_Feedback feedback;
} kinova_msgs__action__ArmJointAngles_FeedbackMessage;

// Struct for a sequence of kinova_msgs__action__ArmJointAngles_FeedbackMessage.
typedef struct kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence
{
  kinova_msgs__action__ArmJointAngles_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} kinova_msgs__action__ArmJointAngles_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // KINOVA_MSGS__ACTION__DETAIL__ARM_JOINT_ANGLES__STRUCT_H_
