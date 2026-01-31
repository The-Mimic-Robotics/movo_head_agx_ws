// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kinova_msgs:action/ArmJointAngles.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
#include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kinova_msgs/action/detail/arm_joint_angles__functions.h"
#include "kinova_msgs/action/detail/arm_joint_angles__struct.h"


// Include directives for member types
// Member `angles`
#include "kinova_msgs/msg/joint_angles.h"
// Member `angles`
#include "kinova_msgs/msg/detail/joint_angles__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__action__ArmJointAngles_Goal__init(message_memory);
}

void kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_fini_function(void * message_memory)
{
  kinova_msgs__action__ArmJointAngles_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_message_member_array[1] = {
  {
    "angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_Goal, angles),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_message_members = {
  "kinova_msgs__action",  // message namespace
  "ArmJointAngles_Goal",  // message name
  1,  // number of fields
  sizeof(kinova_msgs__action__ArmJointAngles_Goal),
  kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_message_member_array,  // message members
  kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_message_type_support_handle = {
  0,
  &kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_Goal)() {
  kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, msg, JointAngles)();
  if (!kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__action__ArmJointAngles_Goal__rosidl_typesupport_introspection_c__ArmJointAngles_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__struct.h"


// Include directives for member types
// Member `angles`
// already included above
// #include "kinova_msgs/msg/joint_angles.h"
// Member `angles`
// already included above
// #include "kinova_msgs/msg/detail/joint_angles__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__action__ArmJointAngles_Result__init(message_memory);
}

void kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_fini_function(void * message_memory)
{
  kinova_msgs__action__ArmJointAngles_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_message_member_array[1] = {
  {
    "angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_Result, angles),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_message_members = {
  "kinova_msgs__action",  // message namespace
  "ArmJointAngles_Result",  // message name
  1,  // number of fields
  sizeof(kinova_msgs__action__ArmJointAngles_Result),
  kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_message_member_array,  // message members
  kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_message_type_support_handle = {
  0,
  &kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_Result)() {
  kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, msg, JointAngles)();
  if (!kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__action__ArmJointAngles_Result__rosidl_typesupport_introspection_c__ArmJointAngles_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__struct.h"


// Include directives for member types
// Member `angles`
// already included above
// #include "kinova_msgs/msg/joint_angles.h"
// Member `angles`
// already included above
// #include "kinova_msgs/msg/detail/joint_angles__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__action__ArmJointAngles_Feedback__init(message_memory);
}

void kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_fini_function(void * message_memory)
{
  kinova_msgs__action__ArmJointAngles_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_message_member_array[1] = {
  {
    "angles",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_Feedback, angles),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_message_members = {
  "kinova_msgs__action",  // message namespace
  "ArmJointAngles_Feedback",  // message name
  1,  // number of fields
  sizeof(kinova_msgs__action__ArmJointAngles_Feedback),
  kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_message_member_array,  // message members
  kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_message_type_support_handle = {
  0,
  &kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_Feedback)() {
  kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, msg, JointAngles)();
  if (!kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__action__ArmJointAngles_Feedback__rosidl_typesupport_introspection_c__ArmJointAngles_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "kinova_msgs/action/arm_joint_angles.h"
// Member `goal`
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__init(message_memory);
}

void kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_fini_function(void * message_memory)
{
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_members = {
  "kinova_msgs__action",  // message namespace
  "ArmJointAngles_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Request),
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_member_array,  // message members
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_type_support_handle = {
  0,
  &kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_SendGoal_Request)() {
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_Goal)();
  if (!kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__action__ArmJointAngles_SendGoal_Request__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__action__ArmJointAngles_SendGoal_Response__init(message_memory);
}

void kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_fini_function(void * message_memory)
{
  kinova_msgs__action__ArmJointAngles_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_members = {
  "kinova_msgs__action",  // message namespace
  "ArmJointAngles_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(kinova_msgs__action__ArmJointAngles_SendGoal_Response),
  kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_member_array,  // message members
  kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_type_support_handle = {
  0,
  &kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_SendGoal_Response)() {
  kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__action__ArmJointAngles_SendGoal_Response__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_service_members = {
  "kinova_msgs__action",  // service namespace
  "ArmJointAngles_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_service_type_support_handle = {
  0,
  &kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_SendGoal)() {
  if (!kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_service_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_SendGoal_Response)()->data;
  }

  return &kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__action__ArmJointAngles_GetResult_Request__init(message_memory);
}

void kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_fini_function(void * message_memory)
{
  kinova_msgs__action__ArmJointAngles_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_members = {
  "kinova_msgs__action",  // message namespace
  "ArmJointAngles_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Request),
  kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_member_array,  // message members
  kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_type_support_handle = {
  0,
  &kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_GetResult_Request)() {
  kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__action__ArmJointAngles_GetResult_Request__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "kinova_msgs/action/arm_joint_angles.h"
// Member `result`
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__action__ArmJointAngles_GetResult_Response__init(message_memory);
}

void kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_fini_function(void * message_memory)
{
  kinova_msgs__action__ArmJointAngles_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_members = {
  "kinova_msgs__action",  // message namespace
  "ArmJointAngles_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(kinova_msgs__action__ArmJointAngles_GetResult_Response),
  kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_member_array,  // message members
  kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_type_support_handle = {
  0,
  &kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_GetResult_Response)() {
  kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_Result)();
  if (!kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__action__ArmJointAngles_GetResult_Response__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_service_members = {
  "kinova_msgs__action",  // service namespace
  "ArmJointAngles_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_service_type_support_handle = {
  0,
  &kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_GetResult)() {
  if (!kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_service_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_GetResult_Response)()->data;
  }

  return &kinova_msgs__action__detail__arm_joint_angles__rosidl_typesupport_introspection_c__ArmJointAngles_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__functions.h"
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "kinova_msgs/action/arm_joint_angles.h"
// Member `feedback`
// already included above
// #include "kinova_msgs/action/detail/arm_joint_angles__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__init(message_memory);
}

void kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_fini_function(void * message_memory)
{
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__action__ArmJointAngles_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_members = {
  "kinova_msgs__action",  // message namespace
  "ArmJointAngles_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(kinova_msgs__action__ArmJointAngles_FeedbackMessage),
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_member_array,  // message members
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_type_support_handle = {
  0,
  &kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_FeedbackMessage)() {
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, action, ArmJointAngles_Feedback)();
  if (!kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__action__ArmJointAngles_FeedbackMessage__rosidl_typesupport_introspection_c__ArmJointAngles_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
