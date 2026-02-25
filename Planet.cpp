
#include "Planet.h"

Planet::Planet(std::string name, size_t type, double mass, double radius, double altitude) {
	this->name = name;
	this->type = type;
	this->mass = mass;
	this->radius = radius;
	this->altitude = altitude;
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

