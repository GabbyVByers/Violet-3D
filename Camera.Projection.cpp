
#include "Camera.h"

double Camera::getNearPlane() const {
	return this->nearPlane;
}

double Camera::getFarPlane() const {
	return this->farPlane;
}

double Camera::getFOV() const {
	return this->FOV;
}

void Camera::setNearPlane(const double nearPlane) {
	this->nearPlane = nearPlane;
}

void Camera::setFarPlane(const double farPlane) {
	this->farPlane = farPlane;
}

void Camera::setFOV(const double FOV) {
	this->FOV = FOV;
}

const Matrix Camera::getProjectionMatrix(int width, int height) const {
	double aspectRatio = (double)width / (double)height;
	double fovRadians = this->FOV * PI / 180.0;
	double f = 1.0 / tan(fovRadians / 2.0);
	Matrix projectionMatrix(
		f / aspectRatio, 0.0, 0.0, 0.0,
		0.0, f, 0.0, 0.0,
		0.0, 0.0, (this->farPlane + this->nearPlane) / (this->nearPlane - this->farPlane),
		(2.0 * this->farPlane * this->nearPlane) / (this->nearPlane - this->farPlane),
		0.0, 0.0, -1.0, 0.0
	);
	return projectionMatrix;
}

