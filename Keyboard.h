
#pragma once

#include "Core.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"
#include "Window.h"
#include "gl_keyEvent.h"

class Keyboard {
public:
	static void reset();
	static void addKeyEvent(const gl_keyEvent& keyEvent);
	static bool press(int KEY, int EDGE = INT_MAX);

private:
	Keyboard() = delete;
	~Keyboard() = delete;
	inline static std::vector<gl_keyEvent> gl_keyEvents;
};

