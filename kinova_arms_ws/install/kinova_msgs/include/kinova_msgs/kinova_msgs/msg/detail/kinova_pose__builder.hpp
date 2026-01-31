// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:msg/KinovaPose.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__BUILDER_HPP_
#define KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/msg/detail/kinova_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace msg
{

namespace builder
{

class Init_KinovaPose_theta_z
{
public:
  explicit Init_KinovaPose_theta_z(::kinova_msgs::msg::KinovaPose & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::msg::KinovaPose theta_z(::kinova_msgs::msg::KinovaPose::_theta_z_type arg)
  {
    msg_.theta_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::msg::KinovaPose msg_;
};

class Init_KinovaPose_theta_y
{
public:
  explicit Init_KinovaPose_theta_y(::kinova_msgs::msg::KinovaPose & msg)
  : msg_(msg)
  {}
  Init_KinovaPose_theta_z theta_y(::kinova_msgs::msg::KinovaPose::_theta_y_type arg)
  {
    msg_.theta_y = std::move(arg);
    return Init_KinovaPose_theta_z(msg_);
  }

private:
  ::kinova_msgs::msg::KinovaPose msg_;
};

class Init_KinovaPose_theta_x
{
public:
  explicit Init_KinovaPose_theta_x(::kinova_msgs::msg::KinovaPose & msg)
  : msg_(msg)
  {}
  Init_KinovaPose_theta_y theta_x(::kinova_msgs::msg::KinovaPose::_theta_x_type arg)
  {
    msg_.theta_x = std::move(arg);
    return Init_KinovaPose_theta_y(msg_);
  }

private:
  ::kinova_msgs::msg::KinovaPose msg_;
};

class Init_KinovaPose_z
{
public:
  explicit Init_KinovaPose_z(::kinova_msgs::msg::KinovaPose & msg)
  : msg_(msg)
  {}
  Init_KinovaPose_theta_x z(::kinova_msgs::msg::KinovaPose::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_KinovaPose_theta_x(msg_);
  }

private:
  ::kinova_msgs::msg::KinovaPose msg_;
};

class Init_KinovaPose_y
{
public:
  explicit Init_KinovaPose_y(::kinova_msgs::msg::KinovaPose & msg)
  : msg_(msg)
  {}
  Init_KinovaPose_z y(::kinova_msgs::msg::KinovaPose::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_KinovaPose_z(msg_);
  }

private:
  ::kinova_msgs::msg::KinovaPose msg_;
};

class Init_KinovaPose_x
{
public:
  Init_KinovaPose_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_KinovaPose_y x(::kinova_msgs::msg::KinovaPose::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_KinovaPose_y(msg_);
  }

private:
  ::kinova_msgs::msg::KinovaPose msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::msg::KinovaPose>()
{
  return kinova_msgs::msg::builder::Init_KinovaPose_x();
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__MSG__DETAIL__KINOVA_POSE__BUILDER_HPP_
