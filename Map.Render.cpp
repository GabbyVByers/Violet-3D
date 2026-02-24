
#include "Map.h"

void Map::render() {
	controlCameraMapView();
	updatePlanetRenderPositions();
	renderPlanetMeshes();
}

void Map::controlCameraMapView() {
	const double sensitivity = 0.1;
	if (Vi::Mouse::pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Vi::Vector2d mouseVelocity = Vi::Mouse::velocity();
		camera.pitch(sensitivity * mouseVelocity.y * -0.01);
		camera.rotateAroundAxis(Vi::Vector3d(0.0, 1.0, 0.0), sensitivity * mouseVelocity.x * -0.01);
	}
	camera.setPosition(camera.forward() * -1.0);
}

void Map::updatePlanetRenderPositions() {
	Planet& theSun = Keplar::getPlanet(theSunID);
	Planet& focusPlanet = Keplar::getPlanet(focusPlanetID);
	focusPlanet.setGlobalPosition(Vi::Vector3d::ZERO());

	if (focusPlanet.isPlanet()) {
		theSun.setGlobalPosition(focusPlanet.getLocalPosition() * -1.0);
	}
	if (focusPlanet.isMoon()) {
		Planet& focusPlanetParent = Keplar::getPlanet(focusPlanet.getParentID());
		Vi::Vector3d focusPlanetPosition = focusPlanetParent.getLocalPosition() + focusPlanet.getLocalPosition();
		theSun.setGlobalPosition(focusPlanetPosition * -1.0);
	}

	for (Planet& planet : Keplar::getPlanets()) {
		if (planet.isPlanet())
			planet.setGlobalPosition(theSun.getGlobalPosition() + planet.getLocalPosition());
	}

	for (Planet& planet : Keplar::getPlanets()) {
		if (planet.isMoon()) {
			planet.setGlobalPosition(
				planet.getGlobalPosition() + Keplar::getPlanet(planet.getParentID()).getGlobalPosition()
			);
		}
	}
}

void Map::renderPlanetMeshes() {
	for (Planet& planet : Keplar::getPlanets()) {
		Vi::Window::draw(planet.getMesh(), camera);
	}
}

