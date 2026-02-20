
#include "Window.h"

void Window::framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
	glViewport(0, 0, width, height);
}

void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	gl_keyEvent keyEvent = {
		window,
		key,
		scancode,
		action,
		mods
	};
	Keyboard::addKeyEvent(keyEvent);
}

void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	gl_mouseEvent mouseEvent = {
		window,
		button,
		action,
		mods
	};
	Mouse::addMouseEvent(mouseEvent);
}

