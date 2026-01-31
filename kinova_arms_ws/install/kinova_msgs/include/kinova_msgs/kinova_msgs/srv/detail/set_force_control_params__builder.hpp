// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:srv/SetForceControlParams.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__BUILDER_HPP_
#define KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/srv/detail/set_force_control_params__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace srv
{

namespace builder
{

class Init_SetForceControlParams_Request_force_max_angular
{
public:
  explicit Init_SetForceControlParams_Request_force_max_angular(::kinova_msgs::srv::SetForceControlParams_Request & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::srv::SetForceControlParams_Request force_max_angular(::kinova_msgs::srv::SetForceControlParams_Request::_force_max_angular_type arg)
  {
    msg_.force_max_angular = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::srv::SetForceControlParams_Request msg_;
};

class Init_SetForceControlParams_Request_force_max_linear
{
public:
  explicit Init_SetForceControlParams_Request_force_max_linear(::kinova_msgs::srv::SetForceControlParams_Request & msg)
  : msg_(msg)
  {}
  Init_SetForceControlParams_Request_force_max_angular force_max_linear(::kinova_msgs::srv::SetForceControlParams_Request::_force_max_linear_type arg)
  {
    msg_.force_max_linear = std::move(arg);
    return Init_SetForceControlParams_Request_force_max_angular(msg_);
  }

private:
  ::kinova_msgs::srv::SetForceControlParams_Request msg_;
};

class Init_SetForceControlParams_Request_force_min_angular
{
public:
  explicit Init_SetForceControlParams_Request_force_min_angular(::kinova_msgs::srv::SetForceControlParams_Request & msg)
  : msg_(msg)
  {}
  Init_SetForceControlParams_Request_force_max_linear force_min_angular(::kinova_msgs::srv::SetForceControlParams_Request::_force_min_angular_type arg)
  {
    msg_.force_min_angular = std::move(arg);
    return Init_SetForceControlParams_Request_force_max_linear(msg_);
  }

private:
  ::kinova_msgs::srv::SetForceControlParams_Request msg_;
};

class Init_SetForceControlParams_Request_force_min_linear
{
public:
  explicit Init_SetForceControlParams_Request_force_min_linear(::kinova_msgs::srv::SetForceControlParams_Request & msg)
  : msg_(msg)
  {}
  Init_SetForceControlParams_Request_force_min_angular force_min_linear(::kinova_msgs::srv::SetForceControlParams_Request::_force_min_linear_type arg)
  {
    msg_.force_min_linear = std::move(arg);
    return Init_SetForceControlParams_Request_force_min_angular(msg_);
  }

private:
  ::kinova_msgs::srv::SetForceControlParams_Request msg_;
};

class Init_SetForceControlParams_Request_damping_angular
{
public:
  explicit Init_SetForceControlParams_Request_damping_angular(::kinova_msgs::srv::SetForceControlParams_Request & msg)
  : msg_(msg)
  {}
  Init_SetForceControlParams_Request_force_min_linear damping_angular(::kinova_msgs::srv::SetForceControlParams_Request::_damping_angular_type arg)
  {
    msg_.damping_angular = std::move(arg);
    return Init_SetForceControlParams_Request_force_min_linear(msg_);
  }

private:
  ::kinova_msgs::srv::SetForceControlParams_Request msg_;
};

class Init_SetForceControlParams_Request_damping_linear
{
public:
  explicit Init_SetForceControlParams_Request_damping_linear(::kinova_msgs::srv::SetForceControlParams_Request & msg)
  : msg_(msg)
  {}
  Init_SetForceControlParams_Request_damping_angular damping_linear(::kinova_msgs::srv::SetForceControlParams_Request::_damping_linear_type arg)
  {
    msg_.damping_linear = std::move(arg);
    return Init_SetForceControlParams_Request_damping_angular(msg_);
  }

private:
  ::kinova_msgs::srv::SetForceControlParams_Request msg_;
};

class Init_SetForceControlParams_Request_inertia_angular
{
public:
  explicit Init_SetForceControlParams_Request_inertia_angular(::kinova_msgs::srv::SetForceControlParams_Request & msg)
  : msg_(msg)
  {}
  Init_SetForceControlParams_Request_damping_linear inertia_angular(::kinova_msgs::srv::SetForceControlParams_Request::_inertia_angular_type arg)
  {
    msg_.inertia_angular = std::move(arg);
    return Init_SetForceControlParams_Request_damping_linear(msg_);
  }

private:
  ::kinova_msgs::srv::SetForceControlParams_Request msg_;
};

class Init_SetForceControlParams_Request_inertia_linear
{
public:
  Init_SetForceControlParams_Request_inertia_linear()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SetForceControlParams_Request_inertia_angular inertia_linear(::kinova_msgs::srv::SetForceControlParams_Request::_inertia_linear_type arg)
  {
    msg_.inertia_linear = std::move(arg);
    return Init_SetForceControlParams_Request_inertia_angular(msg_);
  }

private:
  ::kinova_msgs::srv::SetForceControlParams_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::srv::SetForceControlParams_Request>()
{
  return kinova_msgs::srv::builder::Init_SetForceControlParams_Request_inertia_linear();
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
auto build<::kinova_msgs::srv::SetForceControlParams_Response>()
{
  return ::kinova_msgs::srv::SetForceControlParams_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__SET_FORCE_CONTROL_PARAMS__BUILDER_HPP_
