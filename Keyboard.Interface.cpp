
#include "Keyboard.h"

bool Keyboard::press(int KEY, int EDGE) {
	if ((EDGE != GLFW_PRESS) && (EDGE != GLFW_RELEASE)) {
		GLFWwindow* glfwWindow = Window::getGlfwWindowPtr();
		if (glfwWindow) {
			return glfwGetKey(glfwWindow, KEY) == GLFW_PRESS;
		}
	}
	else {
		for (KeyCallBackPacket& packet : keyCallBackPackets) {
			if (packet.key == KEY && packet.action == EDGE) {
				return true;
			}
		}
	}
	return false;
}

