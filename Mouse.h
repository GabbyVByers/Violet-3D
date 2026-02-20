
#pragma once

#include "Core.h"
#include "Error.h"
#include "Window.h"
#include "gl_mouseEvent.h"
#include "Vector.double2.h"

class Mouse {
public:
	// Buttons
	static void reset();
	static void addMouseEvent(const gl_mouseEvent& mouseEvent);
	static bool pressing(int GLFW_BUTTON);
	static bool clicked(int GLFW_BUTTON, int EDGE);
	
	// Movement
	static void update(double x, double y);
	static double2 getPosition();
	static double2 getVelocity();

private:
	Mouse() = delete;
	~Mouse() = delete;

	inline static double x_pos = 0.0, y_pos = 0.0;
	inline static double x_vel = 0.0, y_vel = 0.0;
	inline static std::vector<gl_mouseEvent> gl_mouseEvents;
};

