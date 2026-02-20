
#include "Keyboard.h"

Keyboard::Keyboard() {
	instanceCounter++;
	if (instanceCounter > 1)
		error(MULTIPLE_KEYBOARD_INSTANCES);
}

Keyboard::~Keyboard() {
	instanceCounter--;
}

void Keyboard::reset() {
	gl_keyEvents.clear();
}

void Keyboard::addKeyEvent(gl_keyEvent& keyEvent) {
	gl_keyEvents.push_back(keyEvent);
}

bool Keyboard::press(int KEY, int EDGE) {
	if ((EDGE != GLFW_PRESS) && (EDGE != GLFW_RELEASE)) {
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

