
#pragma once

#include "Core.h"
#include "Matrix.h"

class Camera {
public:
	//double3    getPosition()         const;
	//double3    getRightDirection()   const;
	//double3    getUpDirection()      const;
	//double3    getForwardDirection() const;
	//Quaternion getOrientation()      const;
	//
	//void resetPosition();
	//void resetOrientation();
	//
	//
	//void setPosition(double3 pos);
	//
	//
	//void translate(double3 offset);
	//void moveForward(double dist);
	//void moveRight(double dist);
	//void moveUp(double dist);
	//
	//void setDirection(double3 dir)          { resetDirection(); direction.translate(dir); }
	//void rotate(double3 axis, double theta) { direction.rotate(axis, theta); }

	const double4x4& getViewMatrix() const {
		return viewMatrix;
	}

	const double4x4& getProjectionMatrix(int width, int height) {
		double aspectRatio = (double)width / (double)height;
		double fovRadians = FOV * PI / 180.0;
		double f = 1.0 / tan(fovRadians / 2.0);
		projectionMatrix.set(
			f / aspectRatio, 0.0, 0.0, 0.0,
			0.0, f, 0.0, 0.0,
			0.0, 0.0, (farPlane + nearPlane) / (nearPlane - farPlane),
			(2.0 * farPlane * nearPlane) / (nearPlane - farPlane),
			0.0, 0.0, -1.0, 0.0
		);
		return projectionMatrix;
	}

private:
	double nearPlane = 0.1f;
	double farPlane = 100.0f;
	double FOV = 60.0f;

	//double4x4 viewMatrix;
	//double4x4 viewMatrix;
	double4x4 viewMatrix;
	double4x4 projectionMatrix;
};

