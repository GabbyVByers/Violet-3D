
#include "Mesh.h"

void Mesh::resetPosition() {
	modelTranslation.reset();
}

void Mesh::resetSize() {
	modelScale.reset();
}

void Mesh::resetOrientation() {
	modelRotation.reset();
}

void Mesh::setPosition(double3 position) {
	resetPosition(); modelTranslation.translate(position);
}

void Mesh::setSize(double size) {
	resetSize();
	modelScale.scale(size);
}

void Mesh::translate(double3 offset) {
	modelTranslation.translate(offset);
}

void Mesh::rotate(double3 axis, double theta) {
	modelRotation.rotate(axis, theta);
}

void Mesh::scale(double scale) {
	modelScale.scale(scale);
}

