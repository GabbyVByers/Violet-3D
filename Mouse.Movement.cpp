
#include "Mouse.h"

void Mouse::update(double x, double y) {
	static double x_pos_prev = 0.0;
	static double y_pos_prev = 0.0;
	x_pos_prev = x_pos;
	y_pos_prev = y_pos;
	x_pos = x;
	y_pos = y;
	x_vel = x_pos - x_pos_prev;
	y_vel = y_pos - y_pos_prev;
}

double2 Mouse::getPosition() {
	return { x_pos, y_pos };
}

double2 Mouse::getVelocity() {
	return { x_vel, y_vel };
}

