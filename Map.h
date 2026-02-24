
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

private:
	Map() = delete;
	~Map() = delete;
	inline static Vi::Camera camera;
	inline static double globalScale = 0.00001;
	inline static Vi::ID theSunID = Vi::InvalidID;
	inline static Vi::ID focusBodyID = Vi::InvalidID;
};

