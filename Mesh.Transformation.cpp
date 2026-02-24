
#include "Mesh.h"

void Violet::Mesh::setScale(double scale) {
	m_transformation.setScale(scale);
}

void Violet::Mesh::setPosition(Vector3d position) {
	m_transformation.setPosition(position);
}

void Violet::Mesh::setQuaternionRotation(Quaternion quaternion) {
	m_transformation.setQuaternionRotation(quaternion);
}

double& Violet::Mesh::getScale() {
	return m_transformation.getScale();
}

Violet::Vector3d& Violet::Mesh::getPosition() {
	return m_transformation.getPosition();
}

Violet::Quaternion& Violet::Mesh::getQuaternionRotation() {
	return m_transformation.getQuaternionRotation();
}

void Violet::Mesh::rotateAroundAxis(Vector3d rotation_axis, double theta) {
	m_transformation.rotateAroundAxis(rotation_axis, theta);
}

Violet::Vector3d Violet::Mesh::forward() const {
	return m_transformation.forward();
}

Violet::Vector3d Violet::Mesh::right() const {
	return m_transformation.right();
}

Violet::Vector3d Violet::Mesh::up() const {
	return m_transformation.up();
}

void Violet::Mesh::move(Vector3d direction, double distance) {
	m_transformation.move(direction, distance);
}

void Violet::Mesh::pitch(double theta) {
	m_transformation.pitch(theta);
}

void Violet::Mesh::roll(double theta) {
	m_transformation.roll(theta);
}

void Violet::Mesh::yaw(double theta) {
	m_transformation.yaw(theta);
}

const Violet::Matrix Violet::Mesh::calculateModelMatrix() const {
	return m_transformation.calculateModelMatrix();
}

