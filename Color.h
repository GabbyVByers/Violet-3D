
#pragma once

class Color {
public:
	float r;
	float g;
	float b;
	float a;

	Color(float r = 1.0f,
		  float g = 1.0f,
		  float b = 1.0f,
		  float a = 1.0f) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	static Color WHITE()  { return { 1.0f, 1.0f, 1.0f, 1.0f }; }
	static Color BLACK()  { return { 0.0f, 0.0f, 0.0f, 1.0f }; }
	static Color RED()    { return { 1.0f, 0.0f, 0.0f, 1.0f }; }
	static Color GREEN()  { return { 0.0f, 1.0f, 0.0f, 1.0f }; }
	static Color BLUE()   { return { 0.0f, 0.0f, 1.0f, 1.0f }; }
	static Color CYAN()   { return { 0.0f, 1.0f, 1.0f, 1.0f }; }
	static Color PURPLE() { return { 1.0f, 0.0f, 1.0f, 1.0f }; }
	static Color YELLOW() { return { 1.0f, 1.0f, 0.0f, 1.0f }; }
};

