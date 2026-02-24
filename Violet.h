
#pragma once

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include <math.h>
#include <cassert>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>
#include "Container.h"

#define Vi Violet

namespace Violet
{
	using uchar = unsigned char;
	using uint = unsigned int;
	constexpr double PI = 3.14159265358979323846;

	class Window;
	class Mesh;
	class Shape;
	class Camera;
	class Keyboard;
	class Mouse;
	class Color;
	class Quaternion;
	class Transformation;
	class Matrix;
	struct gl_keyEvent;
	struct gl_mouseEvent;
	struct Vertex;
	struct Vector2i;
	struct Vector2f;
	struct Vector2d;
	struct Vector3f;
	struct Vector3d;
}

