
#include "Color.h"

Violet::Color::Color() {
	r = 1.0f;
	g = 1.0f;
	b = 1.0f;
	a = 1.0f;
}

Violet::Color::Color(float r, float g, float b, float a) {
	r = std::fmax(0.0f, std::fmin(r, 1.0f));
	g = std::fmax(0.0f, std::fmin(g, 1.0f));
	b = std::fmax(0.0f, std::fmin(b, 1.0f));
	a = std::fmax(0.0f, std::fmin(a, 1.0f));
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Violet::Color Violet::Color::Random() {
	return {
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		1.0f
	};
}

Violet::Color Violet::Color::White() {
	return {
		1.0f,
		1.0f,
		1.0f,
		1.0f
	};
}

Violet::Color Violet::Color::Black() {
	return {
		0.0f,
		0.0f,
		0.0f,
		1.0f
	};
}

Violet::Color Violet::Color::Red() {
	return {
		1.0f,
		0.0f,
		0.0f,
		1.0f
	};
}

Violet::Color Violet::Color::Green() {
	return {
		0.0f,
		1.0f,
		0.0f,
		1.0f
	};
}

Violet::Color Violet::Color::Blue() {
	return {
		0.0f,
		0.0f,
		1.0f,
		1.0f
	};
}

Violet::Color Violet::Color::Cyan() {
	return {
		0.0f,
		1.0f,
		1.0f,
		1.0f
	};
}

Violet::Color Violet::Color::Purple() {
	return {
		1.0f,
		0.0f,
		1.0f,
		1.0f
	};
}

Violet::Color Violet::Color::Yellow() {
	return {
		1.0f,
		1.0f,
		0.0f,
		1.0f
	};
}

