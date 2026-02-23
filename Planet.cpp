
#include "Planet.h"

Planet::Planet(std::string name, size_t type, double mass, double radius, double altitude) {
	this->name = name;
	this->type = type;
	this->mass = mass;
	this->radius = radius;
	this->altitude = altitude;

	Vi::Shape::sphere(mesh, 1.0, 10);
	mesh.setRandomColors();
}

Vi::ID Planet::getParentID() const {
	return parentID;
}

void Planet::setParentID(Vi::ID planetID) {
	parentID = planetID;
}

Vi::Vector3f Planet::getRenderPosition() const {
	return renderPosition;
}

Vi::Vector3d Planet::getLocalPosition() const {
	return localPosition;
}

Vi::Vector3d Planet::getGlobalPosition() const {
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

Vi::Mesh& Planet::getMesh() {
	return mesh;
}

void Planet::clearMesh() {
	mesh.vertices.clear();
}

void Planet::addMeshVertex(const Vi::Vertex& vertex) {
	mesh.vertices.push_back(vertex);
}

