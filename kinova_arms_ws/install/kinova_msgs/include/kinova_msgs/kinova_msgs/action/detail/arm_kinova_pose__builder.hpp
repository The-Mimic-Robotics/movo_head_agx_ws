// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from kinova_msgs:action/ArmKinovaPose.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__ACTION__DETAIL__ARM_KINOVA_POSE__BUILDER_HPP_
#define KINOVA_MSGS__ACTION__DETAIL__ARM_KINOVA_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "kinova_msgs/action/detail/arm_kinova_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace kinova_msgs
{

namespace action
{

namespace builder
{

class Init_ArmKinovaPose_Goal_kinova_pose
{
public:
  Init_ArmKinovaPose_Goal_kinova_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kinova_msgs::action::ArmKinovaPose_Goal kinova_pose(::kinova_msgs::action::ArmKinovaPose_Goal::_kinova_pose_type arg)
  {
    msg_.kinova_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::action::ArmKinovaPose_Goal>()
{
  return kinova_msgs::action::builder::Init_ArmKinovaPose_Goal_kinova_pose();
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace action
{

namespace builder
{

class Init_ArmKinovaPose_Result_kinova_pose
{
public:
  Init_ArmKinovaPose_Result_kinova_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kinova_msgs::action::ArmKinovaPose_Result kinova_pose(::kinova_msgs::action::ArmKinovaPose_Result::_kinova_pose_type arg)
  {
    msg_.kinova_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::action::ArmKinovaPose_Result>()
{
  return kinova_msgs::action::builder::Init_ArmKinovaPose_Result_kinova_pose();
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace action
{

namespace builder
{

class Init_ArmKinovaPose_Feedback_kinova_pose
{
public:
  Init_ArmKinovaPose_Feedback_kinova_pose()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kinova_msgs::action::ArmKinovaPose_Feedback kinova_pose(::kinova_msgs::action::ArmKinovaPose_Feedback::_kinova_pose_type arg)
  {
    msg_.kinova_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::action::ArmKinovaPose_Feedback>()
{
  return kinova_msgs::action::builder::Init_ArmKinovaPose_Feedback_kinova_pose();
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace action
{

namespace builder
{

class Init_ArmKinovaPose_SendGoal_Request_goal
{
public:
  explicit Init_ArmKinovaPose_SendGoal_Request_goal(::kinova_msgs::action::ArmKinovaPose_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::action::ArmKinovaPose_SendGoal_Request goal(::kinova_msgs::action::ArmKinovaPose_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_SendGoal_Request msg_;
};

class Init_ArmKinovaPose_SendGoal_Request_goal_id
{
public:
  Init_ArmKinovaPose_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmKinovaPose_SendGoal_Request_goal goal_id(::kinova_msgs::action::ArmKinovaPose_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ArmKinovaPose_SendGoal_Request_goal(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::action::ArmKinovaPose_SendGoal_Request>()
{
  return kinova_msgs::action::builder::Init_ArmKinovaPose_SendGoal_Request_goal_id();
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace action
{

namespace builder
{

class Init_ArmKinovaPose_SendGoal_Response_stamp
{
public:
  explicit Init_ArmKinovaPose_SendGoal_Response_stamp(::kinova_msgs::action::ArmKinovaPose_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::action::ArmKinovaPose_SendGoal_Response stamp(::kinova_msgs::action::ArmKinovaPose_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_SendGoal_Response msg_;
};

class Init_ArmKinovaPose_SendGoal_Response_accepted
{
public:
  Init_ArmKinovaPose_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmKinovaPose_SendGoal_Response_stamp accepted(::kinova_msgs::action::ArmKinovaPose_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_ArmKinovaPose_SendGoal_Response_stamp(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::action::ArmKinovaPose_SendGoal_Response>()
{
  return kinova_msgs::action::builder::Init_ArmKinovaPose_SendGoal_Response_accepted();
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace action
{

namespace builder
{

class Init_ArmKinovaPose_GetResult_Request_goal_id
{
public:
  Init_ArmKinovaPose_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::kinova_msgs::action::ArmKinovaPose_GetResult_Request goal_id(::kinova_msgs::action::ArmKinovaPose_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::action::ArmKinovaPose_GetResult_Request>()
{
  return kinova_msgs::action::builder::Init_ArmKinovaPose_GetResult_Request_goal_id();
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace action
{

namespace builder
{

class Init_ArmKinovaPose_GetResult_Response_result
{
public:
  explicit Init_ArmKinovaPose_GetResult_Response_result(::kinova_msgs::action::ArmKinovaPose_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::action::ArmKinovaPose_GetResult_Response result(::kinova_msgs::action::ArmKinovaPose_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_GetResult_Response msg_;
};

class Init_ArmKinovaPose_GetResult_Response_status
{
public:
  Init_ArmKinovaPose_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmKinovaPose_GetResult_Response_result status(::kinova_msgs::action::ArmKinovaPose_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_ArmKinovaPose_GetResult_Response_result(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::action::ArmKinovaPose_GetResult_Response>()
{
  return kinova_msgs::action::builder::Init_ArmKinovaPose_GetResult_Response_status();
}

}  // namespace kinova_msgs


namespace kinova_msgs
{

namespace action
{

namespace builder
{

class Init_ArmKinovaPose_FeedbackMessage_feedback
{
public:
  explicit Init_ArmKinovaPose_FeedbackMessage_feedback(::kinova_msgs::action::ArmKinovaPose_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::kinova_msgs::action::ArmKinovaPose_FeedbackMessage feedback(::kinova_msgs::action::ArmKinovaPose_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_FeedbackMessage msg_;
};

class Init_ArmKinovaPose_FeedbackMessage_goal_id
{
public:
  Init_ArmKinovaPose_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArmKinovaPose_FeedbackMessage_feedback goal_id(::kinova_msgs::action::ArmKinovaPose_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_ArmKinovaPose_FeedbackMessage_feedback(msg_);
  }

private:
  ::kinova_msgs::action::ArmKinovaPose_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::kinova_msgs::action::ArmKinovaPose_FeedbackMessage>()
{
  return kinova_msgs::action::builder::Init_ArmKinovaPose_FeedbackMessage_goal_id();
}

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__ACTION__DETAIL__ARM_KINOVA_POSE__BUILDER_HPP_
