// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:msg/JointAngles.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__JOINT_ANGLES__BUILDER_HPP_
#define KINOVA_MSGS__MSG__DETAIL__JOINT_ANGLES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/msg/detail/joint_angles__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace msg
{

namespace builder
{

class Init_JointAngles_joint7
{
public:
  explicit Init_JointAngles_joint7(::kinova_msgs::msg::JointAngles & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::msg::JointAngles joint7(::kinova_msgs::msg::JointAngles::_joint7_type arg)
  {
    msg_.joint7 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::msg::JointAngles msg_;
};

class Init_JointAngles_joint6
{
public:
  explicit Init_JointAngles_joint6(::kinova_msgs::msg::JointAngles & msg)
  : msg_(msg)
  {}
  Init_JointAngles_joint7 joint6(::kinova_msgs::msg::JointAngles::_joint6_type arg)
  {
    msg_.joint6 = std::move(arg);
    return Init_JointAngles_joint7(msg_);
  }

private:
  ::kinova_msgs::msg::JointAngles msg_;
};

class Init_JointAngles_joint5
{
public:
  explicit Init_JointAngles_joint5(::kinova_msgs::msg::JointAngles & msg)
  : msg_(msg)
  {}
  Init_JointAngles_joint6 joint5(::kinova_msgs::msg::JointAngles::_joint5_type arg)
  {
    msg_.joint5 = std::move(arg);
    return Init_JointAngles_joint6(msg_);
  }

private:
  ::kinova_msgs::msg::JointAngles msg_;
};

class Init_JointAngles_joint4
{
public:
  explicit Init_JointAngles_joint4(::kinova_msgs::msg::JointAngles & msg)
  : msg_(msg)
  {}
  Init_JointAngles_joint5 joint4(::kinova_msgs::msg::JointAngles::_joint4_type arg)
  {
    msg_.joint4 = std::move(arg);
    return Init_JointAngles_joint5(msg_);
  }

private:
  ::kinova_msgs::msg::JointAngles msg_;
};

class Init_JointAngles_joint3
{
public:
  explicit Init_JointAngles_joint3(::kinova_msgs::msg::JointAngles & msg)
  : msg_(msg)
  {}
  Init_JointAngles_joint4 joint3(::kinova_msgs::msg::JointAngles::_joint3_type arg)
  {
    msg_.joint3 = std::move(arg);
    return Init_JointAngles_joint4(msg_);
  }

private:
  ::kinova_msgs::msg::JointAngles msg_;
};

class Init_JointAngles_joint2
{
public:
  explicit Init_JointAngles_joint2(::kinova_msgs::msg::JointAngles & msg)
  : msg_(msg)
  {}
  Init_JointAngles_joint3 joint2(::kinova_msgs::msg::JointAngles::_joint2_type arg)
  {
    msg_.joint2 = std::move(arg);
    return Init_JointAngles_joint3(msg_);
  }

private:
  ::kinova_msgs::msg::JointAngles msg_;
};

class Init_JointAngles_joint1
{
public:
  Init_JointAngles_joint1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointAngles_joint2 joint1(::kinova_msgs::msg::JointAngles::_joint1_type arg)
  {
    msg_.joint1 = std::move(arg);
    return Init_JointAngles_joint2(msg_);
  }

private:
  ::kinova_msgs::msg::JointAngles msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::msg::JointAngles>()
{
  return kinova_msgs::msg::builder::Init_JointAngles_joint1();
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__MSG__DETAIL__JOINT_ANGLES__BUILDER_HPP_
