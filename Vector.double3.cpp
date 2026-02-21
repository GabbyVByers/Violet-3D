
#include "Vector3d.h"

Violet::Vector3d::Vector3d(double new_x, double new_y, double new_z) {
	x = new_x;
	y = new_y;
	z = new_z;
}

void Violet::Vector3d::rotate(Vector3d axis, double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	applyQuaternionRotation(quat);
}

void Violet::Vector3d::applyQuaternionRotation(Quaternion quat) {
	Quaternion quat_inv = { quat.w, -quat.x, -quat.y, -quat.z };
	Quaternion p = { 0.0, x, y, z };
	Quaternion result = quat * p * quat_inv;
	x = result.x;
	y = result.y;
	z = result.z;
}

void Violet::Vector3d::normalize() {
	double length = sqrt((x * x) + (y * y) + (z * z));
	if (length == 0.0) {
		error(NORMALIZE_VECTOR_LENGTH_ZERO);
		return;
	}
	x = x /  length;
	y = y /  length;
	z = z /  length;
}

Violet::Vector3f Violet::Vector3d::as_float() const {
	return {
		(float)x,
		(float)y,
		(float)z
	};
}

Violet::Vector3d Violet::Vector3d::operator * (const double scalar) const {
	return { x * scalar, y * scalar, z * scalar };
}

Violet::Vector3d Violet::Vector3d::operator + (const Vector3d vector) const {
	return { x + vector.x, y + vector.y, z + vector.z };
}

