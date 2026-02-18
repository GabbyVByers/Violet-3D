
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

#define uchar unsigned char
#define uint unsigned int
#define PI (double)3.141592653589793

class Window;
class Mesh;
class Camera;
class Keyboard;
class KeyCallBackPacket;
class Vertex;
class Color;
class float3;
class Quaternion;
class double4x4;
class double3;

