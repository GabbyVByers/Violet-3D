
#pragma once

#include "Core.h"

#define MULTIPLE_WINDOW_INSTANCES   (int)0
#define MULTIPLE_KEYBOARD_INSTANCES (int)1
#define VERTEX_SHADER_FAILED        (int)2
#define FRAGMENT_SHADER_FAILED      (int)3
#define SHADER_PROGRAM_FAILED       (int)4

static inline void error(int ERROR_TYPE, char log[1024] = { '\0' }) {
	static const std::string CE = "CATASTROPHIC ERROR: ";
	if (ERROR_TYPE == MULTIPLE_WINDOW_INSTANCES) {
		std::cerr << CE << "Multiple Instances of Window Class is Illegal\n";
		std::terminate();
	}
	if (ERROR_TYPE == MULTIPLE_KEYBOARD_INSTANCES) {
		std::cerr << CE << "Multiple Instances of Keyboard Class is Illegal\n";
		std::terminate();
	}
	if (ERROR_TYPE == VERTEX_SHADER_FAILED) {
		std::cerr << CE << "Failed to Compile Vertex Shader" << log << std::endl;
		std::terminate();
	}
	if (ERROR_TYPE == FRAGMENT_SHADER_FAILED) {
		std::cerr << CE << "Failed to Compile Fragment Shader" << log << std::endl;
		std::terminate();
	}
	if (ERROR_TYPE == SHADER_PROGRAM_FAILED) {
		std::cerr << CE << "Failed to Build Shader Program" << log << std::endl;
		std::terminate();
	}
}

