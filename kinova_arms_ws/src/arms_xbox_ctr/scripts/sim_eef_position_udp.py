#!/usr/bin/env python3
"""
Simple end-effector POSITION setpoint simulator for AXE4 UDP input.

This sends absolute pose setpoints as:
  <x, y, z, qw, qx, qy, qz>  (7 x float32, little-endian)

Use with AXE4 bridge in:
  input_mode:=udp
  control_mode:=pose_action
"""

import argparse
import socket
import struct
import time
from typing import List, Tuple


def lerp(a: float, b: float, t: float) -> float:
    return a + (b - a) * t


def send_pose(sock, addr, x, y, z, quat):
    payload = struct.pack("<fffffff", x, y, z, quat[0], quat[1], quat[2], quat[3])
    sock.sendto(payload, addr)


def clamp(v: float, vmin: float, vmax: float) -> float:
    return max(vmin, min(v, vmax))


def clamp_pose(p: List[float], bounds: Tuple[float, float, float, float, float, float]) -> List[float]:
    x_min, x_max, y_min, y_max, z_min, z_max = bounds
    return [
        clamp(p[0], x_min, x_max),
        clamp(p[1], y_min, y_max),
        clamp(p[2], z_min, z_max),
    ]


def move_linear(sock, addr, start, target, quat, duration, rate_hz):
    steps = max(2, int(duration * rate_hz))
    dt = 1.0 / rate_hz
    for i in range(steps):
        t = i / (steps - 1)
        x = lerp(start[0], target[0], t)
        y = lerp(start[1], target[1], t)
        z = lerp(start[2], target[2], t)
        send_pose(sock, addr, x, y, z, quat)
        time.sleep(dt)


def hold_pose(sock, addr, pose, quat, hold_s, rate_hz):
    steps = max(1, int(hold_s * rate_hz))
    dt = 1.0 / rate_hz
    for _ in range(steps):
        send_pose(sock, addr, pose[0], pose[1], pose[2], quat)
        time.sleep(dt)


def main():
    parser = argparse.ArgumentParser(description="Simulate EEF position setpoints over UDP")
    parser.add_argument("--ip", default="127.0.0.1", help="Destination UDP IP")
    parser.add_argument("--port", type=int, default=5005, help="Destination UDP port")
    parser.add_argument("--center-x", type=float, default=0.30, help="Center pose X (m)")
    parser.add_argument("--center-y", type=float, default=0.00, help="Center pose Y (m)")
    parser.add_argument("--center-z", type=float, default=0.38, help="Center pose Z (m)")
    parser.add_argument("--step", type=float, default=0.02, help="Axis excursion in meters")
    parser.add_argument("--move-duration", type=float, default=2.5, help="Seconds per move")
    parser.add_argument("--hold", type=float, default=1.0, help="Hold time at each waypoint")
    parser.add_argument("--rate", type=float, default=30.0, help="Packet send rate (Hz)")
    parser.add_argument("--qw", type=float, default=1.0, help="Orientation qw")
    parser.add_argument("--qx", type=float, default=0.0, help="Orientation qx")
    parser.add_argument("--qy", type=float, default=0.0, help="Orientation qy")
    parser.add_argument("--qz", type=float, default=0.0, help="Orientation qz")
    parser.add_argument("--x-min", type=float, default=0.20, help="Safety clamp min X (m)")
    parser.add_argument("--x-max", type=float, default=0.40, help="Safety clamp max X (m)")
    parser.add_argument("--y-min", type=float, default=-0.15, help="Safety clamp min Y (m)")
    parser.add_argument("--y-max", type=float, default=0.15, help="Safety clamp max Y (m)")
    parser.add_argument("--z-min", type=float, default=0.20, help="Safety clamp min Z (m)")
    parser.add_argument("--z-max", type=float, default=0.50, help="Safety clamp max Z (m)")
    args = parser.parse_args()

    addr = (args.ip, args.port)
    bounds = (args.x_min, args.x_max, args.y_min, args.y_max, args.z_min, args.z_max)
    center = clamp_pose([args.center_x, args.center_y, args.center_z], bounds)
    step = args.step
    quat = [args.qw, args.qx, args.qy, args.qz]

    raw_path = [
        center,
        [center[0] + step, center[1], center[2]],
        [center[0], center[1], center[2] + step],
        [center[0] - step, center[1], center[2]],
        [center[0], center[1], center[2] - step],
        center,
        [center[0], center[1] + step, center[2]],
        [center[0], center[1] - step, center[2]],
        center,
    ]
    path = [clamp_pose(p, bounds) for p in raw_path]

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    print(f"Sending POSITION setpoints to {addr} at {args.rate:.1f} Hz")
    print(
        "Safety bounds: "
        f"x=[{args.x_min:.3f},{args.x_max:.3f}] "
        f"y=[{args.y_min:.3f},{args.y_max:.3f}] "
        f"z=[{args.z_min:.3f},{args.z_max:.3f}]"
    )
    print("Pattern: center,+X,+Z,-X,-Z,center,+Y,-Y,center")

    hold_pose(sock, addr, center, quat, args.hold, args.rate)

    prev = center
    for idx, target in enumerate(path[1:], start=1):
        print(f"Move {idx}: {prev} -> {target}")
        move_linear(sock, addr, prev, target, quat, args.move_duration, args.rate)
        hold_pose(sock, addr, target, quat, args.hold, args.rate)
        prev = target

    print("Position sequence complete.")


if __name__ == "__main__":
    main()
