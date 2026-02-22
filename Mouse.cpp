
#include "Mouse.h"

// Utilities

void Violet::Mouse::reset() {
	gl_mouseEvents.clear();
}

void Violet::Mouse::addMouseEvent(const gl_mouseEvent& mouseEvent) {
	gl_mouseEvents.push_back(mouseEvent);
}

void Violet::Mouse::update(double x, double y) {
	static double x_pos_prev = 0.0;
	static double y_pos_prev = 0.0;
	x_pos_prev = x_pos;
	y_pos_prev = y_pos;
	x_pos = x;
	y_pos = y;
	x_vel = x_pos - x_pos_prev;
	y_vel = y_pos - y_pos_prev;
}

// Interface

bool Violet::Mouse::isImGuiCaptured() {
	ImGuiIO& io = ImGui::GetIO();
	return io.WantCaptureMouse;
}

void Violet::Mouse::cursor(int cursorSetting) {
	glfwSetInputMode(Window::getGlfwWindowPtr(), GLFW_CURSOR, cursorSetting);
}

Violet::Vector2d Violet::Mouse::velocity() {
	return { x_vel, y_vel };
}

Violet::Vector2d Violet::Mouse::position() {
	return { x_pos, y_pos };
}

bool Violet::Mouse::pressing(int GLFW_BUTTON) {
	return glfwGetMouseButton(Window::getGlfwWindowPtr(), GLFW_BUTTON) == GLFW_PRESS;
}

bool Violet::Mouse::clicked(int GLFW_BUTTON, int ACTION) {
	for (gl_mouseEvent& mouseEvent : gl_mouseEvents) {
		if (mouseEvent.button == GLFW_BUTTON && mouseEvent.action == ACTION) {
			return true;
		}
	}
	return false;
}

