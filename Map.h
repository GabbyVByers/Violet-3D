
#pragma once

#include "Window.h"
#include <string>

enum Celestial {
	isNull,
	isMoon,
	isPlanet,
	isSun
};

class Planet {
public:
	Planet(std::string name, size_t type, double mass, double radius, double altitude) {
		this->name = name;
		this->type = type;
		this->mass = mass;
		this->radius = radius;
		this->altitude = altitude;

		Vi::Shape::sphere(mesh, 1.0, 10);
		mesh.setRandomColors();
	}

	// Metadata
	std::string name = "Unnamed Body";
	size_t type = isNull;
	Vi::ID parentID = 0;

	// Rendering
	Vi::Mesh mesh;
	Vi::Vector3f renderPosition;
	Vi::Vector3d localPosition;
	Vi::Vector3d globalPosition;

	// Physical Characteristics
	double mass = 0.0;
	double radius = 0.0;

	// Orbital Characteristics
	double altitude = 0.0;
};

class Keplar {
public:
	static void constructSolarSystem() {
		planets.clear();

		theSunID = planets.push_back(Planet(
			"Sun",
			isSun,
			1.988475E30,
			6.957E8,
			0.0
		));
		Vi::ID Mercury = planets.push_back(Planet(
			"Mercury",
			isPlanet,
			3.3011E23,
			2.4397E6,
			5.791E10
		));
		Vi::ID Venus = planets.push_back(Planet(
			"Venus",
			isPlanet,
			4.8675E24,
			6.0518E6,
			1.0821E11
		));
		Vi::ID Earth = planets.push_back(Planet(
			"Earth",
			isPlanet,
			5.972168E24,
			6.371E6,
			1.49598023E11
		));
		Vi::ID Moon = planets.push_back(Planet(
			"Luna",
			isMoon,
			7.346E22,
			1.7374E6,
			3.84399E8
		));
		Vi::ID Mars = planets.push_back(Planet(
			"Mars",
			isPlanet,
			6.4171E23,
			3.3895E6,
			2.27939366E11
		));
		Vi::ID Phobos = planets.push_back(Planet(
			"Phobos",
			isMoon,
			1.06E16,
			1.108E4,
			9.376E6
		));
		Vi::ID Deimos = planets.push_back(Planet(
			"Deimos",
			isMoon,
			1.51E15,
			6.27E3,
			2.34632E7
		));

		planets[Mercury].parentID = theSunID;
		planets[Venus].parentID   = theSunID;
		planets[Earth].parentID   = theSunID;
		planets[Mars].parentID    = theSunID;
		planets[Moon].parentID    = Earth;
		planets[Phobos].parentID  = Mars;
		planets[Deimos].parentID  = Mars;
	}

	static void updatePlanetsAlongTrajectory(double deltaTime) {

	}

	static void updatePlanetLocalPositions() {

	}

	static Planet& getTheSun() {
		return planets[theSunID];
	}

	static Vi::Container<Planet>& getPlanets() {
		return planets;
	}

private:
	inline static Vi::ID theSunID = Vi::InvalidID;
	inline static Vi::Container<Planet> planets;
};

class Map {
public:

	static void controlMapViewCamera() {
		const double sensitivity = 0.1;

		if (Vi::Mouse::pressing(GLFW_MOUSE_BUTTON_LEFT)) {
			Vi::Vector2d mouseVelocity = Vi::Mouse::velocity();
			camera.transformation.pitch(sensitivity * mouseVelocity.y * -0.01);
			camera.transformation.rotate(Vi::Vector3d(0.0, 1.0, 0.0), sensitivity * mouseVelocity.x * -0.01);
		}

		Vi::Vector3d forward = camera.transformation.forward();
		Vi::Vector3d& position = camera.transformation.position;
		position = forward * -1.0;
	}

	static void render() {
		updatePlanetRenderPositions();
		updatePlanetTransformations();
		drawPlanetMeshes();
	}

private:
	static void updatePlanetRenderPositions() {
		Planet& theSun = Keplar::getTheSun();
		theSun.globalPosition = Vi::Vector3d::ZERO();

		for (Planet& planet : Keplar::getPlanets()) {
			planet.globalPosition = planet.localPosition;
		}
	}

	static void updatePlanetTransformations() {

	}

	static void drawPlanetMeshes() {
		for (Planet& planet : Keplar::getPlanets()) {
			Vi::Window::draw(planet.mesh, camera);
		}
	}

	inline static Vi::Camera camera;
	inline static double globalScale = 0.00001;
	inline static Vi::ID focusPlanetID = Vi::InvalidID;
};

