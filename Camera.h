
#pragma once

#include "Core.h"
#include "Vector.h"
#include "Matrix.h"

class Camera {
public:
	double3 getPosition()         { return { viewMatrix[0][3], viewMatrix[1][3], viewMatrix[2][3] }; }
	double3 getForwardDirection() { return {-viewMatrix[2][0],-viewMatrix[2][1],-viewMatrix[2][2] }; }
	double3 getRightDirection()   { return { viewMatrix[0][0], viewMatrix[0][1], viewMatrix[0][2] }; }
	double3 getUpDirection()      { return { viewMatrix[1][0], viewMatrix[1][1], viewMatrix[1][2] }; }

	void resetPosition()           { viewMatrix[3][0] = 0.0; viewMatrix[3][1] = 0.0; viewMatrix[3][2] = 0.0; }
	void setPosition(double3 pos)  { resetPosition(); viewMatrix.translate(pos * -1.0); }
	void translate(double3 offset) { viewMatrix.translate(offset * -1.0); }
	void moveForward(double dist)  { double3 dir = getForwardDirection(); dir.normalize(); translate(dir * dist); }
	void moveRight(double dist)    { double3 dir = getRightDirection();   dir.normalize(); translate(dir * dist); }
	void moveUp(double dist)       { double3 dir = getUpDirection();      dir.normalize(); translate(dir * dist); }
	
	//void resetDirection()                   { direction.reset(); }
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
			0.0, 0.0, (farPlane + nearPlane) / (nearPlane - farPlane), -1.0,
			0.0, 0.0, (2.0 * farPlane * nearPlane) / (nearPlane - farPlane), 0.0
		);
		return projectionMatrix;
	}

private:
	double nearPlane = 0.1f;
	double farPlane = 100.0f;
	double FOV = 60.0f;
	double4x4 viewMatrix;
	double4x4 projectionMatrix;
};

