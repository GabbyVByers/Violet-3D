
#include "Transformation.h"

void Transformation::reScale(double scale) {
	this->scale *= scale;
}

void Transformation::setScale(double scale) {
	this->scale = scale;
}

double Transformation::getScale() const {
	return this->scale;
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

void Transformation::move(double3 position) {
	this->position = this->position + position;
}

void Transformation::setPosition(double3 position) {
	this->position = position;
}

double3 Transformation::getPosition() const {
	return this->position;
}

void Transformation::resetOrientation() {
	this->orientation = { 1.0, 0.0, 0.0, 0.0 };
}

void Transformation::rotate(double3 axis, double theta) {
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	this->orientation = quat * this->orientation;
	this->orientation.normalize();
}

void Transformation::pitch(double theta) {
	double3 axis = this->getRightDirection();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	this->orientation = quat * this->orientation;
	this->orientation.normalize();
}

void Transformation::roll(double theta) {
	double3 axis = this->getForwardDirection();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	this->orientation = quat * this->orientation;
	this->orientation.normalize();
}

void Transformation::yaw(double theta) {
	double3 axis = this->getUpDirection();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, -theta);
	this->orientation = quat * this->orientation;
	this->orientation.normalize();
}

double3 Transformation::getForwardDirection() const {
	double3 forward = { 0.0, 0.0, -1.0 };
	forward.applyQuaternionRotation(this->orientation);
	forward.normalize();
	return forward;
}

double3 Transformation::getRightDirection() const {
	double3 right = { 1.0, 0.0, 0.0 };
	right.applyQuaternionRotation(this->orientation);
	right.normalize();
	return right;
}

double3 Transformation::getUpDirection() const {
	double3 up = { 0.0, 1.0, 0.0 };
	up.applyQuaternionRotation(this->orientation);
	up.normalize();
	return up;
}

const Matrix Transformation::getModelMatrix() const {
	Matrix scalarMatrix = Matrix::buildScalarMatrix(this->scale);
	Matrix translationMatrix = Matrix::buildTranslationMatrix(this->position);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix(this->orientation);
	return translationMatrix * scalarMatrix * quaternionRotationMatrix;
}

const Matrix Transformation::getViewMatrix() const {
	Matrix scalarMatrix = Matrix::buildScalarMatrix(this->scale);
	Matrix translationMatrix = Matrix::buildTranslationMatrix(this->position);
	Matrix quaternionRotationMatrix = Matrix::buildQuaternionRotationMatrix(this->orientation);
	return quaternionRotationMatrix * scalarMatrix * translationMatrix;
}

