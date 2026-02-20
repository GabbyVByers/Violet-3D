
#include "Keyboard.h"

void Keyboard::reset() {
	gl_keyEvents.clear();
}

void Keyboard::addKeyEvent(const gl_keyEvent& keyEvent) {
	gl_keyEvents.push_back(keyEvent);
}

bool Keyboard::pressing(int KEY) {
	GLFWwindow* glfwWindow = Window::getGlfwWindowPtr();
	if (glfwWindow) {
		return glfwGetKey(glfwWindow, KEY) == GLFW_PRESS;
	}
	return false;
}

bool Keyboard::pressed(int KEY, int EDGE) {
	for (gl_keyEvent& keyEvent : gl_keyEvents) {
		if (keyEvent.key == KEY && keyEvent.action == EDGE) {
			return true;
		}
	}
	return false;
}

