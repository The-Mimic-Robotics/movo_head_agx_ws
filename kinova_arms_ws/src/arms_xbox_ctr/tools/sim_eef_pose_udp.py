#!/usr/bin/env python3
"""
Simple end-effector pose simulator for AXE4 UDP input testing.

Pattern (relative to center):
  center -> +X -> -X -> center -> +Z -> -Z -> center -> +Y -> -Y -> center
"""

import argparse
import socket
import struct
import time


def lerp(a: float, b: float, t: float) -> float:
    return a + (b - a) * t


def send_pose(sock, addr, x, y, z, quat):
    payload = struct.pack("<fffffff", x, y, z, quat[0], quat[1], quat[2], quat[3])
    sock.sendto(payload, addr)


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
    parser = argparse.ArgumentParser(description="Simulate EEF poses over UDP")
    parser.add_argument("--ip", default="127.0.0.1", help="Destination UDP IP")
    parser.add_argument("--port", type=int, default=5005, help="Destination UDP port")
    parser.add_argument("--center-x", type=float, default=0.30, help="Center pose X (m)")
    parser.add_argument("--center-y", type=float, default=0.00, help="Center pose Y (m)")
    parser.add_argument("--center-z", type=float, default=0.40, help="Center pose Z (m)")
    parser.add_argument("--step", type=float, default=0.10, help="Axis excursion in meters")
    parser.add_argument("--move-duration", type=float, default=1.5, help="Seconds per move")
    parser.add_argument("--hold", type=float, default=0.7, help="Hold time at each waypoint")
    parser.add_argument("--rate", type=float, default=50.0, help="Packet send rate (Hz)")
    args = parser.parse_args()

    addr = (args.ip, args.port)
    center = [args.center_x, args.center_y, args.center_z]
    step = args.step
    quat = [1.0, 0.0, 0.0, 0.0]  # identity orientation

    path = [
        center,
        [center[0] + step, center[1], center[2]],
        [center[0] - step, center[1], center[2]],
        center,
        [center[0], center[1], center[2] + step],
        [center[0], center[1], center[2] - step],
        center,
        [center[0], center[1] + step, center[2]],
        [center[0], center[1] - step, center[2]],
        center,
    ]

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    print(f"Sending to {addr} at {args.rate:.1f} Hz")
    print("Pattern: center,+X,-X,center,+Z,-Z,center,+Y,-Y,center")

    # Prime with center
    hold_pose(sock, addr, center, quat, args.hold, args.rate)

    prev = center
    for idx, target in enumerate(path[1:], start=1):
        print(f"Move {idx}: {prev} -> {target}")
        move_linear(sock, addr, prev, target, quat, args.move_duration, args.rate)
        hold_pose(sock, addr, target, quat, args.hold, args.rate)
        prev = target

    print("Sequence complete.")


if __name__ == "__main__":
    main()
