// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinova_msgs:action/SetFingersPosition.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__ACTION__DETAIL__SET_FINGERS_POSITION__STRUCT_HPP_
#define KINOVA_MSGS__ACTION__DETAIL__SET_FINGERS_POSITION__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'fingers'
#include "kinova_msgs/msg/detail/finger_position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_Goal __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_Goal __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SetFingersPosition_Goal_
{
  using Type = SetFingersPosition_Goal_<ContainerAllocator>;

  explicit SetFingersPosition_Goal_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fingers(_init)
  {
    (void)_init;
  }

  explicit SetFingersPosition_Goal_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fingers(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _fingers_type =
    kinova_msgs::msg::FingerPosition_<ContainerAllocator>;
  _fingers_type fingers;

  // setters for named parameter idiom
  Type & set__fingers(
    const kinova_msgs::msg::FingerPosition_<ContainerAllocator> & _arg)
  {
    this->fingers = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_Goal
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_Goal
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFingersPosition_Goal_ & other) const
  {
    if (this->fingers != other.fingers) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFingersPosition_Goal_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFingersPosition_Goal_

// alias to use template instance with default allocator
using SetFingersPosition_Goal =
  kinova_msgs::action::SetFingersPosition_Goal_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace kinova_msgs


// Include directives for member types
// Member 'fingers'
// already included above
// #include "kinova_msgs/msg/detail/finger_position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_Result __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_Result __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SetFingersPosition_Result_
{
  using Type = SetFingersPosition_Result_<ContainerAllocator>;

  explicit SetFingersPosition_Result_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fingers(_init)
  {
    (void)_init;
  }

  explicit SetFingersPosition_Result_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fingers(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _fingers_type =
    kinova_msgs::msg::FingerPosition_<ContainerAllocator>;
  _fingers_type fingers;

  // setters for named parameter idiom
  Type & set__fingers(
    const kinova_msgs::msg::FingerPosition_<ContainerAllocator> & _arg)
  {
    this->fingers = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_Result
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_Result
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFingersPosition_Result_ & other) const
  {
    if (this->fingers != other.fingers) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFingersPosition_Result_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFingersPosition_Result_

// alias to use template instance with default allocator
using SetFingersPosition_Result =
  kinova_msgs::action::SetFingersPosition_Result_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace kinova_msgs


// Include directives for member types
// Member 'fingers'
// already included above
// #include "kinova_msgs/msg/detail/finger_position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_Feedback __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_Feedback __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SetFingersPosition_Feedback_
{
  using Type = SetFingersPosition_Feedback_<ContainerAllocator>;

  explicit SetFingersPosition_Feedback_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fingers(_init)
  {
    (void)_init;
  }

  explicit SetFingersPosition_Feedback_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : fingers(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _fingers_type =
    kinova_msgs::msg::FingerPosition_<ContainerAllocator>;
  _fingers_type fingers;

  // setters for named parameter idiom
  Type & set__fingers(
    const kinova_msgs::msg::FingerPosition_<ContainerAllocator> & _arg)
  {
    this->fingers = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_Feedback
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_Feedback
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFingersPosition_Feedback_ & other) const
  {
    if (this->fingers != other.fingers) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFingersPosition_Feedback_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFingersPosition_Feedback_

// alias to use template instance with default allocator
using SetFingersPosition_Feedback =
  kinova_msgs::action::SetFingersPosition_Feedback_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace kinova_msgs


// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'goal'
#include "kinova_msgs/action/detail/set_fingers_position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_SendGoal_Request __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_SendGoal_Request __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SetFingersPosition_SendGoal_Request_
{
  using Type = SetFingersPosition_SendGoal_Request_<ContainerAllocator>;

  explicit SetFingersPosition_SendGoal_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    goal(_init)
  {
    (void)_init;
  }

  explicit SetFingersPosition_SendGoal_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    goal(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _goal_type =
    kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator>;
  _goal_type goal;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__goal(
    const kinova_msgs::action::SetFingersPosition_Goal_<ContainerAllocator> & _arg)
  {
    this->goal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_SendGoal_Request
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_SendGoal_Request
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFingersPosition_SendGoal_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->goal != other.goal) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFingersPosition_SendGoal_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFingersPosition_SendGoal_Request_

// alias to use template instance with default allocator
using SetFingersPosition_SendGoal_Request =
  kinova_msgs::action::SetFingersPosition_SendGoal_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace kinova_msgs


// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_SendGoal_Response __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_SendGoal_Response __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SetFingersPosition_SendGoal_Response_
{
  using Type = SetFingersPosition_SendGoal_Response_<ContainerAllocator>;

  explicit SetFingersPosition_SendGoal_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  explicit SetFingersPosition_SendGoal_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : stamp(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->accepted = false;
    }
  }

  // field types and members
  using _accepted_type =
    bool;
  _accepted_type accepted;
  using _stamp_type =
    builtin_interfaces::msg::Time_<ContainerAllocator>;
  _stamp_type stamp;

  // setters for named parameter idiom
  Type & set__accepted(
    const bool & _arg)
  {
    this->accepted = _arg;
    return *this;
  }
  Type & set__stamp(
    const builtin_interfaces::msg::Time_<ContainerAllocator> & _arg)
  {
    this->stamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_SendGoal_Response
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_SendGoal_Response
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_SendGoal_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFingersPosition_SendGoal_Response_ & other) const
  {
    if (this->accepted != other.accepted) {
      return false;
    }
    if (this->stamp != other.stamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFingersPosition_SendGoal_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFingersPosition_SendGoal_Response_

// alias to use template instance with default allocator
using SetFingersPosition_SendGoal_Response =
  kinova_msgs::action::SetFingersPosition_SendGoal_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace kinova_msgs

namespace kinova_msgs
{

namespace action
{

struct SetFingersPosition_SendGoal
{
  using Request = kinova_msgs::action::SetFingersPosition_SendGoal_Request;
  using Response = kinova_msgs::action::SetFingersPosition_SendGoal_Response;
};

}  // namespace action

}  // namespace kinova_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_GetResult_Request __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_GetResult_Request __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SetFingersPosition_GetResult_Request_
{
  using Type = SetFingersPosition_GetResult_Request_<ContainerAllocator>;

  explicit SetFingersPosition_GetResult_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init)
  {
    (void)_init;
  }

  explicit SetFingersPosition_GetResult_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_GetResult_Request
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_GetResult_Request
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFingersPosition_GetResult_Request_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFingersPosition_GetResult_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFingersPosition_GetResult_Request_

// alias to use template instance with default allocator
using SetFingersPosition_GetResult_Request =
  kinova_msgs::action::SetFingersPosition_GetResult_Request_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace kinova_msgs


// Include directives for member types
// Member 'result'
// already included above
// #include "kinova_msgs/action/detail/set_fingers_position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_GetResult_Response __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_GetResult_Response __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SetFingersPosition_GetResult_Response_
{
  using Type = SetFingersPosition_GetResult_Response_<ContainerAllocator>;

  explicit SetFingersPosition_GetResult_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit SetFingersPosition_GetResult_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    int8_t;
  _status_type status;
  using _result_type =
    kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__status(
    const int8_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__result(
    const kinova_msgs::action::SetFingersPosition_Result_<ContainerAllocator> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_GetResult_Response
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_GetResult_Response
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_GetResult_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFingersPosition_GetResult_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFingersPosition_GetResult_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFingersPosition_GetResult_Response_

// alias to use template instance with default allocator
using SetFingersPosition_GetResult_Response =
  kinova_msgs::action::SetFingersPosition_GetResult_Response_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace kinova_msgs

namespace kinova_msgs
{

namespace action
{

struct SetFingersPosition_GetResult
{
  using Request = kinova_msgs::action::SetFingersPosition_GetResult_Request;
  using Response = kinova_msgs::action::SetFingersPosition_GetResult_Response;
};

}  // namespace action

}  // namespace kinova_msgs


// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.hpp"
// Member 'feedback'
// already included above
// #include "kinova_msgs/action/detail/set_fingers_position__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_FeedbackMessage __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__action__SetFingersPosition_FeedbackMessage __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace action
{

// message struct
template<class ContainerAllocator>
struct SetFingersPosition_FeedbackMessage_
{
  using Type = SetFingersPosition_FeedbackMessage_<ContainerAllocator>;

  explicit SetFingersPosition_FeedbackMessage_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_init),
    feedback(_init)
  {
    (void)_init;
  }

  explicit SetFingersPosition_FeedbackMessage_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goal_id(_alloc, _init),
    feedback(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _goal_id_type =
    unique_identifier_msgs::msg::UUID_<ContainerAllocator>;
  _goal_id_type goal_id;
  using _feedback_type =
    kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator>;
  _feedback_type feedback;

  // setters for named parameter idiom
  Type & set__goal_id(
    const unique_identifier_msgs::msg::UUID_<ContainerAllocator> & _arg)
  {
    this->goal_id = _arg;
    return *this;
  }
  Type & set__feedback(
    const kinova_msgs::action::SetFingersPosition_Feedback_<ContainerAllocator> & _arg)
  {
    this->feedback = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_FeedbackMessage
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__action__SetFingersPosition_FeedbackMessage
    std::shared_ptr<kinova_msgs::action::SetFingersPosition_FeedbackMessage_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetFingersPosition_FeedbackMessage_ & other) const
  {
    if (this->goal_id != other.goal_id) {
      return false;
    }
    if (this->feedback != other.feedback) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetFingersPosition_FeedbackMessage_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetFingersPosition_FeedbackMessage_

// alias to use template instance with default allocator
using SetFingersPosition_FeedbackMessage =
  kinova_msgs::action::SetFingersPosition_FeedbackMessage_<std::allocator<void>>;

// constant definitions

}  // namespace action

}  // namespace kinova_msgs

#include "action_msgs/srv/cancel_goal.hpp"
#include "action_msgs/msg/goal_info.hpp"
#include "action_msgs/msg/goal_status_array.hpp"

namespace kinova_msgs
{

namespace action
{

struct SetFingersPosition
{
  /// The goal message defined in the action definition.
  using Goal = kinova_msgs::action::SetFingersPosition_Goal;
  /// The result message defined in the action definition.
  using Result = kinova_msgs::action::SetFingersPosition_Result;
  /// The feedback message defined in the action definition.
  using Feedback = kinova_msgs::action::SetFingersPosition_Feedback;

  struct Impl
  {
    /// The send_goal service using a wrapped version of the goal message as a request.
    using SendGoalService = kinova_msgs::action::SetFingersPosition_SendGoal;
    /// The get_result service using a wrapped version of the result message as a response.
    using GetResultService = kinova_msgs::action::SetFingersPosition_GetResult;
    /// The feedback message with generic fields which wraps the feedback message.
    using FeedbackMessage = kinova_msgs::action::SetFingersPosition_FeedbackMessage;

    /// The generic service to cancel a goal.
    using CancelGoalService = action_msgs::srv::CancelGoal;
    /// The generic message for the status of a goal.
    using GoalStatusMessage = action_msgs::msg::GoalStatusArray;
  };
};

typedef struct SetFingersPosition SetFingersPosition;

}  // namespace action

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__ACTION__DETAIL__SET_FINGERS_POSITION__STRUCT_HPP_
