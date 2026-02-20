
#include "Camera.h"

void Camera::moveForward(double dist) {
	this->transformation.moveForward(-dist);
}

void Camera::moveRight(double dist) {
	this->transformation.moveRight(-dist);
}

void Camera::moveUp(double dist) {
	this->transformation.moveUp(-dist);
}

void Camera::move(double3 position) {
	this->transformation.move(position * -1.0);
}

void Camera::setPosition(double3 position) {
	this->transformation.setPosition(position * -1.0);
}

double3 Camera::getPosition() const {
	return this->transformation.getPosition();
}

void Camera::resetOrientation() {
	this->transformation.resetOrientation();
}

void Camera::rotate(double3 rot_axis, double theta) {
	this->transformation.rotate(rot_axis, -theta);
}

void Camera::pitch(double theta) {
	this->transformation.pitch(-theta);
}

void Camera::roll(double theta) {
	this->transformation.roll(-theta);
}

void Camera::yaw(double theta) {
	this->transformation.yaw(-theta);
}

double3 Camera::getForwardDirection() const {
	this->transformation.getForwardDirection();
}

double3 Camera::getRightDirection() const {
	this->transformation.getRightDirection();
}

double3 Camera::getUpDirection() const {
	this->getUpDirection();
}

const Matrix Camera::getViewMatrix() const {
	return this->transformation.getMatrix();
}

