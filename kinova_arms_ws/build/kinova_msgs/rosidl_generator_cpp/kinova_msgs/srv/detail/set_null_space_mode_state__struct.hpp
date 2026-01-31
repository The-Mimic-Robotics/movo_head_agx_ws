// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinova_msgs:srv/SetNullSpaceModeState.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__SET_NULL_SPACE_MODE_STATE__STRUCT_HPP_
#define KINOVA_MSGS__SRV__DETAIL__SET_NULL_SPACE_MODE_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__SetNullSpaceModeState_Request __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__SetNullSpaceModeState_Request __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetNullSpaceModeState_Request_
{
  using Type = SetNullSpaceModeState_Request_<ContainerAllocator>;

  explicit SetNullSpaceModeState_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  explicit SetNullSpaceModeState_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
    }
  }

  // field types and members
  using _state_type =
    uint16_t;
  _state_type state;

  // setters for named parameter idiom
  Type & set__state(
    const uint16_t & _arg)
  {
    this->state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__SetNullSpaceModeState_Request
    std::shared_ptr<kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__SetNullSpaceModeState_Request
    std::shared_ptr<kinova_msgs::srv::SetNullSpaceModeState_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetNullSpaceModeState_Request_ & other) const
  {
    if (this->state != other.state) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetNullSpaceModeState_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetNullSpaceModeState_Request_

// alias to use template instance with default allocator
using SetNullSpaceModeState_Request =
  kinova_msgs::srv::SetNullSpaceModeState_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__SetNullSpaceModeState_Response __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__SetNullSpaceModeState_Response __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetNullSpaceModeState_Response_
{
  using Type = SetNullSpaceModeState_Response_<ContainerAllocator>;

  explicit SetNullSpaceModeState_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit SetNullSpaceModeState_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__SetNullSpaceModeState_Response
    std::shared_ptr<kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__SetNullSpaceModeState_Response
    std::shared_ptr<kinova_msgs::srv::SetNullSpaceModeState_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetNullSpaceModeState_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetNullSpaceModeState_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetNullSpaceModeState_Response_

// alias to use template instance with default allocator
using SetNullSpaceModeState_Response =
  kinova_msgs::srv::SetNullSpaceModeState_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs

namespace kinova_msgs
{

namespace srv
{

struct SetNullSpaceModeState
{
  using Request = kinova_msgs::srv::SetNullSpaceModeState_Request;
  using Response = kinova_msgs::srv::SetNullSpaceModeState_Response;
};

}  // namespace srv

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__SET_NULL_SPACE_MODE_STATE__STRUCT_HPP_
