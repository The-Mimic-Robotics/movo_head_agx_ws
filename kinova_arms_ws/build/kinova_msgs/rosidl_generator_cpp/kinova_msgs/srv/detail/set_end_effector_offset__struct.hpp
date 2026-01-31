// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinova_msgs:srv/SetEndEffectorOffset.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__SET_END_EFFECTOR_OFFSET__STRUCT_HPP_
#define KINOVA_MSGS__SRV__DETAIL__SET_END_EFFECTOR_OFFSET__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'offset'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__SetEndEffectorOffset_Request __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__SetEndEffectorOffset_Request __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetEndEffectorOffset_Request_
{
  using Type = SetEndEffectorOffset_Request_<ContainerAllocator>;

  explicit SetEndEffectorOffset_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : offset(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  explicit SetEndEffectorOffset_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : offset(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = 0;
    }
  }

  // field types and members
  using _status_type =
    uint16_t;
  _status_type status;
  using _offset_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _offset_type offset;

  // setters for named parameter idiom
  Type & set__status(
    const uint16_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__offset(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->offset = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__SetEndEffectorOffset_Request
    std::shared_ptr<kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__SetEndEffectorOffset_Request
    std::shared_ptr<kinova_msgs::srv::SetEndEffectorOffset_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetEndEffectorOffset_Request_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    if (this->offset != other.offset) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetEndEffectorOffset_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetEndEffectorOffset_Request_

// alias to use template instance with default allocator
using SetEndEffectorOffset_Request =
  kinova_msgs::srv::SetEndEffectorOffset_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__SetEndEffectorOffset_Response __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__SetEndEffectorOffset_Response __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetEndEffectorOffset_Response_
{
  using Type = SetEndEffectorOffset_Response_<ContainerAllocator>;

  explicit SetEndEffectorOffset_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit SetEndEffectorOffset_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__SetEndEffectorOffset_Response
    std::shared_ptr<kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__SetEndEffectorOffset_Response
    std::shared_ptr<kinova_msgs::srv::SetEndEffectorOffset_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetEndEffectorOffset_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetEndEffectorOffset_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetEndEffectorOffset_Response_

// alias to use template instance with default allocator
using SetEndEffectorOffset_Response =
  kinova_msgs::srv::SetEndEffectorOffset_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs

namespace kinova_msgs
{

namespace srv
{

struct SetEndEffectorOffset
{
  using Request = kinova_msgs::srv::SetEndEffectorOffset_Request;
  using Response = kinova_msgs::srv::SetEndEffectorOffset_Response;
};

}  // namespace srv

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__SET_END_EFFECTOR_OFFSET__STRUCT_HPP_
