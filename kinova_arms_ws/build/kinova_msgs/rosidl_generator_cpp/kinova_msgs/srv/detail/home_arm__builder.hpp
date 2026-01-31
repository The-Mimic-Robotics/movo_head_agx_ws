// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:srv/HomeArm.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__HOME_ARM__BUILDER_HPP_
#define KINOVA_MSGS__SRV__DETAIL__HOME_ARM__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/srv/detail/home_arm__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::srv::HomeArm_Request>()
{
  return ::kinova_msgs::srv::HomeArm_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace srv
{

namespace builder
{

class Init_HomeArm_Response_homearm_result
{
public:
  Init_HomeArm_Response_homearm_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kinova_msgs::srv::HomeArm_Response homearm_result(::kinova_msgs::srv::HomeArm_Response::_homearm_result_type arg)
  {
    msg_.homearm_result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::srv::HomeArm_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::srv::HomeArm_Response>()
{
  return kinova_msgs::srv::builder::Init_HomeArm_Response_homearm_result();
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__HOME_ARM__BUILDER_HPP_
