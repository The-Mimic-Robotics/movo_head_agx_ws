// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:srv/Start.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__START__BUILDER_HPP_
#define KINOVA_MSGS__SRV__DETAIL__START__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/srv/detail/start__struct.hpp"
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
auto build<::kinova_msgs::srv::Start_Request>()
{
  return ::kinova_msgs::srv::Start_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace srv
{

namespace builder
{

class Init_Start_Response_start_result
{
public:
  Init_Start_Response_start_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kinova_msgs::srv::Start_Response start_result(::kinova_msgs::srv::Start_Response::_start_result_type arg)
  {
    msg_.start_result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::srv::Start_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::srv::Start_Response>()
{
  return kinova_msgs::srv::builder::Init_Start_Response_start_result();
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__START__BUILDER_HPP_
