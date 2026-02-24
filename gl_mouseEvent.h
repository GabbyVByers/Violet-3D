
#pragma once

#include "Core.h"

struct Violet::gl_mouseEvent {
	GLFWwindow* window;
	int button;
	int action;
	int mods;
};

