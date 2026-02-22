
#pragma once

#include "Violet.h"
#include "Vector.h"
#include "Matrix.h"

class Violet::Transformation {
public:
	void resetOrientation();
	void rotate(Vector3d rot_axis, double theta);
	void pitch(double theta);
	void roll(double theta);
	void yaw(double theta);
	Vector3d forward() const;
	Vector3d right() const;
	Vector3d up() const;
	void moveForward(double dist);
	void moveRight(double dist);
	void moveUp(double dist);
	Matrix getModelMatrix() const;
	Matrix getViewMatrix() const;

	double scale           = 1.0;
	Vector3d position      = { 0.0, 0.0, 0.0 };
	Quaternion orientation = { 1.0, 0.0, 0.0, 0.0 };
};

