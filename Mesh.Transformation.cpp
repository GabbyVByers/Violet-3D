
#include "Mesh.h"

void Mesh::scale(double scale) {
	transformation.reScale(scale);
}

void Mesh::setScale(double scale) {
	transformation.setScale(scale);
}

double Mesh::getScale() const {
	return transformation.getScale();
}

void Mesh::moveForward(double dist) {
	transformation.moveForward(dist);
}

void Mesh::moveRight(double dist) {
	transformation.moveRight(dist);
}

void Mesh::moveUp(double dist) {
	transformation.moveUp(dist);
}

void Mesh::move(double3 position) {
	transformation.move(position);
}

void Mesh::setPosition(double3 position) {
	transformation.setPosition(position);
}

double3 Mesh::getPosition() const {
	return transformation.getPosition();
}

void Mesh::resetOrientation() {
	transformation.resetOrientation();
}

void Mesh::rotate(double3 rot_axis, double theta) {
	transformation.rotate(rot_axis, theta);
}

void Mesh::pitch(double theta) {
	transformation.pitch(theta);
}

void Mesh::roll(double theta) {
	transformation.roll(theta);
}

void Mesh::yaw(double theta) {
	transformation.yaw(theta);
}

double3 Mesh::getForwardDirection() const {
	return transformation.getForwardDirection();
}

double3 Mesh::getRightDirection() const {
	return transformation.getRightDirection();
}

double3 Mesh::getUpDirection() const {
	return transformation.getUpDirection();
}

const Matrix Mesh::getModelMatrix() const {
	return transformation.getModelMatrix();
}

