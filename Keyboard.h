
#pragma once

#include "Core.h"
#include "Vec3.h"
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
	static void reset();
	static void pushPacket(KeyCallBackPacket& packet);
	static bool keyPressed(int KEY);
	static bool keyPressedEvent(int KEY, int EDGE);

private:
	Keyboard() = delete;
	~Keyboard() = delete;

	inline static std::vector<KeyCallBackPacket> keyCallBackPackets;
};

