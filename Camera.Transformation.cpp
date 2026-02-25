
#include "Camera.h"

void Violet::Camera::setPosition(Vector3d position) {
	m_transformation.setPosition(position);
}

void Violet::Camera::setQuaternionRotation(Quaternion quaternion) {
	m_transformation.setQuaternionRotation(quaternion);
}

Violet::Vector3d& Violet::Camera::getPosition() {
	return m_transformation.getPosition();
}

Violet::Quaternion& Violet::Camera::getQuaternionRotation() {
	return m_transformation.getQuaternionRotation();
}

void Violet::Camera::rotateAroundAxis(Vector3d rotation_axis, double theta) {
	m_transformation.rotateAroundAxis(rotation_axis, theta);
}

Violet::Vector3d Violet::Camera::forward() const {
	return m_transformation.forward();
}

Violet::Vector3d Violet::Camera::right() const {
	return m_transformation.right();
}

Violet::Vector3d Violet::Camera::up() const {
	return m_transformation.up();
}

void Violet::Camera::move(Vector3d direction, double distance) {
	m_transformation.move(direction, distance);
}

void Violet::Camera::pitch(double theta) {
	m_transformation.pitch(theta);
}

void Violet::Camera::roll(double theta) {
	m_transformation.roll(theta);
}

void Violet::Camera::yaw(double theta) {
	m_transformation.yaw(theta);
}

