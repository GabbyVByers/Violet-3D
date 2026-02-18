
#include "Keyboard.h"

void Keyboard::reset() {
	keyCallBackPackets.clear();
}

void Keyboard::pushPacket(KeyCallBackPacket& packet) {
	keyCallBackPackets.push_back(packet);
}

bool Keyboard::keyPressed(int KEY) {
	GLFWwindow* glfwWindow = Window::getGlfwWindowPtr();
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

