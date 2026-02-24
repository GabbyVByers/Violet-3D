
#include "Mouse.h"

void Violet::Mouse::reset() {
	m_gl_mouseEvents.clear();
}

void Violet::Mouse::addMouseEvent(const gl_mouseEvent& mouseEvent) {
	m_gl_mouseEvents.push_back(mouseEvent);
}

void Violet::Mouse::update(double x, double y) {
	static double x_pos_prev = 0.0;
	static double y_pos_prev = 0.0;
	x_pos_prev = m_x_pos;
	y_pos_prev = m_y_pos;
	m_x_pos = x;
	m_y_pos = y;
	m_x_vel = m_x_pos - x_pos_prev;
	m_y_vel = m_y_pos - y_pos_prev;
}

