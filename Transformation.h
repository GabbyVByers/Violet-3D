
#pragma once

#include "Core.h"
#include "Vector.double3.h"
#include "Matrix.h"

class Transformation {
public:
	void reScale(double scale);
	void setScale(double scale);
	double getScale() const;
	void moveForward(double dist);
	void moveRight(double dist);
	void moveUp(double dist);
	void move(double3 position);
	void setPosition(double3 position);
	double3 getPosition() const;
	void resetOrientation();
	void rotate(double3 rot_axis, double theta);
	void pitch(double theta);
	void roll(double theta);
	void yaw(double theta);
	double3 getForwardDirection() const;
	double3 getRightDirection() const;
	double3 getUpDirection() const;
	const Matrix getModelMatrix() const;
	const Matrix getViewMatrix() const;

private:
	double scale           = 1.0;
	double3 position       = { 0.0, 0.0, 0.0 };
	Quaternion orientation = { 1.0, 0.0, 0.0, 0.0 };
};

