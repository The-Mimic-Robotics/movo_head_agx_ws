// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from kinova_msgs:msg/CartesianForce.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__TRAITS_HPP_
#define KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "kinova_msgs/msg/detail/cartesian_force__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace kinova_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const CartesianForce & msg,
  std::ostream & out)
{
  out << "{";
  // member: force_x
  {
    out << "force_x: ";
    rosidl_generator_traits::value_to_yaml(msg.force_x, out);
    out << ", ";
  }

  // member: force_y
  {
    out << "force_y: ";
    rosidl_generator_traits::value_to_yaml(msg.force_y, out);
    out << ", ";
  }

  // member: force_z
  {
    out << "force_z: ";
    rosidl_generator_traits::value_to_yaml(msg.force_z, out);
    out << ", ";
  }

  // member: torque_x
  {
    out << "torque_x: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_x, out);
    out << ", ";
  }

  // member: torque_y
  {
    out << "torque_y: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_y, out);
    out << ", ";
  }

  // member: torque_z
  {
    out << "torque_z: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CartesianForce & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: force_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_x: ";
    rosidl_generator_traits::value_to_yaml(msg.force_x, out);
    out << "\n";
  }

  // member: force_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_y: ";
    rosidl_generator_traits::value_to_yaml(msg.force_y, out);
    out << "\n";
  }

  // member: force_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "force_z: ";
    rosidl_generator_traits::value_to_yaml(msg.force_z, out);
    out << "\n";
  }

  // member: torque_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "torque_x: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_x, out);
    out << "\n";
  }

  // member: torque_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "torque_y: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_y, out);
    out << "\n";
  }

  // member: torque_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "torque_z: ";
    rosidl_generator_traits::value_to_yaml(msg.torque_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CartesianForce & msg, bool use_flow_style = false)
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
  const kinova_msgs::msg::CartesianForce & msg,
  std::ostream & out, size_t indentation = 0)
{
  kinova_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use kinova_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const kinova_msgs::msg::CartesianForce & msg)
{
  return kinova_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<kinova_msgs::msg::CartesianForce>()
{
  return "kinova_msgs::msg::CartesianForce";
}

template<>
inline const char * name<kinova_msgs::msg::CartesianForce>()
{
  return "kinova_msgs/msg/CartesianForce";
}

template<>
struct has_fixed_size<kinova_msgs::msg::CartesianForce>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<kinova_msgs::msg::CartesianForce>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<kinova_msgs::msg::CartesianForce>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__TRAITS_HPP_
