
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

double Violet::Transformation::getScale() const {
	return m_scale;
}

Violet::Vector3d Violet::Transformation::getPosition() const {
	return m_position;
}

Violet::Quaternion Violet::Transformation::getQuaternionRotation() const {
	return m_quaternion;
}

