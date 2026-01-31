// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kinova_msgs:srv/AddPoseToCartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__ADD_POSE_TO_CARTESIAN_TRAJECTORY__TRAITS_HPP_
#define KINOVA_MSGS__SRV__DETAIL__ADD_POSE_TO_CARTESIAN_TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kinova_msgs/srv/detail/add_pose_to_cartesian_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace kinova_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddPoseToCartesianTrajectory_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: theta_x
  {
    out << "theta_x: ";
    rosidl_generator_traits::value_to_yaml(msg.theta_x, out);
    out << ", ";
  }

  // member: theta_y
  {
    out << "theta_y: ";
    rosidl_generator_traits::value_to_yaml(msg.theta_y, out);
    out << ", ";
  }

  // member: theta_z
  {
    out << "theta_z: ";
    rosidl_generator_traits::value_to_yaml(msg.theta_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddPoseToCartesianTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: theta_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta_x: ";
    rosidl_generator_traits::value_to_yaml(msg.theta_x, out);
    out << "\n";
  }

  // member: theta_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta_y: ";
    rosidl_generator_traits::value_to_yaml(msg.theta_y, out);
    out << "\n";
  }

  // member: theta_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta_z: ";
    rosidl_generator_traits::value_to_yaml(msg.theta_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddPoseToCartesianTrajectory_Request & msg, bool use_flow_style = false)
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
  const kinova_msgs::srv::AddPoseToCartesianTrajectory_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::srv::AddPoseToCartesianTrajectory_Request & msg)
{
  return kinova_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request>()
{
  return "kinova_msgs::srv::AddPoseToCartesianTrajectory_Request";
}

template<>
inline const char * name<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request>()
{
  return "kinova_msgs/srv/AddPoseToCartesianTrajectory_Request";
}

template<>
struct has_fixed_size<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace kinova_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const AddPoseToCartesianTrajectory_Response & msg,
  std::ostream & out)
{
  (void)msg;
  out << "null";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const AddPoseToCartesianTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  (void)msg;
  (void)indentation;
  out << "null\n";
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const AddPoseToCartesianTrajectory_Response & msg, bool use_flow_style = false)
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
  const kinova_msgs::srv::AddPoseToCartesianTrajectory_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::srv::AddPoseToCartesianTrajectory_Response & msg)
{
  return kinova_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response>()
{
  return "kinova_msgs::srv::AddPoseToCartesianTrajectory_Response";
}

template<>
inline const char * name<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response>()
{
  return "kinova_msgs/srv/AddPoseToCartesianTrajectory_Response";
}

template<>
struct has_fixed_size<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<kinova_msgs::srv::AddPoseToCartesianTrajectory>()
{
  return "kinova_msgs::srv::AddPoseToCartesianTrajectory";
}

template<>
inline const char * name<kinova_msgs::srv::AddPoseToCartesianTrajectory>()
{
  return "kinova_msgs/srv/AddPoseToCartesianTrajectory";
}

template<>
struct has_fixed_size<kinova_msgs::srv::AddPoseToCartesianTrajectory>
  : std::integral_constant<
    bool,
    has_fixed_size<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request>::value &&
    has_fixed_size<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response>::value
  >
{
};

template<>
struct has_bounded_size<kinova_msgs::srv::AddPoseToCartesianTrajectory>
  : std::integral_constant<
    bool,
    has_bounded_size<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request>::value &&
    has_bounded_size<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response>::value
  >
{
};

template<>
struct is_service<kinova_msgs::srv::AddPoseToCartesianTrajectory>
  : std::true_type
{
};

template<>
struct is_service_request<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request>
  : std::true_type
{
};

template<>
struct is_service_response<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // KINOVA_MSGS__SRV__DETAIL__ADD_POSE_TO_CARTESIAN_TRAJECTORY__TRAITS_HPP_
