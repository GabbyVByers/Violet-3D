
#include "Camera.h"

double Violet::Camera::getNearPlane() const {
	return nearPlane;
}

double Violet::Camera::getFarPlane() const {
	return farPlane;
}

double Violet::Camera::getFOV() const {
	return FOV;
}

void Violet::Camera::setNearPlane(const double new_nearPlane) {
	nearPlane = new_nearPlane;
}

void Violet::Camera::setFarPlane(const double new_farPlane) {
	farPlane = new_farPlane;
}

void Violet::Camera::setFOV(const double new_FOV) {
	FOV = new_FOV;
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

