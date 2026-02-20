
#pragma once

#include "Core.h"
#include "Matrix.h"
#include "Transformation.h"

class Camera {
public:
	const Matrix getViewMatrix() const;
	const Matrix getProjectionMatrix(int width, int height) const;

private:
	double nearPlane = 0.1f;
	double farPlane = 100.0f;
	double FOV = 60.0f;

	Transformation transformation;
};

