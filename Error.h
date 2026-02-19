
#pragma once

#include "Core.h"

#define VERTEX_SHADER_FAILED        (uint)0
#define FRAGMENT_SHADER_FAILED      (uint)1
#define SHADER_PROGRAM_FAILED       (uint)2
#define NULL_WINDOW                 (uint)3
#define MULTIPLE_WINDOW_INSTANCES   (uint)4
#define MULTIPLE_KEYBOARD_INSTANCES (uint)5
#define WINDOW_CREATION_FAILED      (uint)6
#define MESH_HAS_NO_VERTICES        (uint)7

static inline void error(int ERROR_TYPE) {
	if (ERROR_TYPE == VERTEX_SHADER_FAILED) {
		std::cerr << "CATASTROPHIC ERROR: Failed to Compile Vertex Shader!\n";
		std::terminate();
	}
	if (ERROR_TYPE == FRAGMENT_SHADER_FAILED) {
		std::cerr << "CATASTROPHIC ERROR: Failed to Compile Fragment Shader!\n";
		std::terminate();
	}
	if (ERROR_TYPE == SHADER_PROGRAM_FAILED) {
		std::cerr << "CATASTROPHIC ERROR: Failed to Build Shader Program!\n";
		std::terminate();
	}
	if (ERROR_TYPE == NULL_WINDOW) {
		std::cerr << "CATASTROPHIC ERROR: GLFW Window is Nullptr!\n";
		std::terminate();
	}
	if (ERROR_TYPE == MULTIPLE_WINDOW_INSTANCES) {
		std::cerr << "CATASTROPHIC ERROR: Multiple Instances of Window is Illegal!\n";
		std::terminate();
	}
	if (ERROR_TYPE == MULTIPLE_KEYBOARD_INSTANCES) {
		std::cerr << "CATASTROPHIC ERROR: Multiple Instances of Keyboard is Illegal!\n";
		std::terminate();
	}
	if (ERROR_TYPE == WINDOW_CREATION_FAILED) {
		std::cerr << "CATASTROPHIC ERROR: Window Creation Failed!\n";
		std::terminate();
	}
	if (ERROR_TYPE == MESH_HAS_NO_VERTICES) {
		std::cerr << "CATASTROPHIC ERROR: Attempted to Draw Mesh with Zero Vertices!\n";
		std::terminate();
	}
}

