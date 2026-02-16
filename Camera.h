
#pragma once

#include "Core.h"
#include "Vector.h"
#include "Matrix.h"

class Camera {
public:
	void resetPosition()           { position.reset(); }
	void setPosition(double3 pos)  { resetPosition(); position.translate(pos); }
	void translate(double3 offset) { position.translate(offset); }
	void moveForward(double distance) {

	}

	void resetDirection()                   { direction.reset(); }
	void setDirection(double3 dir)          { resetDirection(); direction.translate(dir); }
	void rotate(double3 axis, double theta) { direction.rotate(axis, theta); }




	const double4x4 getView() {
		return direction * position;
	}

	const double4x4& getProjection(int width, int height) {
		// this should maybe not be recalculated every time it's called (probably isnt that expensive tho)
		double aspectRatio = (double)width / (double)height;
		double fovRadians = FOV * PI / 180.0;
		double f = 1.0 / tan(fovRadians / 2.0);
		projection.set(
			f / aspectRatio, 0.0, 0.0, 0.0,
			0.0, f, 0.0, 0.0,
			0.0, 0.0, (farPlane + nearPlane) / (nearPlane - farPlane), -1.0,
			0.0, 0.0, (2.0 * farPlane * nearPlane) / (nearPlane - farPlane), 0.0
		);
		return projection;
	}

private:
	double nearPlane = 0.1f;
	double farPlane = 100.0f;
	double FOV = 60.0f;
	double4x4 position;
	double4x4 direction;
	double4x4 projection;
};

