
#pragma once

#include "Core.h"

class Violet::Color {
public:
	// Color.cpp
	Color();
	Color(float r, float g, float b, float a = 1.0f);
	static Color Random();
	static Color White();
	static Color Black();
	static Color Red();
	static Color Green();
	static Color Blue();
	static Color Cyan();
	static Color Purple();
	static Color Yellow();

	// Members
	float r = 1.0f;
	float g = 1.0f;
	float b = 1.0f;
	float a = 1.0f;
};

