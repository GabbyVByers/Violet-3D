
#pragma once

#include "Violet.h"
#include "Quaternion.h"
#include "Error.h"
#include "Vector3f.h"

class Violet::Vector3d {
public:
	Vector3d(double new_x = 0.0, double new_y = 0.0, double new_z = 0.0);
	void rotate(Vector3d axis, double theta);
	void applyQuaternionRotation(Quaternion quat);
	void normalize();
	Vector3f as_float() const;
	Vector3d operator * (const double scalar) const;
	Vector3d operator + (const Vector3d vector) const;
	void operator += (const Vector3d vector);

	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};

