
#include "Transformation.h"

void Transformation::reScale(double s) {
	scale *= s;
}

void Transformation::setScale(double s) {
	scale = s;
}

double Transformation::getScale() const {
	return scale;
}

void Transformation::moveForward(double dist) {
	double3 forwardDirection = getForwardDirection();
	move(forwardDirection * dist);
}

void Transformation::moveRight(double dist) {
	double3 rightDirection = getRightDirection();
	move(rightDirection * dist);
}

void Transformation::moveUp(double dist) {
	double3 upDirection = getUpDirection();
	move(upDirection * dist);
}

void Transformation::move(double3 pos) {
	position = position + pos;
}

void Transformation::setPosition(double3 pos) {
	position = pos;
}

double3 Transformation::getPosition() const {
	return position;
}

void Transformation::resetOrientation() {
	orientation = { 1.0, 0.0, 0.0, 0.0 };
}

void Transformation::rotate(double3 axis, double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Transformation::pitch(double theta) {
	double3 axis = getRightDirection();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Transformation::roll(double theta) {
	double3 axis = getForwardDirection();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Transformation::yaw(double theta) {
	double3 axis = getUpDirection();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, -theta);
	orientation = quat * orientation;
	orientation.normalize();
}

double3 Transformation::getForwardDirection() const {
	double3 forward = { 0.0, 0.0, -1.0 };
	forward.applyQuaternionRotation(orientation);
	forward.normalize();
	return forward;
}

double3 Transformation::getRightDirection() const {
	double3 right = { 1.0, 0.0, 0.0 };
	right.applyQuaternionRotation(orientation);
	right.normalize();
	return right;
}

double3 Transformation::getUpDirection() const {
	double3 up = { 0.0, 1.0, 0.0 };
	up.applyQuaternionRotation(orientation);
	up.normalize();
	return up;
}

const Matrix Transformation::getModelMatrix() const {
	Matrix scalarMatrix = Matrix::buildScalarMatrix(scale);
	Matrix translationMatrix = Matrix::buildTranslationMatrix(position);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix(orientation);
	return translationMatrix * scalarMatrix * quaternionRotationMatrix;
}

const Matrix Transformation::getViewMatrix() const {
	Matrix scalarMatrix = Matrix::buildScalarMatrix(scale);
	Matrix translationMatrix = Matrix::buildTranslationMatrix(position * -1.0);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix({ orientation.w, -orientation.x, -orientation.y, -orientation.z });
	return quaternionRotationMatrix * scalarMatrix * translationMatrix;
}

