
#include "Transformation.h"

void Violet::Transformation::resetOrientation() {
	orientation = { 1.0, 0.0, 0.0, 0.0 };
}

void Violet::Transformation::rotate(Vector3d axis, double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Violet::Transformation::pitch(double theta) {
	Vector3d axis = right();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Violet::Transformation::roll(double theta) {
	Vector3d axis = forward();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Violet::Transformation::yaw(double theta) {
	Vector3d axis = up();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, -theta);
	orientation = quat * orientation;
	orientation.normalize();
}

Violet::Vector3d Violet::Transformation::forward() const {
	Vector3d forward_basis = { 0.0, 0.0, -1.0 };
	forward_basis.applyQuaternionRotation(orientation);
	forward_basis.normalize();
	return forward_basis;
}

Violet::Vector3d Violet::Transformation::right() const {
	Vector3d right_basis = { 1.0, 0.0, 0.0 };
	right_basis.applyQuaternionRotation(orientation);
	right_basis.normalize();
	return right_basis;
}

Violet::Vector3d Violet::Transformation::up() const {
	Vector3d up_basis = { 0.0, 1.0, 0.0 };
	up_basis.applyQuaternionRotation(orientation);
	up_basis.normalize();
	return up_basis;
}

void Violet::Transformation::moveForward(double dist) {
	position += forward() * dist;
}

void Violet::Transformation::moveRight(double dist) {
	position += right() * dist;
}

void Violet::Transformation::moveUp(double dist) {
	position += up() * dist;
}

Violet::Matrix Violet::Transformation::getModelMatrix() const {
	Matrix scalarMatrix = Matrix::buildScalarMatrix(scale);
	Matrix translationMatrix = Matrix::buildTranslationMatrix(position);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix(orientation);
	return translationMatrix * scalarMatrix * quaternionRotationMatrix;
}

Violet::Matrix Violet::Transformation::getViewMatrix() const {
	Matrix translationMatrix = Matrix::buildTranslationMatrix(position * -1.0);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix({ orientation.w, -orientation.x, -orientation.y, -orientation.z });
	return quaternionRotationMatrix * translationMatrix;
}

