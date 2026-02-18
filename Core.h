
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

#define MULTIPLE_WINDOW_INSTANCES   (int)0
#define MULTIPLE_KEYBOARD_INSTANCES (int)1
#define VERTEX_SHADER_FAILED        (int)2
#define FRAGMENT_SHADER_FAILED      (int)3
#define SHADER_PROGRAM_FAILED       (int)4

