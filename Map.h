
#pragma once

#include "Violet.h"
#include "Planet.h"
#include "Keplar.h"
#include <string>

class Map {
public:
	// Map.Render.cpp
	static void render();
	static void controlCameraMapView();
	static void updatePlanetRenderPositions();
	static void renderPlanetMeshes();

	// Map.cpp
	static void setSunID(Vi::ID planetID);
	static void setFocusBodyID(Vi::ID planetID);
	static double& getGlobalScale();

private:
	Map() = delete;
	~Map() = delete;
	inline static Vi::Camera camera;
	inline static double globalScale = 1.0 / 6.371E6;
	inline static Vi::ID theSunID = Vi::InvalidID;
	inline static Vi::ID focusBodyID = Vi::InvalidID;
};

