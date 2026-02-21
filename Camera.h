
#pragma once

#include "Violet.h"
#include "Matrix.h"
#include "Transformation.h"

class Violet::Camera {
public:
	// Transformation
	void moveForward(double dist);
	void moveRight(double dist);
	void moveUp(double dist);
	void move(Vector3d position);
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
	const Matrix getViewMatrix() const;

	// Projection
	double getNearPlane() const;
	double getFarPlane() const;
	double getFOV() const;
	void setNearPlane(const double new_nearPlane);
	void setFarPlane(const double new_farPlane);
	void setFOV(const double new_FOV);
	const Matrix getProjectionMatrix(int width, int height) const;

private:
	double nearPlane = 0.1f;
	double farPlane = 100.0f;
	double FOV = 60.0f;

	Transformation transformation;
};

