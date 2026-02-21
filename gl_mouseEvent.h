
#pragma once

#include "Violet.h"

struct Violet::gl_mouseEvent {
	GLFWwindow* window;
	int button;
	int action;
	int mods;
};

