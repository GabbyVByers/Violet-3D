
#include "Mouse.h"

bool Violet::Mouse::isImGuiCaptured() {
	ImGuiIO& io = ImGui::GetIO();
	return io.WantCaptureMouse;
}

void Violet::Mouse::cursor(int cursorSetting) {
	glfwSetInputMode(Window::getGLFW(), GLFW_CURSOR, cursorSetting);
}

Violet::Vector2d Violet::Mouse::velocity() {
	return { m_x_vel, m_y_vel };
}

Violet::Vector2d Violet::Mouse::position() {
	return { m_x_pos, m_y_pos };
}

bool Violet::Mouse::pressing(int GLFW_BUTTON) {
	return glfwGetMouseButton(Window::getGLFW(), GLFW_BUTTON) == GLFW_PRESS;
}

bool Violet::Mouse::clicked(int GLFW_BUTTON, int ACTION) {
	for (gl_mouseEvent& mouseEvent : m_gl_mouseEvents) {
		if (mouseEvent.button == GLFW_BUTTON && mouseEvent.action == ACTION) {
			return true;
		}
	}
	return false;
}

