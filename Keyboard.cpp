
#include "Keyboard.h"

void Violet::Keyboard::reset() {
	gl_keyEvents.clear();
}

void Violet::Keyboard::addKeyEvent(const gl_keyEvent& keyEvent) {
	gl_keyEvents.push_back(keyEvent);
}

bool Violet::Keyboard::pressing(int KEY) {
	GLFWwindow* glfwWindow = Window::getGlfwWindowPtr();
	if (glfwWindow) {
		return glfwGetKey(glfwWindow, KEY) == GLFW_PRESS;
	}
	return false;
}

bool Violet::Keyboard::pressed(int KEY, int EDGE) {
	for (gl_keyEvent& keyEvent : gl_keyEvents) {
		if (keyEvent.key == KEY && keyEvent.action == EDGE) {
			return true;
		}
	}
	return false;
}

