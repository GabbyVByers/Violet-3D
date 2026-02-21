
#include "Window.h"

void Violet::Window::framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
	glViewport(0, 0, width, height);
}

void Violet::Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	gl_keyEvent keyEvent = {
		window,
		key,
		scancode,
		action,
		mods
	};
	Keyboard::addKeyEvent(keyEvent);
}

void Violet::Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	gl_mouseEvent mouseEvent = {
		window,
		button,
		action,
		mods
	};
	Mouse::addMouseEvent(mouseEvent);
}

