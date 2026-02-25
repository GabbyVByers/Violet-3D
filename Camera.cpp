
#include "Camera.h"

void Violet::Camera::setFOV(double FOV) {
	m_FOV = FOV;
}

void Violet::Camera::setFarPlane(double farPlane) {
	m_farPlane = farPlane;
}

void Violet::Camera::setNearPlane(double nearPlane) {
	m_nearPlane = nearPlane;
}

double Violet::Camera::getFOV() const {
	return m_FOV;
}

double Violet::Camera::getFarPlane() const {
	return m_farPlane;
}

double Violet::Camera::getNearPlane() const {
	return m_nearPlane;
}

Violet::Matrix Violet::Camera::calculateProjectionMatrix(int width, int height) const {
	if (height == 0)
		height = 1;
	double aspectRatio = (double)width / (double)height;
	double fovRadians = m_FOV * PI / 180.0;
	double f = 1.0 / tan(fovRadians / 2.0);
	Matrix projectionMatrix(
		f / aspectRatio, 0.0, 0.0, 0.0,
		0.0, f, 0.0, 0.0,
		0.0, 0.0, (m_farPlane + m_nearPlane) / (m_nearPlane - m_farPlane),
		(2.0 * m_farPlane * m_nearPlane) / (m_nearPlane - m_farPlane),
		0.0, 0.0, -1.0, 0.0
	);
	return projectionMatrix;
}

