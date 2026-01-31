// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kinova_msgs:msg/FingerPosition.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__FINGER_POSITION__TRAITS_HPP_
#define KINOVA_MSGS__MSG__DETAIL__FINGER_POSITION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kinova_msgs/msg/detail/finger_position__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace kinova_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FingerPosition & msg,
  std::ostream & out)
{
  out << "{";
  // member: finger1
  {
    out << "finger1: ";
    rosidl_generator_traits::value_to_yaml(msg.finger1, out);
    out << ", ";
  }

  // member: finger2
  {
    out << "finger2: ";
    rosidl_generator_traits::value_to_yaml(msg.finger2, out);
    out << ", ";
  }

  // member: finger3
  {
    out << "finger3: ";
    rosidl_generator_traits::value_to_yaml(msg.finger3, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FingerPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: finger1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "finger1: ";
    rosidl_generator_traits::value_to_yaml(msg.finger1, out);
    out << "\n";
  }

  // member: finger2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "finger2: ";
    rosidl_generator_traits::value_to_yaml(msg.finger2, out);
    out << "\n";
  }

  // member: finger3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "finger3: ";
    rosidl_generator_traits::value_to_yaml(msg.finger3, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FingerPosition & msg, bool use_flow_style = false)
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
  const kinova_msgs::msg::FingerPosition & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::msg::FingerPosition & msg)
{
  return kinova_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::msg::FingerPosition>()
{
  return "kinova_msgs::msg::FingerPosition";
}

template<>
inline const char * name<kinova_msgs::msg::FingerPosition>()
{
  return "kinova_msgs/msg/FingerPosition";
}

template<>
struct has_fixed_size<kinova_msgs::msg::FingerPosition>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kinova_msgs::msg::FingerPosition>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kinova_msgs::msg::FingerPosition>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KINOVA_MSGS__MSG__DETAIL__FINGER_POSITION__TRAITS_HPP_
