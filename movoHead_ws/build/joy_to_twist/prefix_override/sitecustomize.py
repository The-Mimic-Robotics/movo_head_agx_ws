import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/agx/Desktop/movo_ws/movoHead_ws/install/joy_to_twist'
