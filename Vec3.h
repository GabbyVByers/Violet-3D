
#pragma once

#include "Core.h"
#include "Quaternions.h"

class double3 {
public:
	double x = 0.0;
	double y = 0.0;
	double z = 0.0;

	double3(double x = 0.0,
		    double y = 0.0,
		    double z = 0.0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void rotate(double3 axis, double theta) {
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

	void normalize() {
		double len = sqrt((x * x) + (y * y) + (z * z));
		this->x /= len;
		this->y /= len;
		this->z /= len;
	}

	double3 operator*(const double scalar) const {
		return { this->x * scalar, this->y * scalar, this->z * scalar };
	}
};

class float3 {
public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	float3(float x = 0.0f,
		   float y = 0.0f,
		   float z = 0.0f) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

