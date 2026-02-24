
#pragma once

#include "Violet.h"

class Violet::Color {
public:
	// Color.Interface.cpp
	Color();
	Color(float r, float g, float b, float a = 1.0f);
	float& red();
	float& green();
	float& blue();
	float& alpha();

	// Color.Static.cpp
	static Color Random();
	static Color WHITE();
	static Color BLACK();
	static Color RED();
	static Color GREEN();
	static Color BLUE();
	static Color CYAN();
	static Color PURPLE();
	static Color YELLOW();

private:
	float m_r = 1.0f;
	float m_g = 1.0f;
	float m_b = 1.0f;
	float m_a = 1.0f;
};

