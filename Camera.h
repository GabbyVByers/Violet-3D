
#pragma once

#include "Core.h"
#include "Matrix.h"
#include "Transformation.h"

class Camera {
public:
	// Transformation
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
	const Matrix getViewMatrix() const;

	// Projection
	double getNearPlane() const;
	double getFarPlane() const;
	double getFOV() const;
	void setNearPlane(const double nearPlane);
	void setFarPlane(const double farPlane);
	void setFOV(const double FOV);
	const Matrix getProjectionMatrix(int width, int height) const;

private:
	double nearPlane = 0.1f;
	double farPlane = 100.0f;
	double FOV = 60.0f;

	Transformation transformation;
};

