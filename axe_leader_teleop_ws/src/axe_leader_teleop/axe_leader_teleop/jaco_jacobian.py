"""
Jaco 7-DOF Jacobian computation using official Kinova DH parameters.

DH parameters are taken directly from kinova_arm_kinematics.cpp in the
kinova-ros driver (j2s7 section).  No URDF parsing needed — the same
numbers the arm's DSP chip uses for its own FK.

Provides:
    cart_to_joint_vel(q_deg, v_cart, locked_joints)
        → joint velocity array (deg/s) with chosen joints forced to zero.
"""

import math
import numpy as np

_PI = math.pi

# ── Link lengths (m) — j2s7 from kinova_arm_kinematics.cpp ──────────
_D1 = 0.2755
_D2 = 0.205
_D3 = 0.205
_D4 = 0.2073
_D5 = 0.1038
_D6 = 0.1038
_D7 = 0.160
_E2 = 0.0098

# ── Classical DH table ──────────────────────────────────────────────
#       a        d                      alpha       θ_sign   θ_offset
_DH = [
    (0.0, -_D1,              _PI / 2,  -1, 0.0),
    (0.0,  0.0,              _PI / 2,   1, 0.0),
    (0.0, -(_D2 + _D3),      _PI / 2,   1, 0.0),
    (0.0, -_E2,              _PI / 2,   1, 0.0),
    (0.0, -(_D4 + _D5),      _PI / 2,   1, 0.0),
    (0.0,  0.0,              _PI / 2,   1, 0.0),
    (0.0, -(_D6 + _D7),      _PI,       1, 0.0),
]

_N_JOINTS = 7
_DEFAULT_MAX_JOINT_VEL_DEG = 45.0  # Kinova spec: ~40 deg/s big joints, ~53 deg/s wrist


def _dh_matrix(d: float, theta: float, a: float, alpha: float) -> np.ndarray:
    ct, st = math.cos(theta), math.sin(theta)
    ca, sa = math.cos(alpha), math.sin(alpha)
    return np.array([
        [ct, -st * ca,  st * sa, a * ct],
        [st,  ct * ca, -ct * sa, a * st],
        [0.0, sa,       ca,      d],
        [0.0, 0.0,      0.0,     1.0],
    ])


def forward_kinematics(q_deg: list[float]) -> np.ndarray:
    """Return 4x4 homogeneous transform from base to EE.

    q_deg: 7 joint angles in degrees (Kinova API convention).
    """
    T = _dh_matrix(0, 0, 0, _PI)  # j2s7 base frame rotation
    for i in range(7):
        a_i, d_i, alpha_i, sign_i, off_i = _DH[i]
        theta_i = sign_i * math.radians(q_deg[i]) + off_i
        T = T @ _dh_matrix(d_i, theta_i, a_i, alpha_i)
    return T


def jacobian(q_deg: list[float], eps_deg: float = 0.01) -> np.ndarray:
    """Numerical 6x7 Jacobian (base frame) at the given joint angles.

    Rows 0-2: linear velocity (m/s per rad/s).
    Rows 3-5: angular velocity (rad/s per rad/s).
    """
    T0 = forward_kinematics(q_deg)
    p0, R0 = T0[:3, 3], T0[:3, :3]
    eps_rad = math.radians(eps_deg)

    J = np.zeros((6, _N_JOINTS))
    for j in range(_N_JOINTS):
        q_pert = list(q_deg)
        q_pert[j] += eps_deg
        Tp = forward_kinematics(q_pert)

        J[:3, j] = (Tp[:3, 3] - p0) / eps_rad

        dR = Tp[:3, :3] @ R0.T
        J[3:, j] = np.array([
            dR[2, 1] - dR[1, 2],
            dR[0, 2] - dR[2, 0],
            dR[1, 0] - dR[0, 1],
        ]) / (2.0 * eps_rad)

    return J


def cart_to_joint_vel(
    q_deg: list[float],
    v_cart: np.ndarray,
    locked_joints: list[int] | None = None,
    max_joint_vel_deg: float = _DEFAULT_MAX_JOINT_VEL_DEG,
) -> np.ndarray:
    """Convert a 6D Cartesian velocity to 7 joint velocities (deg/s).

    Locked joints are excluded from the Jacobian pseudo-inverse so they
    stay exactly at zero — the remaining joints absorb the full motion.

    Args:
        q_deg:  current joint angles (degrees, Kinova convention).
        v_cart: desired [vx, vy, vz, wx, wy, wz] in base frame (m/s, rad/s).
        locked_joints: list of 0-indexed joint indices to lock (default [0]).
        max_joint_vel_deg: per-joint velocity clamp for safety.

    Returns:
        7-element array of joint velocities in deg/s.
    """
    if locked_joints is None:
        locked_joints = [0]

    J_full = jacobian(q_deg)

    free = [j for j in range(_N_JOINTS) if j not in locked_joints]
    J_free = J_full[:, free]

    dq_free_rad = np.linalg.pinv(J_free) @ v_cart
    dq_free_deg = np.degrees(dq_free_rad)

    dq_deg = np.zeros(_N_JOINTS)
    for idx, j in enumerate(free):
        dq_deg[j] = dq_free_deg[idx]

    # Safety clamp: if any joint exceeds limit, scale everything down
    peak = np.max(np.abs(dq_deg))
    if peak > max_joint_vel_deg:
        dq_deg *= max_joint_vel_deg / peak

    return dq_deg
