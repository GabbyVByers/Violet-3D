
#pragma once

#include "Violet.h"
#include "Vector.h"
#include "Matrix.h"

class Violet::Transformation {
public:
	// Transformation.Accessors.cpp
	void setScale(double scale);
	void setPosition(Vector3d position);
	void setQuaternionRotation(Quaternion quaternion);
	double& getScale();
	Vector3d& getPosition();
	Quaternion& getQuaternionRotation();

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
	Vector3d m_position = Vector3d::ZERO();
	Quaternion m_quaternion = Quaternion::Identity();
};

