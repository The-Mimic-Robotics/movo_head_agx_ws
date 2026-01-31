// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:msg/CartesianForce.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__BUILDER_HPP_
#define KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/msg/detail/cartesian_force__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace msg
{

namespace builder
{

class Init_CartesianForce_torque_z
{
public:
  explicit Init_CartesianForce_torque_z(::kinova_msgs::msg::CartesianForce & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::msg::CartesianForce torque_z(::kinova_msgs::msg::CartesianForce::_torque_z_type arg)
  {
    msg_.torque_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::msg::CartesianForce msg_;
};

class Init_CartesianForce_torque_y
{
public:
  explicit Init_CartesianForce_torque_y(::kinova_msgs::msg::CartesianForce & msg)
  : msg_(msg)
  {}
  Init_CartesianForce_torque_z torque_y(::kinova_msgs::msg::CartesianForce::_torque_y_type arg)
  {
    msg_.torque_y = std::move(arg);
    return Init_CartesianForce_torque_z(msg_);
  }

private:
  ::kinova_msgs::msg::CartesianForce msg_;
};

class Init_CartesianForce_torque_x
{
public:
  explicit Init_CartesianForce_torque_x(::kinova_msgs::msg::CartesianForce & msg)
  : msg_(msg)
  {}
  Init_CartesianForce_torque_y torque_x(::kinova_msgs::msg::CartesianForce::_torque_x_type arg)
  {
    msg_.torque_x = std::move(arg);
    return Init_CartesianForce_torque_y(msg_);
  }

private:
  ::kinova_msgs::msg::CartesianForce msg_;
};

class Init_CartesianForce_force_z
{
public:
  explicit Init_CartesianForce_force_z(::kinova_msgs::msg::CartesianForce & msg)
  : msg_(msg)
  {}
  Init_CartesianForce_torque_x force_z(::kinova_msgs::msg::CartesianForce::_force_z_type arg)
  {
    msg_.force_z = std::move(arg);
    return Init_CartesianForce_torque_x(msg_);
  }

private:
  ::kinova_msgs::msg::CartesianForce msg_;
};

class Init_CartesianForce_force_y
{
public:
  explicit Init_CartesianForce_force_y(::kinova_msgs::msg::CartesianForce & msg)
  : msg_(msg)
  {}
  Init_CartesianForce_force_z force_y(::kinova_msgs::msg::CartesianForce::_force_y_type arg)
  {
    msg_.force_y = std::move(arg);
    return Init_CartesianForce_force_z(msg_);
  }

private:
  ::kinova_msgs::msg::CartesianForce msg_;
};

class Init_CartesianForce_force_x
{
public:
  Init_CartesianForce_force_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CartesianForce_force_y force_x(::kinova_msgs::msg::CartesianForce::_force_x_type arg)
  {
    msg_.force_x = std::move(arg);
    return Init_CartesianForce_force_y(msg_);
  }

private:
  ::kinova_msgs::msg::CartesianForce msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::msg::CartesianForce>()
{
  return kinova_msgs::msg::builder::Init_CartesianForce_force_x();
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__MSG__DETAIL__CARTESIAN_FORCE__BUILDER_HPP_
