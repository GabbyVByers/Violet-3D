
#include "Color.h"

Violet::Color Violet::Color::Random() {
	return {
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		1.0f
	};
}

Violet::Color Violet::Color::WHITE() {
	return {
		1.0f,
		1.0f,
		1.0f,
		1.0f
	};
}

Violet::Color Violet::Color::BLACK() {
	return {
		0.0f,
		0.0f,
		0.0f,
		1.0f
	};
}

Violet::Color Violet::Color::RED() {
	return {
		1.0f,
		0.0f,
		0.0f,
		1.0f
	};
}

Violet::Color Violet::Color::GREEN() {
	return {
		0.0f,
		1.0f,
		0.0f,
		1.0f
	};
}

Violet::Color Violet::Color::BLUE() {
	return {
		0.0f,
		0.0f,
		1.0f,
		1.0f
	};
}

Violet::Color Violet::Color::CYAN() {
	return {
		0.0f,
		1.0f,
		1.0f,
		1.0f
	};
}

Violet::Color Violet::Color::PURPLE() {
	return {
		1.0f,
		0.0f,
		1.0f,
		1.0f
	};
}

Violet::Color Violet::Color::YELLOW() {
	return {
		1.0f,
		1.0f,
		0.0f,
		1.0f
	};
}

