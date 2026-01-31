// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from kinova_msgs:msg/PoseVelocityWithFingers.idl
// generated code does not contain a copyright notice
#include "kinova_msgs/msg/detail/pose_velocity_with_fingers__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "kinova_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "kinova_msgs/msg/detail/pose_velocity_with_fingers__struct.h"
#include "kinova_msgs/msg/detail/pose_velocity_with_fingers__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _PoseVelocityWithFingers__ros_msg_type = kinova_msgs__msg__PoseVelocityWithFingers;

static bool _PoseVelocityWithFingers__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PoseVelocityWithFingers__ros_msg_type * ros_message = static_cast<const _PoseVelocityWithFingers__ros_msg_type *>(untyped_ros_message);
  // Field name: twist_linear_x
  {
    cdr << ros_message->twist_linear_x;
  }

  // Field name: twist_linear_y
  {
    cdr << ros_message->twist_linear_y;
  }

  // Field name: twist_linear_z
  {
    cdr << ros_message->twist_linear_z;
  }

  // Field name: twist_angular_x
  {
    cdr << ros_message->twist_angular_x;
  }

  // Field name: twist_angular_y
  {
    cdr << ros_message->twist_angular_y;
  }

  // Field name: twist_angular_z
  {
    cdr << ros_message->twist_angular_z;
  }

  // Field name: fingers_closure_percentage
  {
    cdr << ros_message->fingers_closure_percentage;
  }

  return true;
}

static bool _PoseVelocityWithFingers__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PoseVelocityWithFingers__ros_msg_type * ros_message = static_cast<_PoseVelocityWithFingers__ros_msg_type *>(untyped_ros_message);
  // Field name: twist_linear_x
  {
    cdr >> ros_message->twist_linear_x;
  }

  // Field name: twist_linear_y
  {
    cdr >> ros_message->twist_linear_y;
  }

  // Field name: twist_linear_z
  {
    cdr >> ros_message->twist_linear_z;
  }

  // Field name: twist_angular_x
  {
    cdr >> ros_message->twist_angular_x;
  }

  // Field name: twist_angular_y
  {
    cdr >> ros_message->twist_angular_y;
  }

  // Field name: twist_angular_z
  {
    cdr >> ros_message->twist_angular_z;
  }

  // Field name: fingers_closure_percentage
  {
    cdr >> ros_message->fingers_closure_percentage;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kinova_msgs
size_t get_serialized_size_kinova_msgs__msg__PoseVelocityWithFingers(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PoseVelocityWithFingers__ros_msg_type * ros_message = static_cast<const _PoseVelocityWithFingers__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name twist_linear_x
  {
    size_t item_size = sizeof(ros_message->twist_linear_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name twist_linear_y
  {
    size_t item_size = sizeof(ros_message->twist_linear_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name twist_linear_z
  {
    size_t item_size = sizeof(ros_message->twist_linear_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name twist_angular_x
  {
    size_t item_size = sizeof(ros_message->twist_angular_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name twist_angular_y
  {
    size_t item_size = sizeof(ros_message->twist_angular_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name twist_angular_z
  {
    size_t item_size = sizeof(ros_message->twist_angular_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name fingers_closure_percentage
  {
    size_t item_size = sizeof(ros_message->fingers_closure_percentage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _PoseVelocityWithFingers__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_kinova_msgs__msg__PoseVelocityWithFingers(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_kinova_msgs
size_t max_serialized_size_kinova_msgs__msg__PoseVelocityWithFingers(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: twist_linear_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: twist_linear_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: twist_linear_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: twist_angular_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: twist_angular_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: twist_angular_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: fingers_closure_percentage
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = kinova_msgs__msg__PoseVelocityWithFingers;
    is_plain =
      (
      offsetof(DataType, fingers_closure_percentage) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _PoseVelocityWithFingers__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_kinova_msgs__msg__PoseVelocityWithFingers(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_PoseVelocityWithFingers = {
  "kinova_msgs::msg",
  "PoseVelocityWithFingers",
  _PoseVelocityWithFingers__cdr_serialize,
  _PoseVelocityWithFingers__cdr_deserialize,
  _PoseVelocityWithFingers__get_serialized_size,
  _PoseVelocityWithFingers__max_serialized_size
};

static rosidl_message_type_support_t _PoseVelocityWithFingers__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PoseVelocityWithFingers,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, kinova_msgs, msg, PoseVelocityWithFingers)() {
  return &_PoseVelocityWithFingers__type_support;
}

#if defined(__cplusplus)
}
#endif
