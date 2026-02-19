
#include "Transformation.h"

// Scale

void Transformation::reScale(double scale) {
	this->scale *= scale;
}

void Transformation::setScale(double scale) {
	this->scale = scale;
}

double Transformation::getScale() const {
	return this->scale;
}

// Position

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

// Orientation

void Transformation::resetOrientation() {

}

void Transformation::rotate(double3 rot_axis, double theta) {

}

void Transformation::pitch(double theta) {

}

void Transformation::roll(double theta) {

}

void Transformation::yaw(double theta) {

}

double3 Transformation::getForwardDirection() const {
	double3 forwardBasis = { 0.0, 0.0,-1.0 };

}

double3 Transformation::getRightDirection() const {

}

double3 Transformation::getUpDirection() const {

}

