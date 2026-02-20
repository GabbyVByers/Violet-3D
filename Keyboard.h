
#pragma once

#include "Core.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"
#include "Window.h"
#include "gl_keyEvent.h"

class Keyboard {
public:
	Keyboard();
	~Keyboard();
	static const size_t getInstanceCounter();
	static void reset();
	static void addKeyEvent(const gl_keyEvent& keyEvent);
	bool press(int KEY, int EDGE = INT_MAX) const;

private:
	inline static std::vector<gl_keyEvent> gl_keyEvents;
	inline static size_t instanceCounter = 0;
};

