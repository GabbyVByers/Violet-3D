
#pragma once

#include "Violet.h"

enum Celestial {
	isNullType,
	isMoonType,
	isPlanetType,
	isSunType
};

class Planet {
public:
	Planet(std::string name, size_t type, double mass, double radius, double altitude);
	bool isMoon() const;
	bool isPlanet() const;
	bool isSun() const;

	std::string name = "Unnamed Body";
	size_t type = isNullType;
	Vi::ID ID = Vi::InvalidID;
	Vi::ID parentID = Vi::InvalidID;
	std::vector<Vi::ID> childIDs;

	Vi::Mesh mesh;
	Vi::Vector3f renderPosition;
	Vi::Vector3d localPosition;
	Vi::Vector3d globalPosition;

	double mass = 0.0;
	double radius = 0.0;
	double altitude = 0.0;
};

