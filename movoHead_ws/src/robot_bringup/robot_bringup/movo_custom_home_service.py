#!/usr/bin/env python3
"""
Custom home service for MOVO arms.
Sends ArmJointAngles goals to move arms to a predefined home position.

Services:
  /movo/home_right_arm   - home right arm
  /movo/home_left_arm    - home left arm
  /movo/home_both_arms   - home both arms simultaneously
"""

import os
import time

import rclpy
import yaml
from ament_index_python.packages import get_package_share_directory
from rclpy.action import ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import MultiThreadedExecutor
from rclpy.node import Node

from kinova_msgs.action import ArmJointAngles
from kinova_msgs.srv import HomeArm


class MovoCustomHomeService(Node):
    def __init__(self):
        super().__init__("movo_custom_home_service")

        config = self.load_config()
        cb_group = ReentrantCallbackGroup()

        self.right_arm_target = [float(config["right_arm"][f"joint{i}"]) for i in range(1, 8)]
        self.left_arm_target = [float(config["left_arm"][f"joint{i}"]) for i in range(1, 8)]

        self.right_arm_client = ActionClient(
            self, ArmJointAngles,
            "/right_arm/right_arm_driver/joints_action/joint_angles",
            callback_group=cb_group,
        )
        self.left_arm_client = ActionClient(
            self, ArmJointAngles,
            "/left_arm/left_arm_driver/joints_action/joint_angles",
            callback_group=cb_group,
        )

        self.create_service(HomeArm, "/movo/home_right_arm", self.handle_home_right, callback_group=cb_group)
        self.create_service(HomeArm, "/movo/home_left_arm", self.handle_home_left, callback_group=cb_group)
        self.create_service(HomeArm, "/movo/home_both_arms", self.handle_home_both, callback_group=cb_group)

        self.get_logger().info("=== MOVO Custom Home Service READY ===")
        self.get_logger().info(f"  /movo/home_right_arm -> {self.right_arm_target}")
        self.get_logger().info(f"  /movo/home_left_arm  -> {self.left_arm_target}")
        self.get_logger().info(f"  /movo/home_both_arms -> simultaneous")

    def load_config(self):
        path = os.path.join(
            get_package_share_directory("robot_bringup"), "config", "home_joints.yaml"
        )
        with open(path, "r", encoding="utf-8") as f:
            return yaml.safe_load(f)

    def make_goal(self, target_angles):
        goal = ArmJointAngles.Goal()
        for i, val in enumerate(target_angles, start=1):
            setattr(goal.angles, f"joint{i}", float(val))
        return goal

    def poll_future(self, future, timeout):
        """Block until future is done or timeout (seconds) expires."""
        deadline = time.monotonic() + timeout
        while rclpy.ok() and not future.done():
            if time.monotonic() > deadline:
                return False
            time.sleep(0.05)
        return future.done()

    def poll_all_futures(self, futures, timeout):
        """Block until ALL futures are done or timeout (seconds) expires."""
        deadline = time.monotonic() + timeout
        while rclpy.ok():
            if all(f.done() for f in futures):
                return True
            if time.monotonic() > deadline:
                return False
            time.sleep(0.05)
        return all(f.done() for f in futures)

    def send_arm_home(self, client, target, arm_name):
        """Send one arm to its home position and block until done. Returns (ok, msg)."""
        if not client.wait_for_server(timeout_sec=15.0):
            return False, "action server unavailable"

        goal_future = client.send_goal_async(self.make_goal(target))
        if not self.poll_future(goal_future, 30.0):
            return False, "send_goal timeout"

        goal_handle = goal_future.result()
        if not goal_handle or not goal_handle.accepted:
            return False, "goal rejected"

        self.get_logger().info(f"[{arm_name}] Goal accepted, arm is moving...")

        result_future = goal_handle.get_result_async()
        if not self.poll_future(result_future, 180.0):
            return False, "motion timeout"

        wrapped = result_future.result()
        if wrapped and wrapped.status == 4:
            return True, "ok"
        return False, f"action status={getattr(wrapped, 'status', None)}"

    # ── Service callbacks ──

    def handle_home_right(self, request, response):
        self.get_logger().info("[right_arm] Home START")
        ok, msg = self.send_arm_home(self.right_arm_client, self.right_arm_target, "right_arm")
        response.homearm_result = "SUCCESS" if ok else f"FAIL: {msg}"
        self.get_logger().info(f"[right_arm] {response.homearm_result}")
        return response

    def handle_home_left(self, request, response):
        self.get_logger().info("[left_arm] Home START")
        ok, msg = self.send_arm_home(self.left_arm_client, self.left_arm_target, "left_arm")
        response.homearm_result = "SUCCESS" if ok else f"FAIL: {msg}"
        self.get_logger().info(f"[left_arm] {response.homearm_result}")
        return response

    def handle_home_both(self, request, response):
        log = self.get_logger()
        log.info("[both_arms] Home START")

        if not self.right_arm_client.wait_for_server(timeout_sec=15.0):
            response.homearm_result = "FAIL: right arm action server unavailable"
            log.error(response.homearm_result)
            return response
        if not self.left_arm_client.wait_for_server(timeout_sec=15.0):
            response.homearm_result = "FAIL: left arm action server unavailable"
            log.error(response.homearm_result)
            return response

        # Fire both goals so both arms start moving at the same time
        right_goal_fut = self.right_arm_client.send_goal_async(self.make_goal(self.right_arm_target))
        left_goal_fut = self.left_arm_client.send_goal_async(self.make_goal(self.left_arm_target))

        # Wait for BOTH goal acceptances together (not one-then-the-other)
        if not self.poll_all_futures([right_goal_fut, left_goal_fut], 30.0):
            response.homearm_result = "FAIL: send_goal timeout"
            log.error(response.homearm_result)
            return response

        right_handle = right_goal_fut.result()
        left_handle = left_goal_fut.result()

        right_accepted = right_handle and right_handle.accepted
        left_accepted = left_handle and left_handle.accepted

        if right_accepted:
            log.info("[right_arm] Goal accepted, arm is moving...")
        else:
            log.error("[right_arm] Goal rejected")

        if left_accepted:
            log.info("[left_arm] Goal accepted, arm is moving...")
        else:
            log.error("[left_arm] Goal rejected")

        if not right_accepted and not left_accepted:
            response.homearm_result = "FAIL: both goals rejected"
            return response

        # Wait for BOTH motion results together
        right_res_fut = right_handle.get_result_async() if right_accepted else None
        left_res_fut = left_handle.get_result_async() if left_accepted else None

        waiting = [f for f in (right_res_fut, left_res_fut) if f is not None]
        if not self.poll_all_futures(waiting, 180.0):
            response.homearm_result = "FAIL: motion timeout"
            log.error(response.homearm_result)
            return response

        # Collect results
        errors = []

        if not right_accepted:
            errors.append("right_arm: goal rejected")
        else:
            wrapped = right_res_fut.result()
            if wrapped and wrapped.status == 4:
                log.info("[right_arm] Home DONE")
            else:
                errors.append(f"right_arm: status={getattr(wrapped, 'status', None)}")
                log.error(f"[right_arm] FAIL: status={getattr(wrapped, 'status', None)}")

        if not left_accepted:
            errors.append("left_arm: goal rejected")
        else:
            wrapped = left_res_fut.result()
            if wrapped and wrapped.status == 4:
                log.info("[left_arm] Home DONE")
            else:
                errors.append(f"left_arm: status={getattr(wrapped, 'status', None)}")
                log.error(f"[left_arm] FAIL: status={getattr(wrapped, 'status', None)}")

        if errors:
            response.homearm_result = "FAIL: " + "; ".join(errors)
        else:
            response.homearm_result = "SUCCESS"
            log.info("[both_arms] Home DONE")

        return response


def main(args=None):
    rclpy.init(args=args)
    node = MovoCustomHomeService()
    # MultiThreadedExecutor needed so action-client responses can arrive
    # while a service callback is blocked waiting for results.
    executor = MultiThreadedExecutor(num_threads=4)
    executor.add_node(node)
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    main()
