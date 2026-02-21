
#pragma once

#include "Violet.h"
#include "Vector3d.h"
#include "Matrix.h"

class Violet::Transformation {
public:
	double& borrowScale();
	Vector3d& borrowPosition();
	void resetOrientation();
	void rotate(Vector3d rot_axis, double theta);
	void pitch(double theta);
	void roll(double theta);
	void yaw(double theta);
	Vector3d forwardDir() const;
	Vector3d rightDir() const;
	Vector3d upDir() const;
	const Matrix getModelMatrix() const;
	const Matrix getViewMatrix() const;

private:
	double scale           = 1.0;
	Vector3d position      = { 0.0, 0.0, 0.0 };
	Quaternion orientation = { 1.0, 0.0, 0.0, 0.0 };
};

