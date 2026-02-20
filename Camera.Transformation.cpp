
#include "Camera.h"

void Camera::moveForward(double dist) {
	transformation.moveForward(dist);
}

void Camera::moveRight(double dist) {
	transformation.moveRight(dist);
}

void Camera::moveUp(double dist) {
	transformation.moveUp(dist);
}

void Camera::move(double3 position) {
	transformation.move(position);
}

void Camera::setPosition(double3 position) {
	transformation.setPosition(position);
}

double3 Camera::getPosition() const {
	return transformation.getPosition();
}

void Camera::resetOrientation() {
	transformation.resetOrientation();
}

void Camera::rotate(double3 rot_axis, double theta) {
	transformation.rotate(rot_axis, theta);
}

void Camera::pitch(double theta) {
	transformation.pitch(theta);
}

void Camera::roll(double theta) {
	transformation.roll(theta);
}

void Camera::yaw(double theta) {
	transformation.yaw(theta);
}

double3 Camera::getForwardDirection() const {
	return transformation.getForwardDirection();
}

double3 Camera::getRightDirection() const {
	return transformation.getRightDirection();
}

double3 Camera::getUpDirection() const {
	return transformation.getUpDirection();
}

const Matrix Camera::getViewMatrix() const {
	return transformation.getViewMatrix();
}

