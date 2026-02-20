
#include "Double3.h"

double3::double3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void double3::rotate(double3 axis, double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	this->applyQuaternionRotation(quat);
}

void double3::applyQuaternionRotation(Quaternion quat) {
	Quaternion quat_inv = { quat.w, -quat.x, -quat.y, -quat.z };
	Quaternion p = { 0.0, this->x, this->y, this->z };
	Quaternion result = quat * p * quat_inv;
	this->x = result.x;
	this->y = result.y;
	this->z = result.z;
}

void double3::normalize() {
	double length = sqrt((x * x) + (y * y) + (z * z));
	if (length == 0.0) {
		error(NORMALIZE_VECTOR_LENGTH_ZERO);
		return;
	}
	this->x = this->x /  length;
	this->y = this->y /  length;
	this->z = this->z /  length;
}

float3 double3::as_float() const {
	return {
		(float)this->x,
		(float)this->y,
		(float)this->z
	};
}

double3 double3::operator * (const double scalar) const {
	return { this->x * scalar, this->y * scalar, this->z * scalar };
}

double3 double3::operator + (const double3 vector) const {
	return { this->x + vector.x, this->y + vector.y, this->z + vector.z };
}

