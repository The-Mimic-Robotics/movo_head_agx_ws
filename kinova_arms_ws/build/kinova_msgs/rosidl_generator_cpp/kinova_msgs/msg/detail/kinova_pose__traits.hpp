// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kinova_msgs:msg/KinovaPose.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__TRAITS_HPP_
#define KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kinova_msgs/msg/detail/kinova_pose__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace kinova_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const KinovaPose & msg,
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
  const KinovaPose & msg,
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

inline std::string to_yaml(const KinovaPose & msg, bool use_flow_style = false)
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
  const kinova_msgs::msg::KinovaPose & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::msg::KinovaPose & msg)
{
  return kinova_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::msg::KinovaPose>()
{
  return "kinova_msgs::msg::KinovaPose";
}

template<>
inline const char * name<kinova_msgs::msg::KinovaPose>()
{
  return "kinova_msgs/msg/KinovaPose";
}

template<>
struct has_fixed_size<kinova_msgs::msg::KinovaPose>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kinova_msgs::msg::KinovaPose>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kinova_msgs::msg::KinovaPose>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__TRAITS_HPP_
