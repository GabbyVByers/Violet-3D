
#pragma once

#include "Core.h"
#include "Error.h"
#include "Window.h"
#include "gl_mouseEvent.h"

class Mouse {
public:
	static void reset();
	static void addMouseEvent(const gl_mouseEvent& mouseEvent);
	static bool held(int GLFW_BUTTON);
	static bool clicked(int GLFW_BUTTON, int EDGE);

private:
	Mouse() = delete;
	~Mouse() = delete;
	inline static std::vector<gl_mouseEvent> gl_mouseEvents;
};

