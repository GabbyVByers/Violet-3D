
#include "Transformation.h"

void Violet::Transformation::setScale(double scale) {
	m_scale = scale;
}

void Violet::Transformation::setPosition(Vector3d position) {
	m_position = position;
}

void Violet::Transformation::setQuaternionRotation(Quaternion quaternion) {
	m_quaternion = quaternion;
}

double& Violet::Transformation::getScale() {
	return m_scale;
}

Violet::Vector3d& Violet::Transformation::getPosition() {
	return m_position;
}

Violet::Quaternion& Violet::Transformation::getQuaternionRotation() {
	return m_quaternion;
}

