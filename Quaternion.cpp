
#include "Quaternion.h"

void Violet::Quaternion::normalize() {
    double length = sqrt(w * w + x * x + y * y + z * z);
    if (length == 0.0) {
        error(NORMALIZE_VECTOR_LENGTH_ZERO);
        return;
    }
    w = w / length;
    x = x / length;
    y = y / length;
    z = z / length;
}

Violet::Quaternion Violet::Quaternion::buildRotationQuaternion(Vector3d axis, double theta) {
    axis.normalize();
    double half = theta * 0.5;
    double s = sin(half);
    Quaternion quat = { cos(half), s * axis.x, s * axis.y, s * axis.z };
    return quat;
}

Violet::Quaternion Violet::Quaternion::operator * (const Quaternion & b) const {
    return {
        (w * b.w) - (x * b.x) - (y * b.y) - (z * b.z),
        (w * b.x) + (x * b.w) + (y * b.z) - (z * b.y),
        (w * b.y) - (x * b.z) + (y * b.w) + (z * b.x),
        (w * b.z) + (x * b.y) - (y * b.x) + (z * b.w)
    };
}

