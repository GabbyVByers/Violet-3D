
#pragma once

#include "Window.h"
#include "Planet.h"
#include "Keplar.h"
#include <string>

class Map {
public:
	static void render();
	static void setSunID(Vi::ID planetID);
	static void setFocusPlanetID(Vi::ID planetID);

private:
	Map() = delete;
	~Map() = delete;

	inline static Vi::Camera camera;
	inline static double globalScale = 0.00001;
	
	inline static Vi::ID theSunID = Vi::InvalidID;
	inline static Vi::ID focusPlanetID = Vi::InvalidID;
};

