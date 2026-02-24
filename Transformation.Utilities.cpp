
#include "Transformation.h"

void Violet::Transformation::rotateAroundAxis(Vector3d rotation_axis, double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(rotation_axis, theta);
	m_quaternion = quat * m_quaternion;
	m_quaternion.normalize();
}

Violet::Vector3d Violet::Transformation::forward() const {
	Vector3d forward_basis = { 0.0, 0.0, -1.0 };
	forward_basis.applyQuaternionRotation(m_quaternion);
	forward_basis.normalize();
	return forward_basis;
}

Violet::Vector3d Violet::Transformation::right() const {
	Vector3d right_basis = { 1.0, 0.0, 0.0 };
	right_basis.applyQuaternionRotation(m_quaternion);
	right_basis.normalize();
	return right_basis;
}

Violet::Vector3d Violet::Transformation::up() const {
	Vector3d up_basis = { 0.0, 1.0, 0.0 };
	up_basis.applyQuaternionRotation(m_quaternion);
	up_basis.normalize();
	return up_basis;
}

void Violet::Transformation::move(Vector3d direction, double distance) {
	m_position += (direction * distance);
}

void Violet::Transformation::pitch(const double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(right(), theta);
	m_quaternion = quat * m_quaternion;
	m_quaternion.normalize();
}

void Violet::Transformation::roll(const double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(forward(), theta);
	m_quaternion = quat * m_quaternion;
	m_quaternion.normalize();
}

void Violet::Transformation::yaw(const double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(up(), -theta);
	m_quaternion = quat * m_quaternion;
	m_quaternion.normalize();
}

Violet::Matrix Violet::Transformation::calculateModelMatrix() const {
	Matrix scalarMatrix = Matrix::buildScalarMatrix(m_scale);
	Matrix translationMatrix = Matrix::buildTranslationMatrix(m_position);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix(m_quaternion);
	return translationMatrix * scalarMatrix * quaternionRotationMatrix;
}

Violet::Matrix Violet::Transformation::calculateViewMatrix() const {
	Matrix translationMatrix = Matrix::buildTranslationMatrix(m_position * -1.0);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix({ m_quaternion.w, -m_quaternion.x, -m_quaternion.y, -m_quaternion.z });
	return quaternionRotationMatrix * translationMatrix;
}

