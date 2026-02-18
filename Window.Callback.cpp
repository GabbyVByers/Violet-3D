
#include "Window.h"

void Window::framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
	glViewport(0, 0, width, height);
}

void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

