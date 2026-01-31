// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from kinova_msgs:msg/KinovaPose.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "kinova_msgs/msg/detail/kinova_pose__struct.h"
#include "kinova_msgs/msg/detail/kinova_pose__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool kinova_msgs__msg__kinova_pose__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("kinova_msgs.msg._kinova_pose.KinovaPose", full_classname_dest, 39) == 0);
  }
  kinova_msgs__msg__KinovaPose * ros_message = _ros_message;
  {  // x
    PyObject * field = PyObject_GetAttrString(_pymsg, "x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // y
    PyObject * field = PyObject_GetAttrString(_pymsg, "y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // z
    PyObject * field = PyObject_GetAttrString(_pymsg, "z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // theta_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "theta_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->theta_x = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // theta_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "theta_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->theta_y = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // theta_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "theta_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->theta_z = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * kinova_msgs__msg__kinova_pose__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of KinovaPose */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("kinova_msgs.msg._kinova_pose");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "KinovaPose");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  kinova_msgs__msg__KinovaPose * ros_message = (kinova_msgs__msg__KinovaPose *)raw_ros_message;
  {  // x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // theta_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->theta_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "theta_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // theta_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->theta_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "theta_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // theta_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->theta_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "theta_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
