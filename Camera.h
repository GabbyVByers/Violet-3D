
#pragma once

#include "Core.h"
#include "Vector.h"
#include "Matrix.h"

class Camera {
public:
	const double4x4& getView() {
		return view;
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
	double4x4 view;
	double4x4 projection;
};

