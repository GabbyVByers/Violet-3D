
#include "Mouse.h"

Mouse::Mouse() {
	this->instanceCounter++;
	if (this->instanceCounter > 1)
		error(MULTIPLE_MOUSE_INSTANCES);
}

Mouse::~Mouse() {
	this->instanceCounter--;
	this->gl_mouseEvents.clear();
}

const size_t Mouse::getInstanceCounter() {
	return instanceCounter;
}

void Mouse::reset() {
	gl_mouseEvents.clear();
}

void Mouse::addMouseEvent(const gl_mouseEvent& mouseEvent) {
	gl_mouseEvents.push_back(mouseEvent);
}

bool Mouse::held(int GLFW_BUTTON) const {
	return glfwGetMouseButton(Window::getGlfwWindowPtr(), GLFW_BUTTON) == GLFW_PRESS;
}

bool Mouse::clicked(int GLFW_BUTTON, int EDGE) const {
	for (gl_mouseEvent& mouseEvent : this->gl_mouseEvents) {
		if (mouseEvent.button == GLFW_BUTTON && mouseEvent.action == EDGE) {
			return true;
		}
	}
	return false;
}

