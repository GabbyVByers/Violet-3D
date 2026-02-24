
#pragma once

#include "Core.h"
#include "Quaternion.h"

struct Violet::Vector2i;
struct Violet::Vector2f;
struct Violet::Vector2d;
struct Violet::Vector3f;
struct Violet::Vector3d;

struct Violet::Vector2i {
	int x = 0;
	int y = 0;
};

struct Violet::Vector2f {
	float x = 0.0f;
	float y = 0.0f;
};

struct Violet::Vector2d {
	double x = 0.0;
	double y = 0.0;
};

struct Violet::Vector3f {
	// Vector.Vector3f.cpp
	Vector3f() = default;
	Vector3f(float x, float y, float z);
	Vector3d as_double() const;

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

struct Violet::Vector3d {
	// Vector.Vector3d.cpp
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

