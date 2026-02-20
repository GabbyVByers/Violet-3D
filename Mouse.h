
#pragma once

#include "Core.h"
#include "Error.h"
#include "Window.h"
#include "gl_mouseEvent.h"

class Mouse {
public:
	Mouse();
	~Mouse();
	static const size_t getInstanceCounter();
	static void reset();
	static void addMouseEvent(const gl_mouseEvent& mouseEvent);
	bool held(int GLFW_BUTTON) const;
	bool clicked(int GLFW_BUTTON, int EDGE) const;

private:
	inline static std::vector<gl_mouseEvent> gl_mouseEvents;
	inline static size_t instanceCounter = 0;
};

