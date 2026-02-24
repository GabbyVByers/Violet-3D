
#include "Color.h"

Violet::Color::Color() {
	m_r = 1.0f;
	m_g = 1.0f;
	m_b = 1.0f;
	m_a = 1.0f;
}

Violet::Color::Color(float r, float g, float b, float a) {
	r = std::fmax(0.0f, std::fmin(r, 1.0f));
	g = std::fmax(0.0f, std::fmin(g, 1.0f));
	b = std::fmax(0.0f, std::fmin(b, 1.0f));
	a = std::fmax(0.0f, std::fmin(a, 1.0f));
	m_r = r;
	m_g = g;
	m_b = b;
	m_a = a;
}

float& Violet::Color::red() {
	return m_r;
}

float& Violet::Color::green() {
	return m_g;
}

float& Violet::Color::blue() {
	return m_b;
}

float& Violet::Color::alpha() {
	return m_a;
}

