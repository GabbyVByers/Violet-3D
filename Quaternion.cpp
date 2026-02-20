
#include "Quaternion.h"

void Quaternion::normalize() {
    double length = this->length();
    if (length == 0.0) {
        error(NORMALIZE_VECTOR_LENGTH_ZERO);
        return;
    }
    this->w = this->w / length;
    this->x = this->x / length;
    this->y = this->y / length;
    this->z = this->z / length;
}

double Quaternion::length() const {
    return sqrt(
        this->w * this->w +
        this->x * this->x +
        this->y * this->y +
        this->z * this->z
    );
}

Quaternion Quaternion::buildRotationQuaternion(double3 axis, double theta) {
    axis.normalize();
    double half = theta * 0.5;
    double s = sin(half);
    Quaternion quat = { cos(half), s * axis.x, s * axis.y, s * axis.z };
    return quat;
}

Quaternion Quaternion::operator * (const Quaternion & b) const {
    return {
        (this->w * b.w) - (this->x * b.x) - (this->y * b.y) - (this->z * b.z),
        (this->w * b.x) + (this->x * b.w) + (this->y * b.z) - (this->z * b.y),
        (this->w * b.y) - (this->x * b.z) + (this->y * b.w) + (this->z * b.x),
        (this->w * b.z) + (this->x * b.y) - (this->y * b.x) + (this->z * b.w)
    };
}

