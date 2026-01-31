// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:srv/SetEndEffectorOffset.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__SET_END_EFFECTOR_OFFSET__BUILDER_HPP_
#define KINOVA_MSGS__SRV__DETAIL__SET_END_EFFECTOR_OFFSET__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/srv/detail/set_end_effector_offset__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace srv
{

namespace builder
{

class Init_SetEndEffectorOffset_Request_offset
{
public:
  explicit Init_SetEndEffectorOffset_Request_offset(::kinova_msgs::srv::SetEndEffectorOffset_Request & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::srv::SetEndEffectorOffset_Request offset(::kinova_msgs::srv::SetEndEffectorOffset_Request::_offset_type arg)
  {
    msg_.offset = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::srv::SetEndEffectorOffset_Request msg_;
};

class Init_SetEndEffectorOffset_Request_status
{
public:
  Init_SetEndEffectorOffset_Request_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetEndEffectorOffset_Request_offset status(::kinova_msgs::srv::SetEndEffectorOffset_Request::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_SetEndEffectorOffset_Request_offset(msg_);
  }

private:
  ::kinova_msgs::srv::SetEndEffectorOffset_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::srv::SetEndEffectorOffset_Request>()
{
  return kinova_msgs::srv::builder::Init_SetEndEffectorOffset_Request_status();
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::srv::SetEndEffectorOffset_Response>()
{
  return ::kinova_msgs::srv::SetEndEffectorOffset_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__SET_END_EFFECTOR_OFFSET__BUILDER_HPP_
