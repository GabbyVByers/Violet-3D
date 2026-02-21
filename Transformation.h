
#pragma once

#include "Violet.h"
#include "Vector3d.h"
#include "Matrix.h"

class Violet::Transformation {
public:
	void reScale(double scale);
	void setScale(double scale);
	double getScale() const;
	void moveForward(double dist);
	void moveRight(double dist);
	void moveUp(double dist);
	void move(Vector3d position);
	void setPosX(double new_x);
	void setPosY(double new_y);
	void setPosZ(double new_z);
	void setPosition(Vector3d position);
	Vector3d getPosition() const;
	void resetOrientation();
	void rotate(Vector3d rot_axis, double theta);
	void pitch(double theta);
	void roll(double theta);
	void yaw(double theta);
	Vector3d getForwardDirection() const;
	Vector3d getRightDirection() const;
	Vector3d getUpDirection() const;
	const Matrix getModelMatrix() const;
	const Matrix getViewMatrix() const;

private:
	double scale           = 1.0;
	Vector3d position      = { 0.0, 0.0, 0.0 };
	Quaternion orientation = { 1.0, 0.0, 0.0, 0.0 };
};

