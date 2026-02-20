
#include "Keyboard.h"

Keyboard::Keyboard() {
	this->instanceCounter++;
	if (this->instanceCounter > 1)
		error(MULTIPLE_KEYBOARD_INSTANCES);
}

Keyboard::~Keyboard() {
	this->instanceCounter--;
	this->gl_keyEvents.clear();
}

const size_t Keyboard::getInstanceCounter() {
	return instanceCounter;
}

void Keyboard::reset() {
	gl_keyEvents.clear();
}

void Keyboard::addKeyEvent(const gl_keyEvent& keyEvent) {
	gl_keyEvents.push_back(keyEvent);
}

bool Keyboard::press(int KEY, int EDGE) const {
	if ((EDGE != GLFW_PRESS) && (EDGE != GLFW_RELEASE)) {
		GLFWwindow* glfwWindow = Window::getGlfwWindowPtr();
		if (glfwWindow) {
			return glfwGetKey(glfwWindow, KEY) == GLFW_PRESS;
		}
	}
	else {
		for (gl_keyEvent& keyEvent : this->gl_keyEvents) {
			if (keyEvent.key == KEY && keyEvent.action == EDGE) {
				return true;
			}
		}
	}
	return false;
}

