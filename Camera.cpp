
#include "Camera.h"

const Violet::Matrix Violet::Camera::getViewMatrix() const {
	return transformation.getViewMatrix();
}

const Violet::Matrix Violet::Camera::getProjectionMatrix(int width, int height) const {
	if (height == 0)
		height = 1;
	double aspectRatio = (double)width / (double)height;
	double fovRadians = FOV * PI / 180.0;
	double f = 1.0 / tan(fovRadians / 2.0);
	Matrix projectionMatrix(
		f / aspectRatio, 0.0, 0.0, 0.0,
		0.0, f, 0.0, 0.0,
		0.0, 0.0, (farPlane + nearPlane) / (nearPlane - farPlane),
		(2.0 * farPlane * nearPlane) / (nearPlane - farPlane),
		0.0, 0.0, -1.0, 0.0
	);
	return projectionMatrix;
}

