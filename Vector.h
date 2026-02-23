
#pragma once

#include "Violet.h"
#include "Quaternion.h"

class Violet::Vector2i;
class Violet::Vector2f;
class Violet::Vector2d;
class Violet::Vector3f;
class Violet::Vector3d;

class Violet::Vector2i {
public:
	int x = 0;
	int y = 0;
};

class Violet::Vector2f {
public:
	float x = 0.0f;
	float y = 0.0f;
};

class Violet::Vector2d {
public:
	double x = 0.0;
	double y = 0.0;
};

class Violet::Vector3f {
public:
	Vector3f() = default;
	Vector3f(float x, float y, float z);
	Vector3d as_double() const;

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

class Violet::Vector3d {
public:
	Vector3d() = default;
	Vector3d(double x, double y, double z);
	void rotate(Vector3d axis, double theta);
	void applyQuaternionRotation(Quaternion quat);
	void normalize();
	Vector3f as_float() const;

	static Vector3d ZERO();
	Vector3d operator *  (const double    scalar) const;
	Vector3d operator +  (const Vector3d& vector) const;
	void     operator += (const Vector3d& vector);

	double x = 0.0;
	double y = 0.0;
	double z = 0.0;
};

