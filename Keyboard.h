
#pragma once

#include "Core.h"
#include "Vec3.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"
#include "Window.h"

class KeyCallBackPacket {
public:
	GLFWwindow* window;
	int key;
	int scancode;
	int action;
	int mods;
};

class Keyboard {
public:
	// Constructors
	Keyboard();
	~Keyboard();

	// Static
	static void reset();
	static void pushPacket(KeyCallBackPacket& packet);
	
	// Interface
	bool press(int KEY, int EDGE = INT_MAX);

private:
	inline static std::vector<KeyCallBackPacket> keyCallBackPackets;
	inline static size_t instanceCounter = 0;
};

