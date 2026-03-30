#!/usr/bin/env python3
"""
Cycle through home poses on Xbox A-button double tap.

- Subscribes to /joy (or configured topic).
- Detects rising-edge double tap on button A (index 0).
- Each double tap advances to the next pose in home_joints.yaml order.
- Sends both arm joint-angle goals directly (separate from home service executable).
"""

from __future__ import annotations

import threading
import time

import rclpy
from rclpy.action import ActionClient
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.node import Node
from sensor_msgs.msg import Joy

from kinova_msgs.action import ArmJointAngles

from axe_leader_teleop.home_joint_config import load_home_joints_yaml


class HomePoseCycleTeleop(Node):
    def __init__(self) -> None:
        super().__init__("home_pose_cycle_teleop")

        self.declare_parameter("joy_topic", "/joy")
        self.declare_parameter("double_tap_sec", 0.40)
        self.declare_parameter("start_pose_name", "")
        self.declare_parameter("cycle_pose_names", "")
        self.declare_parameter("stagger_sec", 0.50)

        self._joy_topic = str(self.get_parameter("joy_topic").value)
        self._double_tap_sec = float(self.get_parameter("double_tap_sec").value)
        self._start_pose_name = str(self.get_parameter("start_pose_name").value).strip()
        self._cycle_pose_names_param = str(self.get_parameter("cycle_pose_names").value).strip()
        self._stagger_sec = float(self.get_parameter("stagger_sec").value)

        self._poses, yaml_start_pose = self._load_poses()
        self._pose_names = self._resolve_cycle_order(self._poses)
        if not self._pose_names:
            raise RuntimeError("No home poses loaded from home_joints.yaml")

        if self._start_pose_name and self._start_pose_name in self._pose_names:
            self._idx = self._pose_names.index(self._start_pose_name)
        elif yaml_start_pose and yaml_start_pose in self._pose_names:
            self._idx = self._pose_names.index(yaml_start_pose)
        else:
            self._idx = 0

        cb_group = ReentrantCallbackGroup()
        self._right_client = ActionClient(
            self,
            ArmJointAngles,
            "/right_arm/right_arm_driver/joints_action/joint_angles",
            callback_group=cb_group,
        )
        self._left_client = ActionClient(
            self,
            ArmJointAngles,
            "/left_arm/left_arm_driver/joints_action/joint_angles",
            callback_group=cb_group,
        )

        self._prev_buttons: list[int] = []
        self._last_a_press_t = 0.0
        self._homing_lock = threading.Lock()

        self.create_subscription(Joy, self._joy_topic, self._joy_cb, 10)

        self.get_logger().info(
            f"Home pose cycle ready. joy_topic={self._joy_topic} "
            f"poses={','.join(self._pose_names)} start={self._pose_names[self._idx]}"
        )
        self.get_logger().info("Double-tap A to cycle to next homing pose.")

    def _load_poses(self) -> tuple[dict[str, dict], str]:
        cfg, yaml_path = load_home_joints_yaml()
        if not isinstance(cfg, dict):
            raise RuntimeError("home_joints.yaml not found or invalid")
        poses = cfg.get("home_poses")
        if not isinstance(poses, dict):
            raise RuntimeError("home_joints.yaml has no 'home_poses' map")
        if yaml_path:
            self.get_logger().info(f"Loaded home poses from {yaml_path}")
        yaml_start_pose = str(cfg.get("homing_pose_name") or "").strip()
        return poses, yaml_start_pose

    def _resolve_cycle_order(self, poses: dict[str, dict]) -> list[str]:
        # Default order is YAML insertion order. Optional override allows explicit deterministic order.
        names = list(poses.keys())
        if not self._cycle_pose_names_param:
            return names

        requested = [s.strip() for s in self._cycle_pose_names_param.split(",") if s.strip()]
        valid = [n for n in requested if n in poses]
        invalid = [n for n in requested if n not in poses]
        if invalid:
            self.get_logger().warn(
                f"Ignoring unknown cycle_pose_names entries: {','.join(invalid)}"
            )
        if not valid:
            self.get_logger().warn("cycle_pose_names had no valid names; using YAML order")
            return names
        return valid

    @staticmethod
    def _goal_from_pose(pose_block: dict) -> tuple[ArmJointAngles.Goal, ArmJointAngles.Goal]:
        right = ArmJointAngles.Goal()
        left = ArmJointAngles.Goal()
        for i in range(1, 8):
            setattr(right.angles, f"joint{i}", float(pose_block["right_arm"][f"joint{i}"]))
            setattr(left.angles, f"joint{i}", float(pose_block["left_arm"][f"joint{i}"]))
        return right, left

    @staticmethod
    def _wait_future(future, timeout_sec: float) -> bool:
        deadline = time.monotonic() + timeout_sec
        while rclpy.ok() and not future.done():
            if time.monotonic() >= deadline:
                return False
            time.sleep(0.05)
        return future.done()

    def _joy_cb(self, msg: Joy) -> None:
        if len(self._prev_buttons) < len(msg.buttons):
            self._prev_buttons.extend([0] * (len(msg.buttons) - len(self._prev_buttons)))

        a_now = 1 if (len(msg.buttons) > 0 and msg.buttons[0] == 1) else 0
        a_prev = self._prev_buttons[0] if self._prev_buttons else 0
        rising_a = a_now == 1 and a_prev == 0

        if rising_a:
            now = time.monotonic()
            if (now - self._last_a_press_t) <= self._double_tap_sec:
                self._last_a_press_t = 0.0
                self.get_logger().info("[cycle] A double-tap detected")
                self._cycle_pose()
            else:
                self._last_a_press_t = now

        self._prev_buttons = list(msg.buttons)

    def _cycle_pose(self) -> None:
        if self._homing_lock.locked():
            self.get_logger().warn("Homing in progress; ignoring double tap")
            return
        prev = self._pose_names[self._idx]
        self._idx = (self._idx + 1) % len(self._pose_names)
        pose_name = self._pose_names[self._idx]
        self.get_logger().info(
            f"[cycle] next: '{prev}' -> '{pose_name}' ({self._idx + 1}/{len(self._pose_names)})"
        )
        thread = threading.Thread(target=self._home_pose_thread, args=(pose_name,), daemon=True)
        thread.start()

    def _home_pose_thread(self, pose_name: str) -> None:
        with self._homing_lock:
            pose = self._poses.get(pose_name)
            if not isinstance(pose, dict):
                self.get_logger().error(f"Pose '{pose_name}' missing or invalid")
                return

            self.get_logger().info(f"[cycle] Homing both arms to '{pose_name}'")

            if not self._right_client.wait_for_server(timeout_sec=10.0):
                self.get_logger().error("Right arm action server unavailable")
                return
            if not self._left_client.wait_for_server(timeout_sec=10.0):
                self.get_logger().error("Left arm action server unavailable")
                return

            right_goal, left_goal = self._goal_from_pose(pose)
            right_fut = self._right_client.send_goal_async(right_goal)
            time.sleep(max(0.0, self._stagger_sec))
            left_fut = self._left_client.send_goal_async(left_goal)

            if not self._wait_future(right_fut, 20.0) or not self._wait_future(left_fut, 20.0):
                self.get_logger().error("Timed out waiting for goal acceptance")
                return

            right_h = right_fut.result()
            left_h = left_fut.result()
            if not right_h or not right_h.accepted:
                self.get_logger().error("Right arm goal rejected")
                return
            if not left_h or not left_h.accepted:
                self.get_logger().error("Left arm goal rejected")
                return

            right_res_f = right_h.get_result_async()
            left_res_f = left_h.get_result_async()
            if not self._wait_future(right_res_f, 120.0) or not self._wait_future(left_res_f, 120.0):
                self.get_logger().error("Timed out waiting for homing result")
                return

            right_res = right_res_f.result()
            left_res = left_res_f.result()
            right_ok = bool(right_res and right_res.status == 4)
            left_ok = bool(left_res and left_res.status == 4)
            if right_ok and left_ok:
                self.get_logger().info(f"[cycle] SUCCESS pose='{pose_name}'")
            else:
                self.get_logger().error(
                    f"[cycle] FAIL pose='{pose_name}' "
                    f"(right_status={getattr(right_res, 'status', None)}, "
                    f"left_status={getattr(left_res, 'status', None)})"
                )


def main(args=None) -> None:
    rclpy.init(args=args)
    node = HomePoseCycleTeleop()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
