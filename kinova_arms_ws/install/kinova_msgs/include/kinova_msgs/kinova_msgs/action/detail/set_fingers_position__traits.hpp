// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kinova_msgs:action/SetFingersPosition.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__ACTION__DETAIL__SET_FINGERS_POSITION__TRAITS_HPP_
#define KINOVA_MSGS__ACTION__DETAIL__SET_FINGERS_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kinova_msgs/action/detail/set_fingers_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'fingers'
#include "kinova_msgs/msg/detail/finger_position__traits.hpp"

namespace kinova_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetFingersPosition_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: fingers
  {
    out << "fingers: ";
    to_flow_style_yaml(msg.fingers, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetFingersPosition_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: fingers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fingers:\n";
    to_block_style_yaml(msg.fingers, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetFingersPosition_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::action::SetFingersPosition_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::action::SetFingersPosition_Goal & msg)
{
  return kinova_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_Goal>()
{
  return "kinova_msgs::action::SetFingersPosition_Goal";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_Goal>()
{
  return "kinova_msgs/action/SetFingersPosition_Goal";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_Goal>
  : std::integral_constant<bool, has_fixed_size<kinova_msgs::msg::FingerPosition>::value> {};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_Goal>
  : std::integral_constant<bool, has_bounded_size<kinova_msgs::msg::FingerPosition>::value> {};

template<>
struct is_message<kinova_msgs::action::SetFingersPosition_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'fingers'
// already included above
// #include "kinova_msgs/msg/detail/finger_position__traits.hpp"

namespace kinova_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetFingersPosition_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: fingers
  {
    out << "fingers: ";
    to_flow_style_yaml(msg.fingers, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetFingersPosition_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: fingers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fingers:\n";
    to_block_style_yaml(msg.fingers, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetFingersPosition_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::action::SetFingersPosition_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::action::SetFingersPosition_Result & msg)
{
  return kinova_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_Result>()
{
  return "kinova_msgs::action::SetFingersPosition_Result";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_Result>()
{
  return "kinova_msgs/action/SetFingersPosition_Result";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_Result>
  : std::integral_constant<bool, has_fixed_size<kinova_msgs::msg::FingerPosition>::value> {};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_Result>
  : std::integral_constant<bool, has_bounded_size<kinova_msgs::msg::FingerPosition>::value> {};

template<>
struct is_message<kinova_msgs::action::SetFingersPosition_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'fingers'
// already included above
// #include "kinova_msgs/msg/detail/finger_position__traits.hpp"

namespace kinova_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetFingersPosition_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: fingers
  {
    out << "fingers: ";
    to_flow_style_yaml(msg.fingers, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetFingersPosition_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: fingers
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fingers:\n";
    to_block_style_yaml(msg.fingers, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetFingersPosition_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::action::SetFingersPosition_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::action::SetFingersPosition_Feedback & msg)
{
  return kinova_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_Feedback>()
{
  return "kinova_msgs::action::SetFingersPosition_Feedback";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_Feedback>()
{
  return "kinova_msgs/action/SetFingersPosition_Feedback";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_Feedback>
  : std::integral_constant<bool, has_fixed_size<kinova_msgs::msg::FingerPosition>::value> {};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_Feedback>
  : std::integral_constant<bool, has_bounded_size<kinova_msgs::msg::FingerPosition>::value> {};

template<>
struct is_message<kinova_msgs::action::SetFingersPosition_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "kinova_msgs/action/detail/set_fingers_position__traits.hpp"

namespace kinova_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetFingersPosition_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetFingersPosition_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetFingersPosition_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::action::SetFingersPosition_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::action::SetFingersPosition_SendGoal_Request & msg)
{
  return kinova_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_SendGoal_Request>()
{
  return "kinova_msgs::action::SetFingersPosition_SendGoal_Request";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_SendGoal_Request>()
{
  return "kinova_msgs/action/SetFingersPosition_SendGoal_Request";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<kinova_msgs::action::SetFingersPosition_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<kinova_msgs::action::SetFingersPosition_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<kinova_msgs::action::SetFingersPosition_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace kinova_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetFingersPosition_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetFingersPosition_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetFingersPosition_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::action::SetFingersPosition_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::action::SetFingersPosition_SendGoal_Response & msg)
{
  return kinova_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_SendGoal_Response>()
{
  return "kinova_msgs::action::SetFingersPosition_SendGoal_Response";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_SendGoal_Response>()
{
  return "kinova_msgs/action/SetFingersPosition_SendGoal_Response";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<kinova_msgs::action::SetFingersPosition_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_SendGoal>()
{
  return "kinova_msgs::action::SetFingersPosition_SendGoal";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_SendGoal>()
{
  return "kinova_msgs/action/SetFingersPosition_SendGoal";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<kinova_msgs::action::SetFingersPosition_SendGoal_Request>::value &&
    has_fixed_size<kinova_msgs::action::SetFingersPosition_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<kinova_msgs::action::SetFingersPosition_SendGoal_Request>::value &&
    has_bounded_size<kinova_msgs::action::SetFingersPosition_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<kinova_msgs::action::SetFingersPosition_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<kinova_msgs::action::SetFingersPosition_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<kinova_msgs::action::SetFingersPosition_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace kinova_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetFingersPosition_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetFingersPosition_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetFingersPosition_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::action::SetFingersPosition_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::action::SetFingersPosition_GetResult_Request & msg)
{
  return kinova_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_GetResult_Request>()
{
  return "kinova_msgs::action::SetFingersPosition_GetResult_Request";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_GetResult_Request>()
{
  return "kinova_msgs/action/SetFingersPosition_GetResult_Request";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<kinova_msgs::action::SetFingersPosition_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "kinova_msgs/action/detail/set_fingers_position__traits.hpp"

namespace kinova_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetFingersPosition_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetFingersPosition_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetFingersPosition_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::action::SetFingersPosition_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::action::SetFingersPosition_GetResult_Response & msg)
{
  return kinova_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_GetResult_Response>()
{
  return "kinova_msgs::action::SetFingersPosition_GetResult_Response";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_GetResult_Response>()
{
  return "kinova_msgs/action/SetFingersPosition_GetResult_Response";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<kinova_msgs::action::SetFingersPosition_Result>::value> {};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<kinova_msgs::action::SetFingersPosition_Result>::value> {};

template<>
struct is_message<kinova_msgs::action::SetFingersPosition_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_GetResult>()
{
  return "kinova_msgs::action::SetFingersPosition_GetResult";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_GetResult>()
{
  return "kinova_msgs/action/SetFingersPosition_GetResult";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<kinova_msgs::action::SetFingersPosition_GetResult_Request>::value &&
    has_fixed_size<kinova_msgs::action::SetFingersPosition_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<kinova_msgs::action::SetFingersPosition_GetResult_Request>::value &&
    has_bounded_size<kinova_msgs::action::SetFingersPosition_GetResult_Response>::value
  >
{
};

template<>
struct is_service<kinova_msgs::action::SetFingersPosition_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<kinova_msgs::action::SetFingersPosition_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<kinova_msgs::action::SetFingersPosition_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "kinova_msgs/action/detail/set_fingers_position__traits.hpp"

namespace kinova_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const SetFingersPosition_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetFingersPosition_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetFingersPosition_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::action::SetFingersPosition_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::action::SetFingersPosition_FeedbackMessage & msg)
{
  return kinova_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::action::SetFingersPosition_FeedbackMessage>()
{
  return "kinova_msgs::action::SetFingersPosition_FeedbackMessage";
}

template<>
inline const char * name<kinova_msgs::action::SetFingersPosition_FeedbackMessage>()
{
  return "kinova_msgs/action/SetFingersPosition_FeedbackMessage";
}

template<>
struct has_fixed_size<kinova_msgs::action::SetFingersPosition_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<kinova_msgs::action::SetFingersPosition_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<kinova_msgs::action::SetFingersPosition_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<kinova_msgs::action::SetFingersPosition_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<kinova_msgs::action::SetFingersPosition_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<kinova_msgs::action::SetFingersPosition>
  : std::true_type
{
};

template<>
struct is_action_goal<kinova_msgs::action::SetFingersPosition_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<kinova_msgs::action::SetFingersPosition_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<kinova_msgs::action::SetFingersPosition_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // KINOVA_MSGS__ACTION__DETAIL__SET_FINGERS_POSITION__TRAITS_HPP_
