
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
	Keyboard();
	~Keyboard();
	void reset();
	void pushPacket(KeyCallBackPacket& packet);
	bool keyPressed(int KEY);
	bool keyPressedEvent(int KEY, int EDGE);

private:
	inline static std::vector<KeyCallBackPacket> keyCallBackPackets;
	inline static size_t instanceCounter = 0;
};

