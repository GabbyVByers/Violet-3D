
#include "Keyboard.h"

Keyboard::Keyboard(Window& window) {
	keyCallBackPackets.reserve(32);
	glfwWindow = window.getGlfwWindowPtr();
}

bool Keyboard::keyPressed(int KEY) {
	if (glfwWindow) {
		return glfwGetKey(glfwWindow, KEY) == GLFW_PRESS;
	}
}

bool Keyboard::keyPressedEvent(int KEY, int EDGE) {
	for (KeyCallBackPacket& packet : keyCallBackPackets) {
		if (packet.key == KEY && packet.action == EDGE) {
			return true;
		}
	}
	return false;
}

