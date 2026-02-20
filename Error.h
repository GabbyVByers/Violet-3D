
#pragma once

#include "Core.h"

#define VERTEX_SHADER_FAILED         (size_t)0
#define FRAGMENT_SHADER_FAILED       (size_t)1
#define SHADER_PROGRAM_FAILED        (size_t)2
#define NULL_WINDOW                  (size_t)3
#define MULTIPLE_WINDOW_INSTANCES    (size_t)4
#define WINDOW_CREATION_FAILED       (size_t)5
#define MESH_HAS_NO_VERTICES         (size_t)6
#define NORMALIZE_VECTOR_LENGTH_ZERO (size_t)7

inline void error(size_t ERROR_TYPE) {
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
	if (ERROR_TYPE == WINDOW_CREATION_FAILED) {
		std::cerr << "CATASTROPHIC ERROR: Window Creation Failed!\n";
		std::terminate();
	}
	if (ERROR_TYPE == MESH_HAS_NO_VERTICES) {
		std::cerr << "CATASTROPHIC ERROR: Attempted to Draw Mesh with Zero Vertices!\n";
		std::terminate();
	}
	if (ERROR_TYPE == NORMALIZE_VECTOR_LENGTH_ZERO) {
		std::cerr << "WARNING: Attempted to Normalize Vector of Length Zero!\n";
		return;
	}
}

