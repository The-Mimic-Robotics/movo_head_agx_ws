// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:msg/FingerPosition.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__MSG__DETAIL__FINGER_POSITION__BUILDER_HPP_
#define KINOVA_MSGS__MSG__DETAIL__FINGER_POSITION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/msg/detail/finger_position__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace msg
{

namespace builder
{

class Init_FingerPosition_finger3
{
public:
  explicit Init_FingerPosition_finger3(::kinova_msgs::msg::FingerPosition & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::msg::FingerPosition finger3(::kinova_msgs::msg::FingerPosition::_finger3_type arg)
  {
    msg_.finger3 = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::msg::FingerPosition msg_;
};

class Init_FingerPosition_finger2
{
public:
  explicit Init_FingerPosition_finger2(::kinova_msgs::msg::FingerPosition & msg)
  : msg_(msg)
  {}
  Init_FingerPosition_finger3 finger2(::kinova_msgs::msg::FingerPosition::_finger2_type arg)
  {
    msg_.finger2 = std::move(arg);
    return Init_FingerPosition_finger3(msg_);
  }

private:
  ::kinova_msgs::msg::FingerPosition msg_;
};

class Init_FingerPosition_finger1
{
public:
  Init_FingerPosition_finger1()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FingerPosition_finger2 finger1(::kinova_msgs::msg::FingerPosition::_finger1_type arg)
  {
    msg_.finger1 = std::move(arg);
    return Init_FingerPosition_finger2(msg_);
  }

private:
  ::kinova_msgs::msg::FingerPosition msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::msg::FingerPosition>()
{
  return kinova_msgs::msg::builder::Init_FingerPosition_finger1();
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__MSG__DETAIL__FINGER_POSITION__BUILDER_HPP_
