
#include "Window.h"

bool Window::isOpen() {
	if (!glfwWindow)
		error(NULL_WINDOW);
	return !glfwWindowShouldClose(glfwWindow);
}

void Window::setVerticalSyncEnable(bool vsync) {
	if (!glfwWindow)
		error(NULL_WINDOW);
	glfwSwapInterval((int)vsync);
}

GLFWwindow* Window::getGlfwWindowPtr() {
	if (!glfwWindow)
		error(NULL_WINDOW);
	return glfwWindow;
}

