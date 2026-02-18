
#pragma once

#include "Core.h"

#define VERTEX_SHADER_FAILED        (uint)1
#define FRAGMENT_SHADER_FAILED      (uint)2
#define SHADER_PROGRAM_FAILED       (uint)3
#define NULL_WINDOW                 (uint)4
#define MULTIPLE_WINDOW_INSTANCES   (uint)5
#define MULTIPLE_KEYBOARD_INSTANCES (uint)6

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
}

