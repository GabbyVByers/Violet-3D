
#include "Window.h"

void Window::windowResizeCallback(GLFWwindow* glfwWindow, int width, int height) {
	glViewport(0, 0, width, height);
}

void Window::keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	KeyCallBackPacket packet = {
		window,
		key,
		scancode,
		action,
		mods
	};
	Keyboard::pushPacket(packet);
}

