
#pragma once

#include "Core.h"
#include "Quaternion.h"
#include "Vector.float3.h"
#include "Error.h"

class double3 {
public:
	double3(double x = 0.0, double y = 0.0, double z = 0.0);
	void rotate(double3 axis, double theta);
	void applyQuaternionRotation(Quaternion quat);
	void normalize();
	float3 as_float() const;
	double3 operator * (const double scalar) const;
	double3 operator + (const double3 vector) const;

	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};

