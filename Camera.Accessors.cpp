
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

double& Violet::Camera::getFOV() {
	return m_FOV;
}

double& Violet::Camera::getFarPlane() {
	return m_farPlane;
}

double& Violet::Camera::getNearPlane() {
	return m_nearPlane;
}

