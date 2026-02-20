
#include "Keyboard.h"

void Keyboard::reset() {
	gl_keyEvents.clear();
}

void Keyboard::addKeyEvent(const gl_keyEvent& keyEvent) {
	gl_keyEvents.push_back(keyEvent);
}

bool Keyboard::press(int KEY, int EDGE) {
	if (EDGE == INT_MAX) {
		GLFWwindow* glfwWindow = Window::getGlfwWindowPtr();
		if (glfwWindow) {
			return glfwGetKey(glfwWindow, KEY) == GLFW_PRESS;
		}
	}
	else {
		for (gl_keyEvent& keyEvent : gl_keyEvents) {
			if (keyEvent.key == KEY && keyEvent.action == EDGE) {
				return true;
			}
		}
	}
	return false;
}

