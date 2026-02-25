
#include "Window.h"

bool Violet::Window::isOpen() {
	return !glfwWindowShouldClose(m_glfwWindow);
}

void Violet::Window::vSync(bool vsync) {
	glfwSwapInterval((int)vsync);
}

Violet::Vector2i Violet::Window::getWindowSize() {
	int width, height; glfwGetFramebufferSize(m_glfwWindow, &width, &height);
	return {
		width,
		height
	};
}

GLFWwindow* Violet::Window::getWindowPtr() {
	return m_glfwWindow;
}

