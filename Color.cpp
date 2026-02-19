
#include "Color.h"

Color::Color() {
	this->r = 1.0f;
	this->g = 1.0f;
	this->b = 1.0f;
	this->a = 1.0f;
}

Color::Color(float r, float g, float b, float a) {
	r = std::fmax(0.0f, std::fmin(r, 1.0f));
	g = std::fmax(0.0f, std::fmin(g, 1.0f));
	b = std::fmax(0.0f, std::fmin(b, 1.0f));
	a = std::fmax(0.0f, std::fmin(a, 1.0f));
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color Color::Random() {
	return {
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		1.0f
	};
}

Color Color::WHITE()  { return { 1.0f, 1.0f, 1.0f, 1.0f }; }
Color Color::BLACK()  { return { 0.0f, 0.0f, 0.0f, 1.0f }; }
Color Color::RED()    { return { 1.0f, 0.0f, 0.0f, 1.0f }; }
Color Color::GREEN()  { return { 0.0f, 1.0f, 0.0f, 1.0f }; }
Color Color::BLUE()   { return { 0.0f, 0.0f, 1.0f, 1.0f }; }
Color Color::CYAN()   { return { 0.0f, 1.0f, 1.0f, 1.0f }; }
Color Color::PURPLE() { return { 1.0f, 0.0f, 1.0f, 1.0f }; }
Color Color::YELLOW() { return { 1.0f, 1.0f, 0.0f, 1.0f }; }

