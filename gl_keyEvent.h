
#pragma once

#include "Violet.h"

struct Violet::gl_keyEvent {
	GLFWwindow* window;
	int key;
	int scancode;
	int action;
	int mods;
};

