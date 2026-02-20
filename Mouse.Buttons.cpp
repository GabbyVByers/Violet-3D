
#include "Mouse.h"

void Mouse::reset() {
	gl_mouseEvents.clear();
}

void Mouse::addMouseEvent(const gl_mouseEvent& mouseEvent) {
	gl_mouseEvents.push_back(mouseEvent);
}

bool Mouse::pressing(int GLFW_BUTTON) {
	ImGuiIO& io = ImGui::GetIO();
	if (io.WantCaptureMouse)
		return false;
	return glfwGetMouseButton(Window::getGlfwWindowPtr(), GLFW_BUTTON) == GLFW_PRESS;
}

bool Mouse::clicked(int GLFW_BUTTON, int EDGE) {
	ImGuiIO& io = ImGui::GetIO();
	if (io.WantCaptureMouse)
		return false;
	for (gl_mouseEvent& mouseEvent : gl_mouseEvents) {
		if (mouseEvent.button == GLFW_BUTTON && mouseEvent.action == EDGE) {
			return true;
		}
	}
	return false;
}

