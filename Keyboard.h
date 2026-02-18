
#pragma once

#include "Core.h"
#include "Vector.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"
#include "Window.h"

struct KeyCallBackPacket {
	GLFWwindow* window;
	int key;
	int scancode;
	int action;
	int mods;
};

class Keyboard {
public:
	// Members
	Keyboard(Window& window);
	bool keyPressed(int KEY);
	bool keyPressedEvent(int KEY, int EDGE);

private:
	std::vector<KeyCallBackPacket> keyCallBackPackets;
	GLFWwindow* glfwWindow = nullptr;
};

