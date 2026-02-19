
#pragma once

#include "Core.h"
#include "Quaternions.h"
#include "Float3.h"

class double3 {
public:
	double3(double x = 0.0, double y = 0.0, double z = 0.0);
	void rotate(double3 axis, double theta);
	void normalize();
	float3 as_float() const;
	double3 operator * (const double scalar) const;
	double3 operator + (const double3 vector) const;

	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};

