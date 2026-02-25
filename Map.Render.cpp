
#include "Map.h"

void Map::render() {
	controlCameraMapView();
	updatePlanetRenderPositions();
	renderPlanetMeshes();
}

void Map::controlCameraMapView() {
	const double sensitivity = 0.1;
	globalScale *= (1.0 + (Vi::Mouse::scroll() / 20.0));
	if (Vi::Mouse::pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Vi::Vector2d mouseVelocity = Vi::Mouse::velocity();
		camera.pitch(sensitivity * mouseVelocity.y * -0.01);
		camera.rotateAroundAxis(Vi::Vector3d(0.0, 1.0, 0.0), sensitivity * mouseVelocity.x * -0.01);
	}
	camera.setPosition(camera.forward() * -1.0);
}

void Map::updatePlanetRenderPositions() {
	//Planet& theSun = Keplar::getPlanet(theSunID);
	//Planet& focusBody = Keplar::getPlanet(focusBodyID);
	//
	//if (focusBody.isSun()) {
	//	theSun.setGlobalPosition(Vi::Vector3d::ZERO());
	//}
	//if (focusBody.isPlanet()) {
	//	theSun.setGlobalPosition(focusBody.getLocalPosition() * -1.0);
	//}
	//if (focusBody.isMoon()) {
	//	Planet& parentBody = Keplar::getPlanet(focusBody.getParentID());
	//	Vi::Vector3d moonPosition = parentBody.getLocalPosition() + focusBody.getLocalPosition();
	//	theSun.setGlobalPosition(moonPosition * -1.0);
	//}
	//
	//for (Planet& body : Keplar::getPlanets()) {
	//	if (body.isPlanet()) {
	//		body.setGlobalPosition(
	//			theSun.getGlobalPosition() +
	//			body.getLocalPosition()
	//		);
	//	}
	//}
	//for (Planet& body : Keplar::getPlanets()) {
	//	if (body.isMoon()) {
	//		Planet& parentBody = Keplar::getPlanet(body.getParentID());
	//		body.setGlobalPosition(
	//			parentBody.getGlobalPosition() +
	//			body.getLocalPosition()
	//		);
	//	}
	//}
	//
	//focusBody.setGlobalPosition(Vi::Vector3d::ZERO());
	//if (focusBody.isMoon()) {
	//	Planet& parentBody = Keplar::getPlanet(focusBody.getParentID());
	//	parentBody.setGlobalPosition(focusBody.getLocalPosition() * -1.0);
	//
	//	for (Vi::ID childID : parentBody.getChildren()) {
	//		if (childID == focusBody.getSelfID())
	//			continue;
	//		Planet& body = Keplar::getPlanet(childID);
	//		body.setGlobalPosition(
	//			parentBody.getGlobalPosition() +
	//			body.getLocalPosition()
	//		);
	//	}
	//}
	//if (focusBody.isPlanet()) {
	//	for (Vi::ID childID : focusBody.getChildren()) {
	//		Planet& body = Keplar::getPlanet(childID);
	//		body.setGlobalPosition(body.getLocalPosition());
	//	}
	//}

	for (Planet& body : Keplar::getPlanets()) {
		double renderRadius = globalScale * body.radius;
		body.mesh.setScale(renderRadius);
		
	}
	std::cout << "\n";
}

void Map::renderPlanetMeshes() {
	for (Planet& body : Keplar::getPlanets()) {
		if (body.isSun())
			continue;
		Vi::Vector3f pos = body.renderPosition;
		printf("\n%s: radius: %lf pos: %f %f %f", body.name.c_str(), body.mesh.getScale(), pos.x, pos.y, pos.y);
		//std::cout << body.name << ": " << renderRadius << "pos: x:" << body.renderPosition.x  << "\n";


		Vi::Window::draw(body.mesh, camera);
	}
}

