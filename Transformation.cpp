
#include "Transformation.h"

void Violet::Transformation::reScale(double s) {
	scale *= s;
}

void Violet::Transformation::setScale(double s) {
	scale = s;
}

double Violet::Transformation::getScale() const {
	return scale;
}

void Violet::Transformation::moveForward(double dist) {
	Vector3d forwardDirection = getForwardDirection();
	move(forwardDirection * dist);
}

void Violet::Transformation::moveRight(double dist) {
	Vector3d rightDirection = getRightDirection();
	move(rightDirection * dist);
}

void Violet::Transformation::moveUp(double dist) {
	Vector3d upDirection = getUpDirection();
	move(upDirection * dist);
}

void Violet::Transformation::move(Vector3d pos) {
	position = position + pos;
}

void Violet::Transformation::setPosX(double new_x) {
	position.x = new_x;
}

void Violet::Transformation::setPosY(double new_y) {
	position.y = new_y;
}

void Violet::Transformation::setPosZ(double new_z) {
	position.z = new_z;
}

void Violet::Transformation::setPosition(Vector3d pos) {
	position = pos;
}

Violet::Vector3d Violet::Transformation::getPosition() const {
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
	Vector3d axis = getRightDirection();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Violet::Transformation::roll(double theta) {
	Vector3d axis = getForwardDirection();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, theta);
	orientation = quat * orientation;
	orientation.normalize();
}

void Violet::Transformation::yaw(double theta) {
	Vector3d axis = getUpDirection();
	Quaternion quat = Quaternion::buildRotationQuaternion(axis, -theta);
	orientation = quat * orientation;
	orientation.normalize();
}

Violet::Vector3d Violet::Transformation::getForwardDirection() const {
	Vector3d forward = { 0.0, 0.0, -1.0 };
	forward.applyQuaternionRotation(orientation);
	forward.normalize();
	return forward;
}

Violet::Vector3d Violet::Transformation::getRightDirection() const {
	Vector3d right = { 1.0, 0.0, 0.0 };
	right.applyQuaternionRotation(orientation);
	right.normalize();
	return right;
}

Violet::Vector3d Violet::Transformation::getUpDirection() const {
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

