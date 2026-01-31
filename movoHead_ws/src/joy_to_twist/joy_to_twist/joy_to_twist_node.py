import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from geometry_msgs.msg import Twist

class JoyToTwistNode(Node):
    def __init__(self):
        super().__init__('joy_to_twist_node')
        self.get_logger().info("JoyToTwistNode started")

        # Parameters for axis mapping
        self.declare_parameter('axis_linear_x', 1)  # left stick vertical (linear.x)
        self.declare_parameter('axis_linear_y', 0)  # left stick horizontal (linear.y)
        self.declare_parameter('axis_angular', 2)   # right stick horizontal (angular.z)
        self.declare_parameter('scale_linear', 1.0)
        self.declare_parameter('scale_angular', 1.0)

        self.axis_linear_x = self.get_parameter('axis_linear_x').value
        self.axis_linear_y = self.get_parameter('axis_linear_y').value
        self.axis_angular = self.get_parameter('axis_angular').value
        self.scale_linear = self.get_parameter('scale_linear').value
        self.scale_angular = self.get_parameter('scale_angular').value

        # Subscribe to the /joy topic
        self.joy_sub = self.create_subscription(Joy, '/joy', self.joy_callback, 10)

        # Publish to the /cmd_vel topic
        self.twist_pub = self.create_publisher(Twist, '/cmd_vel', 100)

        # Watchdog: track last received joy message
        self.last_joy_time = self.get_clock().now()
        self.timeout_sec = 0.5  # Timeout period in seconds
        self.timer = self.create_timer(0.1, self.timer_callback)

    def joy_callback(self, msg):
        # Update the time of the last received message
        self.last_joy_time = self.get_clock().now()

        twist = Twist()
        # Map joystick axes to Twist
        twist.linear.x = msg.axes[self.axis_linear_x] * self.scale_linear
        twist.linear.y = msg.axes[self.axis_linear_y] * self.scale_linear
        twist.angular.z = msg.axes[self.axis_angular] * self.scale_angular

        # Publish the Twist message
        self.twist_pub.publish(twist)
        self.get_logger().info(
            f"Published Twist: linear.x = {twist.linear.x}, linear.y = {twist.linear.y}, angular.z = {twist.angular.z}"
        )

    def timer_callback(self):
        # Check if the last message was received within the timeout period
        current_time = self.get_clock().now()
        elapsed_time = (current_time - self.last_joy_time).nanoseconds / 1e9
        if elapsed_time > self.timeout_sec:
            # If the timeout has been exceeded, publish a zero Twist message
            twist = Twist()  # All fields default to 0
            self.twist_pub.publish(twist)
            self.get_logger().warn("No joystick input received - publishing zero Twist!")

def main(args=None):
    rclpy.init(args=args)
    node = JoyToTwistNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info('JoyToTwistNode interrupted.')
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
