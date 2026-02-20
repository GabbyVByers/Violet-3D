
#include "Vector.double3.h"

double3::double3(double new_x, double new_y, double new_z) {
	x = new_x;
	y = new_y;
	z = new_z;
}

void double3::rotate(double3 axis, double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	applyQuaternionRotation(quat);
}

void double3::applyQuaternionRotation(Quaternion quat) {
	Quaternion quat_inv = { quat.w, -quat.x, -quat.y, -quat.z };
	Quaternion p = { 0.0, x, y, z };
	Quaternion result = quat * p * quat_inv;
	x = result.x;
	y = result.y;
	z = result.z;
}

void double3::normalize() {
	double length = sqrt((x * x) + (y * y) + (z * z));
	if (length == 0.0) {
		error(NORMALIZE_VECTOR_LENGTH_ZERO);
		return;
	}
	x = x /  length;
	y = y /  length;
	z = z /  length;
}

float3 double3::as_float() const {
	return {
		(float)x,
		(float)y,
		(float)z
	};
}

double3 double3::operator * (const double scalar) const {
	return { x * scalar, y * scalar, z * scalar };
}

double3 double3::operator + (const double3 vector) const {
	return { x + vector.x, y + vector.y, z + vector.z };
}

