
#include "Double3.h"

double3::double3(double x, double y, double z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void double3::rotate(double3 axis, double theta) {
	axis.normalize();
	double half = theta * 0.5;
	double s = sin(half);

	Quaternion q = { cos(half), axis.x * s, axis.y * s, axis.z * s };
	Quaternion qinv = { q.w, -q.x, -q.y, -q.z };
	Quaternion p = { 0.0, this->x, this->y, this->z };
	Quaternion qp = q * p;
	Quaternion result = qp * qinv;

	this->x = result.x;
	this->y = result.y;
	this->z = result.z;
}

void double3::normalize() {
	double len = sqrt((x * x) + (y * y) + (z * z));
	this->x /= len;
	this->y /= len;
	this->z /= len;
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

