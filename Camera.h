
#pragma once

#include "Violet.h"
#include "Matrix.h"
#include "Transformation.h"

class Violet::Camera {
public:
	const Matrix getViewMatrix() const;
	const Matrix getProjectionMatrix(int width, int height) const;

	double nearPlane = 0.1;
	double farPlane  = 100.0;
	double FOV       = 60.0;
	Transformation transformation;
};

