
#include "Camera.h"

Violet::Matrix Violet::Camera::calculateViewMatrix() const {
	return m_transformation.calculateViewMatrix();
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

