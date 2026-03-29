#!/usr/bin/env python3
"""Twist-driven teleop with Cartesian pose feedback to limit drift.

Runs as a separate node from kinova_teleop: does not modify arms_xbox_ctr.

Leader convention (same as kinova_teleop): +x forward, +y left, +z up.
Axis mapping comes from home_joints.yaml via arms_xbox_ctr.home_joint_config.

Control law each tick:
  v_twist  = rate * apply_linear(twist_linear)           # mimic velocity teleop
  p_target = robot_home + speed * apply_linear(rel_leader)   # where pose says TCP should be
  v_corr   = Kp * deadband(p_target - p_current)       # pulls TCP back toward pose-implied target
  v_cart   = clamp(v_twist + v_corr)                   # hybrid
  joint_vel = cart_to_joint_vel(...)                    # optional J1 lock

Disable drift term by setting drift_kp:=0.0 to approximate pure twist (still uses pose for p_target internally).
"""

from __future__ import annotations

import math
import time

import numpy as np
import rclpy
from geometry_msgs.msg import PoseStamped, TwistStamped
from kinova_msgs.msg import JointAngles, JointVelocity, PoseVelocity
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy

from arms_xbox_ctr.home_joint_config import apply_linear, axis_map_for_arm, parse_axis_map
from arms_xbox_ctr.jaco_jacobian import cart_to_joint_vel


def _deadband_vec(err: list[float], d: float) -> list[float]:
    out = []
    for e in err:
        if abs(e) <= d:
            out.append(0.0)
        else:
            out.append(e - math.copysign(d, e))
    return out


