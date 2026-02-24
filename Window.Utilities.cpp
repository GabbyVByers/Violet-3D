
#include "Window.h"

bool Violet::Window::isOpen() {
	return !glfwWindowShouldClose(m_glfwWindow);
}

void Violet::Window::vSync(bool vsync) {
	glfwSwapInterval((int)vsync);
}

Violet::Vector2i Violet::Window::getSize() {
	int width, height; glfwGetFramebufferSize(m_glfwWindow, &width, &height);
	return {
		width,
		height
	};
}

GLFWwindow* Violet::Window::getGLFW() {
	return m_glfwWindow;
}

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

