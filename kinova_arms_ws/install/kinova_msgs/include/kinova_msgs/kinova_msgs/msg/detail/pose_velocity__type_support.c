// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kinova_msgs:msg/PoseVelocity.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kinova_msgs/msg/detail/pose_velocity__rosidl_typesupport_introspection_c.h"
#include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kinova_msgs/msg/detail/pose_velocity__functions.h"
#include "kinova_msgs/msg/detail/pose_velocity__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__msg__PoseVelocity__init(message_memory);
}

void kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_fini_function(void * message_memory)
{
  kinova_msgs__msg__PoseVelocity__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_message_member_array[6] = {
  {
    "twist_linear_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__msg__PoseVelocity, twist_linear_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "twist_linear_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__msg__PoseVelocity, twist_linear_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "twist_linear_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__msg__PoseVelocity, twist_linear_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "twist_angular_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__msg__PoseVelocity, twist_angular_x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "twist_angular_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__msg__PoseVelocity, twist_angular_y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "twist_angular_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__msg__PoseVelocity, twist_angular_z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_message_members = {
  "kinova_msgs__msg",  // message namespace
  "PoseVelocity",  // message name
  6,  // number of fields
  sizeof(kinova_msgs__msg__PoseVelocity),
  kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_message_member_array,  // message members
  kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_message_type_support_handle = {
  0,
  &kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, msg, PoseVelocity)() {
  if (!kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__msg__PoseVelocity__rosidl_typesupport_introspection_c__PoseVelocity_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