class DriftJointTeleopNode(Node):
    def __init__(self) -> None:
        super().__init__("drift_joint_teleop")

        self.declare_parameter("arm_namespace", "left_arm")
        self.declare_parameter("leader_twist_topic", "/axe4/eef_twist")
        self.declare_parameter("leader_pose_topic", "/axe4/eef_position")
        self.declare_parameter("teleop_axis", "")
        self.declare_parameter("speed", 1.0)
        self.declare_parameter("twist_rate", 12.0)
        self.declare_parameter("drift_kp", 2.0)
        self.declare_parameter("drift_deadband_m", 0.002)
        self.declare_parameter("max_lin_vel", 0.5)
        self.declare_parameter("max_correction_vel", 0.15)
        self.declare_parameter("max_ang_vel", 0.2)
        self.declare_parameter("lock_joint1", True)
        self.declare_parameter("max_joint_vel_deg", 120.0)
        self.declare_parameter("pose_timeout_sec", 0.15)
        self.declare_parameter("twist_timeout_sec", 0.15)
        self.declare_parameter("use_pose_absolute", False)

        p = self.get_parameter
        self._arm = str(p("arm_namespace").value).strip()
        self._lt = str(p("leader_twist_topic").value).strip()
        self._lp = str(p("leader_pose_topic").value).strip()
        ta = (p("teleop_axis").value or "").strip()
        self._axis = parse_axis_map(ta if ta else axis_map_for_arm(self._arm))
        self._speed = max(0.0, float(p("speed").value))
        self._rate = max(0.0, float(p("twist_rate").value))
        self._kp = max(0.0, float(p("drift_kp").value))
        self._dbd = max(0.0, float(p("drift_deadband_m").value))
        self._max_lin = max(0.0, float(p("max_lin_vel").value))
        self._max_corr = max(0.0, float(p("max_correction_vel").value))
        self._max_ang = max(0.0, float(p("max_ang_vel").value))
        self._lock_j1 = bool(p("lock_joint1").value)
        self._max_jd = max(0.0, float(p("max_joint_vel_deg").value))
        self._pose_t = float(p("pose_timeout_sec").value)
        self._twist_t = float(p("twist_timeout_sec").value)
        self._use_abs = bool(p("use_pose_absolute").value)
        if not self._use_abs and "absolute" in self._lp.lower():
            self._use_abs = True

        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )

        self.create_subscription(TwistStamped, self._lt, self._on_twist, qos)
        self.create_subscription(PoseStamped, self._lp, self._on_pose, qos)
        self.create_subscription(
            PoseStamped, f"/{self._arm}/{self._arm}_driver/out/tool_pose", self._on_tool, qos
        )
        self.create_subscription(
            JointAngles, f"/{self._arm}/{self._arm}_driver/out/joint_angles", self._on_joints, qos
        )

        self._vel_pub = self.create_publisher(
            PoseVelocity, f"/{self._arm}/{self._arm}_driver/in/cartesian_velocity", qos
        )
        self._jvel_pub = self.create_publisher(
            JointVelocity, f"/{self._arm}/{self._arm}_driver/in/joint_velocity", qos
        )

        self._last_twist = time.time()
        self._last_pose = time.time()
        self._leader_abs_ref: list[float] | None = None
        self._leader_rel = [0.0, 0.0, 0.0]
        self._twist_lin = [0.0, 0.0, 0.0]
        self._twist_ang_z = 0.0
        self._robot_home: list[float] | None = None
        self._tool_xyz = [0.0, 0.0, 0.0]
        self._have_tool = False
        self._joint_deg: list[float] | None = None
        self._jvel_stop = 0

        self.create_timer(0.01, self._tick)
        self.get_logger().info(
            f"drift_joint_teleop arm={self._arm} twist={self._lt} pose={self._lp} "
            f"axis={ta or axis_map_for_arm(self._arm)} drift_kp={self._kp}"
        )

    def _on_twist(self, msg: TwistStamped) -> None:
        self._last_twist = time.time()
        self._twist_lin = [msg.twist.linear.x, msg.twist.linear.y, msg.twist.linear.z]
        self._twist_ang_z = msg.twist.angular.z

    def _on_pose(self, msg: PoseStamped) -> None:
        self._last_pose = time.time()
        px = float(msg.pose.position.x)
        py = float(msg.pose.position.y)
        pz = float(msg.pose.position.z)
        if self._use_abs:
            if self._leader_abs_ref is None:
                self._leader_abs_ref = [px, py, pz]
            self._leader_rel = [
                px - self._leader_abs_ref[0],
                py - self._leader_abs_ref[1],
                pz - self._leader_abs_ref[2],
            ]
        else:
            self._leader_rel = [px, py, pz]

    def _on_tool(self, msg: PoseStamped) -> None:
        self._tool_xyz = [
            float(msg.pose.position.x),
            float(msg.pose.position.y),
            float(msg.pose.position.z),
        ]
        self._have_tool = True
        if self._robot_home is None:
            self._robot_home = self._tool_xyz[:]

    def _on_joints(self, msg: JointAngles) -> None:
        self._joint_deg = [
            msg.joint1, msg.joint2, msg.joint3, msg.joint4,
            msg.joint5, msg.joint6, msg.joint7,
        ]

    @staticmethod
    def _clamp(v: float, m: float) -> float:
        return max(min(v, m), -m)

    def _tick(self) -> None:
        now = time.time()
        if now - self._last_twist > self._twist_t:
            self._twist_lin = [0.0, 0.0, 0.0]
            self._twist_ang_z = 0.0
        if now - self._last_pose > self._pose_t:
            self._publish_stop()
            return

        if self._robot_home is None or not self._have_tool:
            return

        # Twist branch (mimic)
        vL = [
            self._clamp(self._rate * self._twist_lin[0], self._max_lin),
            self._clamp(self._rate * self._twist_lin[1], self._max_lin),
            self._clamp(self._rate * self._twist_lin[2], self._max_lin),
        ]
        v_twist = apply_linear(vL, self._axis)

        # Pose-implied target (same construction as position teleop)
        delta_f = apply_linear(self._leader_rel, self._axis)
        p_tgt = [
            self._robot_home[i] + self._speed * delta_f[i]
            for i in range(3)
        ]
        err = [p_tgt[i] - self._tool_xyz[i] for i in range(3)]
        err_db = _deadband_vec(err, self._dbd)
        v_corr = [self._kp * e for e in err_db]
        v_corr = [self._clamp(v_corr[i], self._max_corr) for i in range(3)]

        vx = self._clamp(v_twist[0] + v_corr[0], self._max_lin)
        vy = self._clamp(v_twist[1] + v_corr[1], self._max_lin)
        vz = self._clamp(v_twist[2] + v_corr[2], self._max_lin)
        wz = self._clamp(self._rate * self._twist_ang_z, self._max_ang)

        out6 = [vx, vy, vz, 0.0, 0.0, wz]

        if self._lock_j1:
            self._publish_joint(out6)
        else:
            self._publish_cart(out6)

    def _publish_cart(self, out6: list[float]) -> None:
        m = PoseVelocity()
        m.twist_linear_x = float(out6[0])
        m.twist_linear_y = float(out6[1])
        m.twist_linear_z = float(out6[2])
        m.twist_angular_z = float(out6[5])
        self._vel_pub.publish(m)

    def _publish_joint(self, out6: list[float]) -> None:
        q = self._joint_deg
        if q is None:
            return
        v_cart = np.array([
            out6[0], out6[1], out6[2], 0.0, 0.0, out6[5],
        ], dtype=float)
        if np.max(np.abs(v_cart)) < 1e-9:
            if self._jvel_stop > 0:
                self._jvel_pub.publish(JointVelocity())
                self._jvel_stop -= 1
            return
        dq = cart_to_joint_vel(
            q, v_cart,
            locked_joints=[0],
            max_joint_vel_deg=self._max_jd,
        )
        jm = JointVelocity()
        jm.joint1 = 0.0
        jm.joint2 = float(dq[1])
        jm.joint3 = float(dq[2])
        jm.joint4 = float(dq[3])
        jm.joint5 = float(dq[4])
        jm.joint6 = float(dq[5])
        jm.joint7 = float(dq[6])
        self._jvel_pub.publish(jm)
        self._jvel_stop = 10

    def _publish_stop(self) -> None:
        self._vel_pub.publish(PoseVelocity())
        self._jvel_pub.publish(JointVelocity())


def main(args=None) -> None:
    rclpy.init(args=args)
    node = DriftJointTeleopNode()
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
