// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from kinova_msgs:msg/PoseVelocityWithFingers.idl
// generated code does not contain a copyright notice
#include "kinova_msgs/msg/detail/pose_velocity_with_fingers__rosidl_typesupport_fastrtps_cpp.hpp"
#include "kinova_msgs/msg/detail/pose_velocity_with_fingers__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace kinova_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kinova_msgs
cdr_serialize(
  const kinova_msgs::msg::PoseVelocityWithFingers & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: twist_linear_x
  cdr << ros_message.twist_linear_x;
  // Member: twist_linear_y
  cdr << ros_message.twist_linear_y;
  // Member: twist_linear_z
  cdr << ros_message.twist_linear_z;
  // Member: twist_angular_x
  cdr << ros_message.twist_angular_x;
  // Member: twist_angular_y
  cdr << ros_message.twist_angular_y;
  // Member: twist_angular_z
  cdr << ros_message.twist_angular_z;
  // Member: fingers_closure_percentage
  cdr << ros_message.fingers_closure_percentage;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kinova_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  kinova_msgs::msg::PoseVelocityWithFingers & ros_message)
{
  // Member: twist_linear_x
  cdr >> ros_message.twist_linear_x;

  // Member: twist_linear_y
  cdr >> ros_message.twist_linear_y;

  // Member: twist_linear_z
  cdr >> ros_message.twist_linear_z;

  // Member: twist_angular_x
  cdr >> ros_message.twist_angular_x;

  // Member: twist_angular_y
  cdr >> ros_message.twist_angular_y;

  // Member: twist_angular_z
  cdr >> ros_message.twist_angular_z;

  // Member: fingers_closure_percentage
  cdr >> ros_message.fingers_closure_percentage;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kinova_msgs
get_serialized_size(
  const kinova_msgs::msg::PoseVelocityWithFingers & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: twist_linear_x
  {
    size_t item_size = sizeof(ros_message.twist_linear_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: twist_linear_y
  {
    size_t item_size = sizeof(ros_message.twist_linear_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: twist_linear_z
  {
    size_t item_size = sizeof(ros_message.twist_linear_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: twist_angular_x
  {
    size_t item_size = sizeof(ros_message.twist_angular_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: twist_angular_y
  {
    size_t item_size = sizeof(ros_message.twist_angular_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: twist_angular_z
  {
    size_t item_size = sizeof(ros_message.twist_angular_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fingers_closure_percentage
  {
    size_t item_size = sizeof(ros_message.fingers_closure_percentage);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_kinova_msgs
max_serialized_size_PoseVelocityWithFingers(
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


  // Member: twist_linear_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: twist_linear_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: twist_linear_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: twist_angular_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: twist_angular_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: twist_angular_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: fingers_closure_percentage
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
    using DataType = kinova_msgs::msg::PoseVelocityWithFingers;
    is_plain =
      (
      offsetof(DataType, fingers_closure_percentage) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PoseVelocityWithFingers__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const kinova_msgs::msg::PoseVelocityWithFingers *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PoseVelocityWithFingers__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<kinova_msgs::msg::PoseVelocityWithFingers *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PoseVelocityWithFingers__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const kinova_msgs::msg::PoseVelocityWithFingers *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PoseVelocityWithFingers__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PoseVelocityWithFingers(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PoseVelocityWithFingers__callbacks = {
  "kinova_msgs::msg",
  "PoseVelocityWithFingers",
  _PoseVelocityWithFingers__cdr_serialize,
  _PoseVelocityWithFingers__cdr_deserialize,
  _PoseVelocityWithFingers__get_serialized_size,
  _PoseVelocityWithFingers__max_serialized_size
};

static rosidl_message_type_support_t _PoseVelocityWithFingers__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PoseVelocityWithFingers__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace kinova_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<kinova_msgs::msg::PoseVelocityWithFingers>()
{
  return &kinova_msgs::msg::typesupport_fastrtps_cpp::_PoseVelocityWithFingers__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, kinova_msgs, msg, PoseVelocityWithFingers)() {
  return &kinova_msgs::msg::typesupport_fastrtps_cpp::_PoseVelocityWithFingers__handle;
}

#ifdef __cplusplus
}
#endif
