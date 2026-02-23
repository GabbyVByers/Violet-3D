
#include "Map.h"

void Map::render() {
	// CAMERA CONTROL
	const double sensitivity = 0.1;
	if (Vi::Mouse::pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Vi::Vector2d mouseVelocity = Vi::Mouse::velocity();
		camera.transformation.pitch(sensitivity * mouseVelocity.y * -0.01);
		camera.transformation.rotate(Vi::Vector3d(0.0, 1.0, 0.0), sensitivity * mouseVelocity.x * -0.01);
	}

	Vi::Vector3d forward = camera.transformation.forward();
	Vi::Vector3d& position = camera.transformation.position;
	position = forward * -1.0;

	// GLOBAL/LOCAL/RENDER POSITIONS
	Planet& theSun = Keplar::getPlanet(theSunID);
	theSun.setGlobalPosition(Vi::Vector3d::ZERO());

	for (Planet& planet : Keplar::getPlanets()) {
		if (planet.isPlanet())
			planet.setGlobalPosition(planet.getLocalPosition());
	}

	for (Planet& planet : Keplar::getPlanets()) {
		if (planet.isMoon()) {
			planet.setGlobalPosition(
				planet.getGlobalPosition() + Keplar::getPlanet(planet.getParentID()).getGlobalPosition()
			);
		}
	}

	// RENDER PLANET MESHES
	for (Planet& planet : Keplar::getPlanets()) {
		Vi::Window::draw(planet.getMesh(), camera);
	}
}

void Map::setSunID(Vi::ID planetID) {
	theSunID = planetID;
}

void Map::setFocusPlanetID(Vi::ID planetID) {
	focusPlanetID = planetID;
}

