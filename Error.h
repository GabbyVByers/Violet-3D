
#pragma once

#include "Core.h"

#define VERTEX_SHADER_FAILED        (int)1
#define FRAGMENT_SHADER_FAILED      (int)2
#define SHADER_PROGRAM_FAILED       (int)3

static inline void error(int ERROR_TYPE, char log[1024] = { '\0' }) {
	static const std::string CE = "CATASTROPHIC ERROR: ";
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

