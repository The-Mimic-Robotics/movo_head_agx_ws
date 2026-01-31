// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:srv/SetNullSpaceModeState.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__SET_NULL_SPACE_MODE_STATE__BUILDER_HPP_
#define KINOVA_MSGS__SRV__DETAIL__SET_NULL_SPACE_MODE_STATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/srv/detail/set_null_space_mode_state__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace srv
{

namespace builder
{

class Init_SetNullSpaceModeState_Request_state
{
public:
  Init_SetNullSpaceModeState_Request_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kinova_msgs::srv::SetNullSpaceModeState_Request state(::kinova_msgs::srv::SetNullSpaceModeState_Request::_state_type arg)
  {
    msg_.state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::srv::SetNullSpaceModeState_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::srv::SetNullSpaceModeState_Request>()
{
  return kinova_msgs::srv::builder::Init_SetNullSpaceModeState_Request_state();
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
auto build<::kinova_msgs::srv::SetNullSpaceModeState_Response>()
{
  return ::kinova_msgs::srv::SetNullSpaceModeState_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__SET_NULL_SPACE_MODE_STATE__BUILDER_HPP_
