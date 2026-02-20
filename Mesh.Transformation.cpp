
#include "Mesh.h"

void Mesh::scale(double scale) {
	this->transformation.reScale(scale);
}

void Mesh::setScale(double scale) {
	this->transformation.setScale(scale);
}

double Mesh::getScale() const {
	return this->transformation.getScale();
}

void Mesh::moveForward(double dist) {
	this->transformation.moveForward(dist);
}

void Mesh::moveRight(double dist) {
	this->transformation.moveRight(dist);
}

void Mesh::moveUp(double dist) {
	this->transformation.moveUp(dist);
}

void Mesh::move(double3 position) {
	this->transformation.move(position);
}

void Mesh::setPosition(double3 position) {
	this->transformation.setPosition(position);
}

double3 Mesh::getPosition() const {
	return this->transformation.getPosition();
}

void Mesh::resetOrientation() {
	this->transformation.resetOrientation();
}

void Mesh::rotate(double3 rot_axis, double theta) {
	this->transformation.rotate(rot_axis, theta);
}

void Mesh::pitch(double theta) {
	this->transformation.pitch(theta);
}

void Mesh::roll(double theta) {
	this->transformation.roll(theta);
}

void Mesh::yaw(double theta) {
	this->transformation.yaw(theta);
}

double3 Mesh::getForwardDirection() const {
	this->transformation.getForwardDirection();
}

double3 Mesh::getRightDirection() const {
	this->transformation.getRightDirection();
}

double3 Mesh::getUpDirection() const {
	this->transformation.getUpDirection();
}

const Matrix Mesh::getModelMatrix() const {
	return this->transformation.getMatrix();
}

