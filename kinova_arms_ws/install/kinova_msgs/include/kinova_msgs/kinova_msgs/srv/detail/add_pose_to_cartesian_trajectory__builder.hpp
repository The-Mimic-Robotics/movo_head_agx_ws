// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:srv/AddPoseToCartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__ADD_POSE_TO_CARTESIAN_TRAJECTORY__BUILDER_HPP_
#define KINOVA_MSGS__SRV__DETAIL__ADD_POSE_TO_CARTESIAN_TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/srv/detail/add_pose_to_cartesian_trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace srv
{

namespace builder
{

class Init_AddPoseToCartesianTrajectory_Request_theta_z
{
public:
  explicit Init_AddPoseToCartesianTrajectory_Request_theta_z(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request theta_z(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request::_theta_z_type arg)
  {
    msg_.theta_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request msg_;
};

class Init_AddPoseToCartesianTrajectory_Request_theta_y
{
public:
  explicit Init_AddPoseToCartesianTrajectory_Request_theta_y(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_AddPoseToCartesianTrajectory_Request_theta_z theta_y(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request::_theta_y_type arg)
  {
    msg_.theta_y = std::move(arg);
    return Init_AddPoseToCartesianTrajectory_Request_theta_z(msg_);
  }

private:
  ::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request msg_;
};

class Init_AddPoseToCartesianTrajectory_Request_theta_x
{
public:
  explicit Init_AddPoseToCartesianTrajectory_Request_theta_x(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_AddPoseToCartesianTrajectory_Request_theta_y theta_x(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request::_theta_x_type arg)
  {
    msg_.theta_x = std::move(arg);
    return Init_AddPoseToCartesianTrajectory_Request_theta_y(msg_);
  }

private:
  ::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request msg_;
};

class Init_AddPoseToCartesianTrajectory_Request_z
{
public:
  explicit Init_AddPoseToCartesianTrajectory_Request_z(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_AddPoseToCartesianTrajectory_Request_theta_x z(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_AddPoseToCartesianTrajectory_Request_theta_x(msg_);
  }

private:
  ::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request msg_;
};

class Init_AddPoseToCartesianTrajectory_Request_y
{
public:
  explicit Init_AddPoseToCartesianTrajectory_Request_y(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request & msg)
  : msg_(msg)
  {}
  Init_AddPoseToCartesianTrajectory_Request_z y(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_AddPoseToCartesianTrajectory_Request_z(msg_);
  }

private:
  ::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request msg_;
};

class Init_AddPoseToCartesianTrajectory_Request_x
{
public:
  Init_AddPoseToCartesianTrajectory_Request_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddPoseToCartesianTrajectory_Request_y x(::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_AddPoseToCartesianTrajectory_Request_y(msg_);
  }

private:
  ::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::srv::AddPoseToCartesianTrajectory_Request>()
{
  return kinova_msgs::srv::builder::Init_AddPoseToCartesianTrajectory_Request_x();
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
auto build<::kinova_msgs::srv::AddPoseToCartesianTrajectory_Response>()
{
  return ::kinova_msgs::srv::AddPoseToCartesianTrajectory_Response(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__ADD_POSE_TO_CARTESIAN_TRAJECTORY__BUILDER_HPP_
