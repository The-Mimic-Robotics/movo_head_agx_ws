# generated from rosidl_generator_py/resource/_idl.py.em
# with input from kinova_msgs:msg/PoseVelocityWithFingers.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PoseVelocityWithFingers(type):
    """Metaclass of message 'PoseVelocityWithFingers'."""

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
                'kinova_msgs.msg.PoseVelocityWithFingers')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__pose_velocity_with_fingers
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__pose_velocity_with_fingers
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__pose_velocity_with_fingers
            cls._TYPE_SUPPORT = module.type_support_msg__msg__pose_velocity_with_fingers
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__pose_velocity_with_fingers

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class PoseVelocityWithFingers(metaclass=Metaclass_PoseVelocityWithFingers):
    """Message class 'PoseVelocityWithFingers'."""

    __slots__ = [
        '_twist_linear_x',
        '_twist_linear_y',
        '_twist_linear_z',
        '_twist_angular_x',
        '_twist_angular_y',
        '_twist_angular_z',
        '_fingers_closure_percentage',
    ]

    _fields_and_field_types = {
        'twist_linear_x': 'float',
        'twist_linear_y': 'float',
        'twist_linear_z': 'float',
        'twist_angular_x': 'float',
        'twist_angular_y': 'float',
        'twist_angular_z': 'float',
        'fingers_closure_percentage': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
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
        self.twist_linear_x = kwargs.get('twist_linear_x', float())
        self.twist_linear_y = kwargs.get('twist_linear_y', float())
        self.twist_linear_z = kwargs.get('twist_linear_z', float())
        self.twist_angular_x = kwargs.get('twist_angular_x', float())
        self.twist_angular_y = kwargs.get('twist_angular_y', float())
        self.twist_angular_z = kwargs.get('twist_angular_z', float())
        self.fingers_closure_percentage = kwargs.get('fingers_closure_percentage', float())

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
        if self.twist_linear_x != other.twist_linear_x:
            return False
        if self.twist_linear_y != other.twist_linear_y:
            return False
        if self.twist_linear_z != other.twist_linear_z:
            return False
        if self.twist_angular_x != other.twist_angular_x:
            return False
        if self.twist_angular_y != other.twist_angular_y:
            return False
        if self.twist_angular_z != other.twist_angular_z:
            return False
        if self.fingers_closure_percentage != other.fingers_closure_percentage:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def twist_linear_x(self):
        """Message field 'twist_linear_x'."""
        return self._twist_linear_x

    @twist_linear_x.setter
    def twist_linear_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'twist_linear_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'twist_linear_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._twist_linear_x = value

    @builtins.property
    def twist_linear_y(self):
        """Message field 'twist_linear_y'."""
        return self._twist_linear_y

    @twist_linear_y.setter
    def twist_linear_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'twist_linear_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'twist_linear_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._twist_linear_y = value

    @builtins.property
    def twist_linear_z(self):
        """Message field 'twist_linear_z'."""
        return self._twist_linear_z

    @twist_linear_z.setter
    def twist_linear_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'twist_linear_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'twist_linear_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._twist_linear_z = value

    @builtins.property
    def twist_angular_x(self):
        """Message field 'twist_angular_x'."""
        return self._twist_angular_x

    @twist_angular_x.setter
    def twist_angular_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'twist_angular_x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'twist_angular_x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._twist_angular_x = value

    @builtins.property
    def twist_angular_y(self):
        """Message field 'twist_angular_y'."""
        return self._twist_angular_y

    @twist_angular_y.setter
    def twist_angular_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'twist_angular_y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'twist_angular_y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._twist_angular_y = value

    @builtins.property
    def twist_angular_z(self):
        """Message field 'twist_angular_z'."""
        return self._twist_angular_z

    @twist_angular_z.setter
    def twist_angular_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'twist_angular_z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'twist_angular_z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._twist_angular_z = value

    @builtins.property
    def fingers_closure_percentage(self):
        """Message field 'fingers_closure_percentage'."""
        return self._fingers_closure_percentage

    @fingers_closure_percentage.setter
    def fingers_closure_percentage(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'fingers_closure_percentage' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'fingers_closure_percentage' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._fingers_closure_percentage = value
