// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from kinova_msgs:srv/SetForceControlParams.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "kinova_msgs/srv/detail/set_force_control_params__rosidl_typesupport_introspection_c.h"
#include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "kinova_msgs/srv/detail/set_force_control_params__functions.h"
#include "kinova_msgs/srv/detail/set_force_control_params__struct.h"


// Include directives for member types
// Member `inertia_linear`
// Member `inertia_angular`
// Member `damping_linear`
// Member `damping_angular`
// Member `force_min_linear`
// Member `force_min_angular`
// Member `force_max_linear`
// Member `force_max_angular`
#include "geometry_msgs/msg/vector3.h"
// Member `inertia_linear`
// Member `inertia_angular`
// Member `damping_linear`
// Member `damping_angular`
// Member `force_min_linear`
// Member `force_min_angular`
// Member `force_max_linear`
// Member `force_max_angular`
#include "geometry_msgs/msg/detail/vector3__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__srv__SetForceControlParams_Request__init(message_memory);
}

void kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_fini_function(void * message_memory)
{
  kinova_msgs__srv__SetForceControlParams_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array[8] = {
  {
    "inertia_linear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetForceControlParams_Request, inertia_linear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "inertia_angular",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetForceControlParams_Request, inertia_angular),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "damping_linear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetForceControlParams_Request, damping_linear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "damping_angular",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetForceControlParams_Request, damping_angular),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "force_min_linear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetForceControlParams_Request, force_min_linear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "force_min_angular",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetForceControlParams_Request, force_min_angular),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "force_max_linear",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetForceControlParams_Request, force_max_linear),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "force_max_angular",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetForceControlParams_Request, force_max_angular),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_members = {
  "kinova_msgs__srv",  // message namespace
  "SetForceControlParams_Request",  // message name
  8,  // number of fields
  sizeof(kinova_msgs__srv__SetForceControlParams_Request),
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array,  // message members
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_type_support_handle = {
  0,
  &kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetForceControlParams_Request)() {
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array[4].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_member_array[7].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Vector3)();
  if (!kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__srv__SetForceControlParams_Request__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "kinova_msgs/srv/detail/set_force_control_params__rosidl_typesupport_introspection_c.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "kinova_msgs/srv/detail/set_force_control_params__functions.h"
// already included above
// #include "kinova_msgs/srv/detail/set_force_control_params__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  kinova_msgs__srv__SetForceControlParams_Response__init(message_memory);
}

void kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_fini_function(void * message_memory)
{
  kinova_msgs__srv__SetForceControlParams_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(kinova_msgs__srv__SetForceControlParams_Response, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_message_members = {
  "kinova_msgs__srv",  // message namespace
  "SetForceControlParams_Response",  // message name
  1,  // number of fields
  sizeof(kinova_msgs__srv__SetForceControlParams_Response),
  kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_message_member_array,  // message members
  kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_message_type_support_handle = {
  0,
  &kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetForceControlParams_Response)() {
  if (!kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_message_type_support_handle.typesupport_identifier) {
    kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &kinova_msgs__srv__SetForceControlParams_Response__rosidl_typesupport_introspection_c__SetForceControlParams_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "kinova_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "kinova_msgs/srv/detail/set_force_control_params__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers kinova_msgs__srv__detail__set_force_control_params__rosidl_typesupport_introspection_c__SetForceControlParams_service_members = {
  "kinova_msgs__srv",  // service namespace
  "SetForceControlParams",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // kinova_msgs__srv__detail__set_force_control_params__rosidl_typesupport_introspection_c__SetForceControlParams_Request_message_type_support_handle,
  NULL  // response message
  // kinova_msgs__srv__detail__set_force_control_params__rosidl_typesupport_introspection_c__SetForceControlParams_Response_message_type_support_handle
};

static rosidl_service_type_support_t kinova_msgs__srv__detail__set_force_control_params__rosidl_typesupport_introspection_c__SetForceControlParams_service_type_support_handle = {
  0,
  &kinova_msgs__srv__detail__set_force_control_params__rosidl_typesupport_introspection_c__SetForceControlParams_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetForceControlParams_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetForceControlParams_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_kinova_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetForceControlParams)() {
  if (!kinova_msgs__srv__detail__set_force_control_params__rosidl_typesupport_introspection_c__SetForceControlParams_service_type_support_handle.typesupport_identifier) {
    kinova_msgs__srv__detail__set_force_control_params__rosidl_typesupport_introspection_c__SetForceControlParams_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)kinova_msgs__srv__detail__set_force_control_params__rosidl_typesupport_introspection_c__SetForceControlParams_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetForceControlParams_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, kinova_msgs, srv, SetForceControlParams_Response)()->data;
  }

  return &kinova_msgs__srv__detail__set_force_control_params__rosidl_typesupport_introspection_c__SetForceControlParams_service_type_support_handle;
}
