
#pragma once

#include "Core.h"
#include "Vector.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"
#include "Window.h"

class Keyboard {
public:
	Keyboard(Window& window) {
		glfwWindow = window.getGlfwWindowPtr();
	}

	bool isPressed(int KEY) {
		if (glfwWindow) {
			return glfwGetKey(glfwWindow, KEY) == GLFW_PRESS;
		}
	}

private:
	GLFWwindow* glfwWindow = nullptr;
};

