# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kinova_msgs:msg/CartesianForce.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CartesianForce(type):
    """Metaclass of message 'CartesianForce'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('kinova_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'kinova_msgs.msg.CartesianForce')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__cartesian_force
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__cartesian_force
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__cartesian_force
            cls._TYPE_SUPPORT = module.type_support_msg__msg__cartesian_force
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__cartesian_force

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CartesianForce(metaclass=Metaclass_CartesianForce):
    """Message class 'CartesianForce'."""

    __slots__ = [
        '_force_x',
        '_force_y',
        '_force_z',
        '_torque_x',
        '_torque_y',
        '_torque_z',
    ]

    _fields_and_field_types = {
        'force_x': 'float',
        'force_y': 'float',
        'force_z': 'float',
        'torque_x': 'float',
        'torque_y': 'float',
        'torque_z': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.force_x = kwargs.get('force_x', float())
        self.force_y = kwargs.get('force_y', float())
        self.force_z = kwargs.get('force_z', float())
        self.torque_x = kwargs.get('torque_x', float())
        self.torque_y = kwargs.get('torque_y', float())
        self.torque_z = kwargs.get('torque_z', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.force_x != other.force_x:
            return False
        if self.force_y != other.force_y:
            return False
        if self.force_z != other.force_z:
            return False
        if self.torque_x != other.torque_x:
            return False
        if self.torque_y != other.torque_y:
            return False
        if self.torque_z != other.torque_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def force_x(self):
        """Message field 'force_x'."""
        return self._force_x

    @force_x.setter
    def force_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force_x = value

    @builtins.property
    def force_y(self):
        """Message field 'force_y'."""
        return self._force_y

    @force_y.setter
    def force_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force_y = value

    @builtins.property
    def force_z(self):
        """Message field 'force_z'."""
        return self._force_z

    @force_z.setter
    def force_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'force_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'force_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._force_z = value

    @builtins.property
    def torque_x(self):
        """Message field 'torque_x'."""
        return self._torque_x

    @torque_x.setter
    def torque_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'torque_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'torque_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._torque_x = value

    @builtins.property
    def torque_y(self):
        """Message field 'torque_y'."""
        return self._torque_y

    @torque_y.setter
    def torque_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'torque_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'torque_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._torque_y = value

    @builtins.property
    def torque_z(self):
        """Message field 'torque_z'."""
        return self._torque_z

    @torque_z.setter
    def torque_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'torque_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'torque_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._torque_z = value
