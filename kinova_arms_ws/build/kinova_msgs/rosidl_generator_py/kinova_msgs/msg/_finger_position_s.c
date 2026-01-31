// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from kinova_msgs:msg/FingerPosition.idl
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
#include "kinova_msgs/msg/detail/finger_position__struct.h"
#include "kinova_msgs/msg/detail/finger_position__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool kinova_msgs__msg__finger_position__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[48];
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
    assert(strncmp("kinova_msgs.msg._finger_position.FingerPosition", full_classname_dest, 47) == 0);
  }
  kinova_msgs__msg__FingerPosition * ros_message = _ros_message;
  {  // finger1
    PyObject * field = PyObject_GetAttrString(_pymsg, "finger1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->finger1 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // finger2
    PyObject * field = PyObject_GetAttrString(_pymsg, "finger2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->finger2 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // finger3
    PyObject * field = PyObject_GetAttrString(_pymsg, "finger3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->finger3 = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * kinova_msgs__msg__finger_position__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of FingerPosition */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("kinova_msgs.msg._finger_position");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "FingerPosition");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  kinova_msgs__msg__FingerPosition * ros_message = (kinova_msgs__msg__FingerPosition *)raw_ros_message;
  {  // finger1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->finger1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "finger1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // finger2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->finger2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "finger2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // finger3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->finger3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "finger3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
