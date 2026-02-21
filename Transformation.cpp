
#include "Transformation.h"

double& Violet::Transformation::borrowScale() {
	return scale;
}

Violet::Vector3d& Violet::Transformation::borrowPosition() {
	return position;
}

void Violet::Transformation::resetOrientation() {
	orientation = { 1.0, 0.0, 0.0, 0.0 };
}

void Violet::Transformation::rotate(Vector3d axis, double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Violet::Transformation::pitch(double theta) {
	Vector3d axis = rightDir();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Violet::Transformation::roll(double theta) {
	Vector3d axis = forwardDir();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Violet::Transformation::yaw(double theta) {
	Vector3d axis = upDir();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, -theta);
	orientation = quat * orientation;
	orientation.normalize();
}

Violet::Vector3d Violet::Transformation::forwardDir() const {
	Vector3d forward = { 0.0, 0.0, -1.0 };
	forward.applyQuaternionRotation(orientation);
	forward.normalize();
	return forward;
}

Violet::Vector3d Violet::Transformation::rightDir() const {
	Vector3d right = { 1.0, 0.0, 0.0 };
	right.applyQuaternionRotation(orientation);
	right.normalize();
	return right;
}

Violet::Vector3d Violet::Transformation::upDir() const {
	Vector3d up = { 0.0, 1.0, 0.0 };
	up.applyQuaternionRotation(orientation);
	up.normalize();
	return up;
}

const Violet::Matrix Violet::Transformation::getModelMatrix() const {
	Matrix scalarMatrix = Matrix::buildScalarMatrix(scale);
	Matrix translationMatrix = Matrix::buildTranslationMatrix(position);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix(orientation);
	return translationMatrix * scalarMatrix * quaternionRotationMatrix;
}

const Violet::Matrix Violet::Transformation::getViewMatrix() const {
	Matrix scalarMatrix = Matrix::buildScalarMatrix(scale);
	Matrix translationMatrix = Matrix::buildTranslationMatrix(position * -1.0);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix({ orientation.w, -orientation.x, -orientation.y, -orientation.z });
	return quaternionRotationMatrix * scalarMatrix * translationMatrix;
}

