
#include "Keyboard.h"

Keyboard::Keyboard() {
	instanceCounter++;
	if (instanceCounter > 1)
		error(MULTIPLE_KEYBOARD_INSTANCES);
}

Keyboard::~Keyboard() {
	instanceCounter--;
}

void Keyboard::reset() {
	keyCallBackPackets.clear();
}

void Keyboard::pushPacket(KeyCallBackPacket& packet) {
	keyCallBackPackets.push_back(packet);
}

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

