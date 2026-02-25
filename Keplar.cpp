
#include "Keplar.h"

void Keplar::constructSolarSystem() {
	planets.clear();
	Vi::ID SunID = planets.push_back(Planet(
		"Sun",
		isSunType,
		1.988475E30,
		6.957E8,
		0.0
	));
	Vi::ID MercuryID = planets.push_back(Planet(
		"Mercury",
		isPlanetType,
		3.3011E23,
		2.4397E6,
		5.791E10
	));
	Vi::ID VenusID = planets.push_back(Planet(
		"Venus",
		isPlanetType,
		4.8675E24,
		6.0518E6,
		1.0821E11
	));
	Vi::ID EarthID = planets.push_back(Planet(
		"Terra",
		isPlanetType,
		5.972168E24,
		6.371E6,
		1.49598023E11
	));
	Vi::ID MoonID = planets.push_back(Planet(
		"Luna",
		isMoonType,
		7.346E22,
		1.7374E6,
		3.84399E8
	));
	Vi::ID MarsID = planets.push_back(Planet(
		"Mars",
		isPlanetType,
		6.4171E23,
		3.3895E6,
		2.27939366E11
	));
	Vi::ID PhobosID = planets.push_back(Planet(
		"Phobos",
		isMoonType,
		1.06E16,
		1.108E4,
		9.376E6
	));
	Vi::ID DeimosID = planets.push_back(Planet(
		"Deimos",
		isMoonType,
		1.51E15,
		6.27E3,
		2.34632E7
	));

	Planet& SUN     = getPlanet(SunID);
	Planet& MERCURY = getPlanet(MercuryID);
	Planet& VENUS   = getPlanet(VenusID);
	Planet& EARTH   = getPlanet(EarthID);
	Planet& MOON    = getPlanet(MoonID);
	Planet& MARS    = getPlanet(MarsID);
	Planet& PHOBOS  = getPlanet(PhobosID);
	Planet& DEIMOS  = getPlanet(DeimosID);

	SUN    .ID = SunID;
	MERCURY.ID = MercuryID;
	VENUS  .ID = VenusID;
	EARTH  .ID = EarthID;
	MOON   .ID = MoonID;
	MARS   .ID = MarsID;
	PHOBOS .ID = PhobosID;
	DEIMOS .ID = DeimosID;

	SUN    .childIDs.push_back(MercuryID);
	SUN    .childIDs.push_back(VenusID);
	SUN    .childIDs.push_back(EarthID);
	SUN    .childIDs.push_back(MarsID);
	EARTH  .childIDs.push_back(MoonID);
	MARS   .childIDs.push_back(PhobosID);
	MARS   .childIDs.push_back(DeimosID);

	MERCURY.parentID = SunID;
	VENUS  .parentID = SunID;
	EARTH  .parentID = SunID;
	MARS   .parentID = SunID;
	MOON   .parentID = EarthID;
	PHOBOS .parentID = MarsID;
	DEIMOS .parentID = MarsID;

	Map::setSunID(SunID);
	Map::setFocusBodyID(EarthID);
	for (Planet& body : getPlanets()) {
		body.mesh.init();
		Vi::Shape::sphere(body.mesh, 1.0, 10);
		body.mesh.setRandomColors();
	}
}

Vi::Container<Planet>& Keplar::getPlanets() {
	return planets;
}

Planet& Keplar::getPlanet(Vi::ID planetID) {
	assert(planetID != Vi::InvalidID);
	return planets[planetID];
}

