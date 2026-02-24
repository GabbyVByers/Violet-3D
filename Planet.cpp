
#include "Planet.h"

Planet::Planet(std::string name, size_t type, double mass, double radius, double altitude) {
	this->name = name;
	this->type = type;
	this->mass = mass;
	this->radius = radius;
	this->altitude = altitude;

	mesh = Vi::Mesh();
	Vi::Shape::sphere(mesh, 1.0, 15);
	mesh.setRandomColors();
}

Vi::Mesh& Planet::getMesh() {
	return mesh;
}

void Planet::setSelfID(Vi::ID id) {
	ID = id;
}

Vi::ID& Planet::getID() {
	return ID;
}

Vi::ID& Planet::getParentID() {
	return parentID;
}

void Planet::setParentID(Vi::ID planetID) {
	parentID = planetID;
}

Vi::Vector3f& Planet::getRenderPosition() {
	return renderPosition;
}

Vi::Vector3d& Planet::getLocalPosition() {
	return localPosition;
}

Vi::Vector3d& Planet::getGlobalPosition() {
	return globalPosition;
}

void Planet::setRenderPosition(Vi::Vector3f renderPosition) {
	this->renderPosition = renderPosition;
}

void Planet::setLocalPosition(Vi::Vector3d localPosition) {
	this->localPosition = localPosition;
}

void Planet::setGlobalPosition(Vi::Vector3d globalPosition) {
	this->globalPosition = globalPosition;
}

bool Planet::isMoon() const {
	return type == isMoonType;
}

bool Planet::isPlanet() const {
	return type == isPlanetType;
}

bool Planet::isSun() const {
	return type == isSunType;
}

