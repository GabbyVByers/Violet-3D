
#pragma once

#include "Core.h"
#include "Window.h"
#include "gl_mouseEvent.h"
#include "Vector.h"

class Violet::Mouse {
public:
	// Mouse.Utilities.cpp
	static void reset();
	static void addMouseEvent(const gl_mouseEvent& mouseEvent);
	static void update(double x, double y);
	
	// Mouse.Internal.cpp
	static bool isImGuiCaptured();
	static void cursor(int cursorSetting);
	static Vector2d velocity();
	static Vector2d position();
	static bool pressing(int GLFW_BUTTON);
	static bool clicked(int GLFW_BUTTON, int EDGE);

private:
	Mouse() = delete;
	~Mouse() = delete;
	inline static double m_x_pos = 0.0, m_y_pos = 0.0;
	inline static double m_x_vel = 0.0, m_y_vel = 0.0;
	inline static std::vector<gl_mouseEvent> m_gl_mouseEvents;
};

