
#pragma once

#include "Violet.h"
#include "Error.h"
#include "Window.h"
#include "gl_mouseEvent.h"
#include "Vector2d.h"

class Violet::Mouse {
public:
	// Utilities
	static void reset();
	static void addMouseEvent(const gl_mouseEvent& mouseEvent);
	static void update(double x, double y);
	
	// Interface
	static bool isImGuiCaptured();
	static void cursor(int cursorSetting);
	static Vector2d getVelocity();
	static Vector2d getPosition();
	static bool pressing(int GLFW_BUTTON);
	static bool clicked(int GLFW_BUTTON, int EDGE);

private:
	Mouse() = delete;
	~Mouse() = delete;

	inline static double x_pos = 0.0, y_pos = 0.0;
	inline static double x_vel = 0.0, y_vel = 0.0;
	inline static std::vector<gl_mouseEvent> gl_mouseEvents;
};

