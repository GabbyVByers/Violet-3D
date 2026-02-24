
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
	Vi::Mesh& getMesh();

	Vi::ID getParentID() const;
	void setParentID(Vi::ID planetID);

	Vi::Vector3f getRenderPosition() const;
	Vi::Vector3d getLocalPosition() const;
	Vi::Vector3d getGlobalPosition() const;
	void setRenderPosition(Vi::Vector3f renderPosition);
	void setLocalPosition(Vi::Vector3d localPosition);
	void setGlobalPosition(Vi::Vector3d globalPosition);

	bool isMoon() const;
	bool isPlanet() const;
	bool isSun() const;


private:
	std::string name = "Unnamed Body";
	size_t type = isNullType;
	Vi::ID parentID = Vi::InvalidID;

	Vi::Mesh mesh;
	Vi::Vector3f renderPosition;
	Vi::Vector3d localPosition;
	Vi::Vector3d globalPosition;

	double mass = 0.0;
	double radius = 0.0;
	double altitude = 0.0;
};

