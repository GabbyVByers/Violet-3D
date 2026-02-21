
#pragma once

#include "Violet.h"

class Violet::Color {
public:
	Color();
	Color(float r, float g, float b, float a = 1.0f);
	static Color Random();
	static Color WHITE();
	static Color BLACK();
	static Color RED();
	static Color GREEN();
	static Color BLUE();
	static Color CYAN();
	static Color PURPLE();
	static Color YELLOW();

	float r = 1.0f;
	float g = 1.0f;
	float b = 1.0f;
	float a = 1.0f;
};

