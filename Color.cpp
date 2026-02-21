
#include "Color.h"

Violet::Color::Color() {
	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
	a = 1.0f;
}

Violet::Color::Color(float new_r, float new_g, float new_b, float new_a) {
	new_r = std::fmax(0.0f, std::fmin(new_r, 1.0f));
	new_g = std::fmax(0.0f, std::fmin(new_g, 1.0f));
	new_b = std::fmax(0.0f, std::fmin(new_b, 1.0f));
	new_a = std::fmax(0.0f, std::fmin(new_a, 1.0f));
	r = new_r;
	g = new_g;
	b = new_b;
	a = new_a;
}

Violet::Color Violet::Color::Random() {
	return {
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		1.0f
	};
}

Violet::Color Violet::Color::WHITE()  { return { 1.0f, 1.0f, 1.0f, 1.0f }; }
Violet::Color Violet::Color::BLACK()  { return { 0.0f, 0.0f, 0.0f, 1.0f }; }
Violet::Color Violet::Color::RED()    { return { 1.0f, 0.0f, 0.0f, 1.0f }; }
Violet::Color Violet::Color::GREEN()  { return { 0.0f, 1.0f, 0.0f, 1.0f }; }
Violet::Color Violet::Color::BLUE()   { return { 0.0f, 0.0f, 1.0f, 1.0f }; }
Violet::Color Violet::Color::CYAN()   { return { 0.0f, 1.0f, 1.0f, 1.0f }; }
Violet::Color Violet::Color::PURPLE() { return { 1.0f, 0.0f, 1.0f, 1.0f }; }
Violet::Color Violet::Color::YELLOW() { return { 1.0f, 1.0f, 0.0f, 1.0f }; }

