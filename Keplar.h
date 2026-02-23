
#pragma once

#include "Window.h"
#include "Planet.h"
#include "Map.h"

class Keplar {
public:
	static void constructSolarSystem();
	static Vi::Container<Planet>& getPlanets();
	static Planet& getPlanet(Vi::ID planetID);

private:
	Keplar() = delete;
	~Keplar() = delete;

	inline static Vi::Container<Planet> planets;
};

