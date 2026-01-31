// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from kinova_msgs:srv/AddPoseToCartesianTrajectory.idl
// generated code does not contain a copyright notice

#ifndef KINOVA_MSGS__SRV__DETAIL__ADD_POSE_TO_CARTESIAN_TRAJECTORY__STRUCT_HPP_
#define KINOVA_MSGS__SRV__DETAIL__ADD_POSE_TO_CARTESIAN_TRAJECTORY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__AddPoseToCartesianTrajectory_Request __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__AddPoseToCartesianTrajectory_Request __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AddPoseToCartesianTrajectory_Request_
{
  using Type = AddPoseToCartesianTrajectory_Request_<ContainerAllocator>;

  explicit AddPoseToCartesianTrajectory_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->theta_x = 0.0f;
      this->theta_y = 0.0f;
      this->theta_z = 0.0f;
    }
  }

  explicit AddPoseToCartesianTrajectory_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0f;
      this->y = 0.0f;
      this->z = 0.0f;
      this->theta_x = 0.0f;
      this->theta_y = 0.0f;
      this->theta_z = 0.0f;
    }
  }

  // field types and members
  using _x_type =
    float;
  _x_type x;
  using _y_type =
    float;
  _y_type y;
  using _z_type =
    float;
  _z_type z;
  using _theta_x_type =
    float;
  _theta_x_type theta_x;
  using _theta_y_type =
    float;
  _theta_y_type theta_y;
  using _theta_z_type =
    float;
  _theta_z_type theta_z;

  // setters for named parameter idiom
  Type & set__x(
    const float & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const float & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__z(
    const float & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__theta_x(
    const float & _arg)
  {
    this->theta_x = _arg;
    return *this;
  }
  Type & set__theta_y(
    const float & _arg)
  {
    this->theta_y = _arg;
    return *this;
  }
  Type & set__theta_z(
    const float & _arg)
  {
    this->theta_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__AddPoseToCartesianTrajectory_Request
    std::shared_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__AddPoseToCartesianTrajectory_Request
    std::shared_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AddPoseToCartesianTrajectory_Request_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->theta_x != other.theta_x) {
      return false;
    }
    if (this->theta_y != other.theta_y) {
      return false;
    }
    if (this->theta_z != other.theta_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const AddPoseToCartesianTrajectory_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AddPoseToCartesianTrajectory_Request_

// alias to use template instance with default allocator
using AddPoseToCartesianTrajectory_Request =
  kinova_msgs::srv::AddPoseToCartesianTrajectory_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs


#ifndef _WIN32
# define DEPRECATED__kinova_msgs__srv__AddPoseToCartesianTrajectory_Response __attribute__((deprecated))
#else
# define DEPRECATED__kinova_msgs__srv__AddPoseToCartesianTrajectory_Response __declspec(deprecated)
#endif

namespace kinova_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct AddPoseToCartesianTrajectory_Response_
{
  using Type = AddPoseToCartesianTrajectory_Response_<ContainerAllocator>;

  explicit AddPoseToCartesianTrajectory_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit AddPoseToCartesianTrajectory_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__kinova_msgs__srv__AddPoseToCartesianTrajectory_Response
    std::shared_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__kinova_msgs__srv__AddPoseToCartesianTrajectory_Response
    std::shared_ptr<kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AddPoseToCartesianTrajectory_Response_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const AddPoseToCartesianTrajectory_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AddPoseToCartesianTrajectory_Response_

// alias to use template instance with default allocator
using AddPoseToCartesianTrajectory_Response =
  kinova_msgs::srv::AddPoseToCartesianTrajectory_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace kinova_msgs

namespace kinova_msgs
{

namespace srv
{

struct AddPoseToCartesianTrajectory
{
  using Request = kinova_msgs::srv::AddPoseToCartesianTrajectory_Request;
  using Response = kinova_msgs::srv::AddPoseToCartesianTrajectory_Response;
};

}  // namespace srv

}  // namespace kinova_msgs

#endif  // KINOVA_MSGS__SRV__DETAIL__ADD_POSE_TO_CARTESIAN_TRAJECTORY__STRUCT_HPP_
