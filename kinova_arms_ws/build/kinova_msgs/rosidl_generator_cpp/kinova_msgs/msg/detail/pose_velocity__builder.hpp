// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:msg/PoseVelocity.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY__BUILDER_HPP_
#define KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/msg/detail/pose_velocity__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace msg
{

namespace builder
{

class Init_PoseVelocity_twist_angular_z
{
public:
  explicit Init_PoseVelocity_twist_angular_z(::kinova_msgs::msg::PoseVelocity & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::msg::PoseVelocity twist_angular_z(::kinova_msgs::msg::PoseVelocity::_twist_angular_z_type arg)
  {
    msg_.twist_angular_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::msg::PoseVelocity msg_;
};

class Init_PoseVelocity_twist_angular_y
{
public:
  explicit Init_PoseVelocity_twist_angular_y(::kinova_msgs::msg::PoseVelocity & msg)
  : msg_(msg)
  {}
  Init_PoseVelocity_twist_angular_z twist_angular_y(::kinova_msgs::msg::PoseVelocity::_twist_angular_y_type arg)
  {
    msg_.twist_angular_y = std::move(arg);
    return Init_PoseVelocity_twist_angular_z(msg_);
  }

private:
  ::kinova_msgs::msg::PoseVelocity msg_;
};

class Init_PoseVelocity_twist_angular_x
{
public:
  explicit Init_PoseVelocity_twist_angular_x(::kinova_msgs::msg::PoseVelocity & msg)
  : msg_(msg)
  {}
  Init_PoseVelocity_twist_angular_y twist_angular_x(::kinova_msgs::msg::PoseVelocity::_twist_angular_x_type arg)
  {
    msg_.twist_angular_x = std::move(arg);
    return Init_PoseVelocity_twist_angular_y(msg_);
  }

private:
  ::kinova_msgs::msg::PoseVelocity msg_;
};

class Init_PoseVelocity_twist_linear_z
{
public:
  explicit Init_PoseVelocity_twist_linear_z(::kinova_msgs::msg::PoseVelocity & msg)
  : msg_(msg)
  {}
  Init_PoseVelocity_twist_angular_x twist_linear_z(::kinova_msgs::msg::PoseVelocity::_twist_linear_z_type arg)
  {
    msg_.twist_linear_z = std::move(arg);
    return Init_PoseVelocity_twist_angular_x(msg_);
  }

private:
  ::kinova_msgs::msg::PoseVelocity msg_;
};

class Init_PoseVelocity_twist_linear_y
{
public:
  explicit Init_PoseVelocity_twist_linear_y(::kinova_msgs::msg::PoseVelocity & msg)
  : msg_(msg)
  {}
  Init_PoseVelocity_twist_linear_z twist_linear_y(::kinova_msgs::msg::PoseVelocity::_twist_linear_y_type arg)
  {
    msg_.twist_linear_y = std::move(arg);
    return Init_PoseVelocity_twist_linear_z(msg_);
  }

private:
  ::kinova_msgs::msg::PoseVelocity msg_;
};

class Init_PoseVelocity_twist_linear_x
{
public:
  Init_PoseVelocity_twist_linear_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PoseVelocity_twist_linear_y twist_linear_x(::kinova_msgs::msg::PoseVelocity::_twist_linear_x_type arg)
  {
    msg_.twist_linear_x = std::move(arg);
    return Init_PoseVelocity_twist_linear_y(msg_);
  }

private:
  ::kinova_msgs::msg::PoseVelocity msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::msg::PoseVelocity>()
{
  return kinova_msgs::msg::builder::Init_PoseVelocity_twist_linear_x();
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__MSG__DETAIL__POSE_VELOCITY__BUILDER_HPP_
