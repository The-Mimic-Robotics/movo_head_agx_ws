// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kinova_msgs:msg/PoseVelocity.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY__TRAITS_HPP_
#define KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kinova_msgs/msg/detail/pose_velocity__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace kinova_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const PoseVelocity & msg,
  std::ostream & out)
{
  out << "{";
  // member: twist_linear_x
  {
    out << "twist_linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_linear_x, out);
    out << ", ";
  }

  // member: twist_linear_y
  {
    out << "twist_linear_y: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_linear_y, out);
    out << ", ";
  }

  // member: twist_linear_z
  {
    out << "twist_linear_z: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_linear_z, out);
    out << ", ";
  }

  // member: twist_angular_x
  {
    out << "twist_angular_x: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_angular_x, out);
    out << ", ";
  }

  // member: twist_angular_y
  {
    out << "twist_angular_y: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_angular_y, out);
    out << ", ";
  }

  // member: twist_angular_z
  {
    out << "twist_angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_angular_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const PoseVelocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: twist_linear_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_linear_x: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_linear_x, out);
    out << "\n";
  }

  // member: twist_linear_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_linear_y: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_linear_y, out);
    out << "\n";
  }

  // member: twist_linear_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_linear_z: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_linear_z, out);
    out << "\n";
  }

  // member: twist_angular_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_angular_x: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_angular_x, out);
    out << "\n";
  }

  // member: twist_angular_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_angular_y: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_angular_y, out);
    out << "\n";
  }

  // member: twist_angular_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "twist_angular_z: ";
    rosidl_generator_traits::value_to_yaml(msg.twist_angular_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const PoseVelocity & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace kinova_msgs

namespace rosidl_generator_traits
{

[[deprecated("use kinova_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const kinova_msgs::msg::PoseVelocity & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::msg::PoseVelocity & msg)
{
  return kinova_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::msg::PoseVelocity>()
{
  return "kinova_msgs::msg::PoseVelocity";
}

template<>
inline const char * name<kinova_msgs::msg::PoseVelocity>()
{
  return "kinova_msgs/msg/PoseVelocity";
}

template<>
struct has_fixed_size<kinova_msgs::msg::PoseVelocity>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kinova_msgs::msg::PoseVelocity>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kinova_msgs::msg::PoseVelocity>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY__TRAITS_HPP_
