
#pragma once

#include "Core.h"
#include "Vector.h"
#include "Matrix.h"

class Violet::Transformation {
public:
	// Special Member Functions
	Transformation() = default;
	Transformation(const Transformation&) = default;
	Transformation(Transformation&&) = default;
	Transformation& operator=(const Transformation&) = default;
	Transformation& operator=(Transformation&&) = default;
	~Transformation() = default;

	// Transformation.Accessors.cpp
	void setScale(double scale);
	void setPosition(Vector3d position);
	void setQuaternionRotation(Quaternion quaternion);
	double getScale() const;
	Vector3d getPosition() const;
	Quaternion getQuaternionRotation() const;

	// Transformation.Utilities.cpp
	void rotateAroundAxis(Vector3d rotation_axis, double theta);
	Vector3d forward() const;
	Vector3d right() const;
	Vector3d up() const;
	void move(Vector3d direction, double distance);
	void pitch(double theta);
	void roll(double theta);
	void yaw(double theta);
	Matrix calculateModelMatrix() const;
	Matrix calculateViewMatrix() const;

private:
	double m_scale = 1.0;
	Vector3d m_position = Vector3d::Zero();
	Quaternion m_quaternion = Quaternion::Identity();
};

