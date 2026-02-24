
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

