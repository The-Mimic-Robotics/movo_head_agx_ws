// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kinova_msgs:srv/SetForceControlParams.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__TRAITS_HPP_
#define KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kinova_msgs/srv/detail/set_force_control_params__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'inertia_linear'
// Member 'inertia_angular'
// Member 'damping_linear'
// Member 'damping_angular'
// Member 'force_min_linear'
// Member 'force_min_angular'
// Member 'force_max_linear'
// Member 'force_max_angular'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace kinova_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetForceControlParams_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: inertia_linear
  {
    out << "inertia_linear: ";
    to_flow_style_yaml(msg.inertia_linear, out);
    out << ", ";
  }

  // member: inertia_angular
  {
    out << "inertia_angular: ";
    to_flow_style_yaml(msg.inertia_angular, out);
    out << ", ";
  }

  // member: damping_linear
  {
    out << "damping_linear: ";
    to_flow_style_yaml(msg.damping_linear, out);
    out << ", ";
  }

  // member: damping_angular
  {
    out << "damping_angular: ";
    to_flow_style_yaml(msg.damping_angular, out);
    out << ", ";
  }

  // member: force_min_linear
  {
    out << "force_min_linear: ";
    to_flow_style_yaml(msg.force_min_linear, out);
    out << ", ";
  }

  // member: force_min_angular
  {
    out << "force_min_angular: ";
    to_flow_style_yaml(msg.force_min_angular, out);
    out << ", ";
  }

  // member: force_max_linear
  {
    out << "force_max_linear: ";
    to_flow_style_yaml(msg.force_max_linear, out);
    out << ", ";
  }

  // member: force_max_angular
  {
    out << "force_max_angular: ";
    to_flow_style_yaml(msg.force_max_angular, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetForceControlParams_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: inertia_linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inertia_linear:\n";
    to_block_style_yaml(msg.inertia_linear, out, indentation + 2);
  }

  // member: inertia_angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inertia_angular:\n";
    to_block_style_yaml(msg.inertia_angular, out, indentation + 2);
  }

  // member: damping_linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "damping_linear:\n";
    to_block_style_yaml(msg.damping_linear, out, indentation + 2);
  }

  // member: damping_angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "damping_angular:\n";
    to_block_style_yaml(msg.damping_angular, out, indentation + 2);
  }

  // member: force_min_linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_min_linear:\n";
    to_block_style_yaml(msg.force_min_linear, out, indentation + 2);
  }

  // member: force_min_angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_min_angular:\n";
    to_block_style_yaml(msg.force_min_angular, out, indentation + 2);
  }

  // member: force_max_linear
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_max_linear:\n";
    to_block_style_yaml(msg.force_max_linear, out, indentation + 2);
  }

  // member: force_max_angular
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_max_angular:\n";
    to_block_style_yaml(msg.force_max_angular, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetForceControlParams_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::srv::SetForceControlParams_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::srv::SetForceControlParams_Request & msg)
{
  return kinova_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::srv::SetForceControlParams_Request>()
{
  return "kinova_msgs::srv::SetForceControlParams_Request";
}

template<>
inline const char * name<kinova_msgs::srv::SetForceControlParams_Request>()
{
  return "kinova_msgs/srv/SetForceControlParams_Request";
}

template<>
struct has_fixed_size<kinova_msgs::srv::SetForceControlParams_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct has_bounded_size<kinova_msgs::srv::SetForceControlParams_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Vector3>::value> {};

template<>
struct is_message<kinova_msgs::srv::SetForceControlParams_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace kinova_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetForceControlParams_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetForceControlParams_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetForceControlParams_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::srv::SetForceControlParams_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::srv::SetForceControlParams_Response & msg)
{
  return kinova_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::srv::SetForceControlParams_Response>()
{
  return "kinova_msgs::srv::SetForceControlParams_Response";
}

template<>
inline const char * name<kinova_msgs::srv::SetForceControlParams_Response>()
{
  return "kinova_msgs/srv/SetForceControlParams_Response";
}

template<>
struct has_fixed_size<kinova_msgs::srv::SetForceControlParams_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kinova_msgs::srv::SetForceControlParams_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kinova_msgs::srv::SetForceControlParams_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kinova_msgs::srv::SetForceControlParams>()
{
  return "kinova_msgs::srv::SetForceControlParams";
}

template<>
inline const char * name<kinova_msgs::srv::SetForceControlParams>()
{
  return "kinova_msgs/srv/SetForceControlParams";
}

template<>
struct has_fixed_size<kinova_msgs::srv::SetForceControlParams>
  : std::integral_constant<
    bool,
    has_fixed_size<kinova_msgs::srv::SetForceControlParams_Request>::value &&
    has_fixed_size<kinova_msgs::srv::SetForceControlParams_Response>::value
  >
{
};

template<>
struct has_bounded_size<kinova_msgs::srv::SetForceControlParams>
  : std::integral_constant<
    bool,
    has_bounded_size<kinova_msgs::srv::SetForceControlParams_Request>::value &&
    has_bounded_size<kinova_msgs::srv::SetForceControlParams_Response>::value
  >
{
};

template<>
struct is_service<kinova_msgs::srv::SetForceControlParams>
  : std::true_type
{
};

template<>
struct is_service_request<kinova_msgs::srv::SetForceControlParams_Request>
  : std::true_type
{
};

template<>
struct is_service_response<kinova_msgs::srv::SetForceControlParams_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__TRAITS_HPP_
