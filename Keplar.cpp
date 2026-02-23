
#include "Keplar.h"

void Keplar::constructSolarSystem() {
	planets.clear();
	Vi::ID Sun = planets.push_back(Planet(
		"Sun",
		isSunType,
		1.988475E30,
		6.957E8,
		0.0
	));
	Vi::ID Mercury = planets.push_back(Planet(
		"Mercury",
		isPlanetType,
		3.3011E23,
		2.4397E6,
		5.791E10
	));
	Vi::ID Venus = planets.push_back(Planet(
		"Venus",
		isPlanetType,
		4.8675E24,
		6.0518E6,
		1.0821E11
	));
	Vi::ID Earth = planets.push_back(Planet(
		"Terra",
		isPlanetType,
		5.972168E24,
		6.371E6,
		1.49598023E11
	));
	Vi::ID Moon = planets.push_back(Planet(
		"Luna",
		isMoonType,
		7.346E22,
		1.7374E6,
		3.84399E8
	));
	Vi::ID Mars = planets.push_back(Planet(
		"Mars",
		isPlanetType,
		6.4171E23,
		3.3895E6,
		2.27939366E11
	));
	Vi::ID Phobos = planets.push_back(Planet(
		"Phobos",
		isMoonType,
		1.06E16,
		1.108E4,
		9.376E6
	));
	Vi::ID Deimos = planets.push_back(Planet(
		"Deimos",
		isMoonType,
		1.51E15,
		6.27E3,
		2.34632E7
	));

	planets[Mercury].setParentID(Sun);
	planets[Venus].setParentID(Sun);
	planets[Earth].setParentID(Sun);
	planets[Mars].setParentID(Sun);
	planets[Moon].setParentID(Earth);
	planets[Phobos].setParentID(Mars);
	planets[Deimos].setParentID(Mars);
	Map::setSunID(Sun);
}

Vi::Container<Planet>& Keplar::getPlanets() {
	return planets;
}

Planet& Keplar::getPlanet(Vi::ID planetID) {
	return planets[planetID];
}

