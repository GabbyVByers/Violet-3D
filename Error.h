
#pragma once

#include "Core.h"

static inline void error(int ERROR_TYPE) {
	static const std::string CE = "CATASTROPHIC ERROR: ";
	if (ERROR_TYPE == MULTIPLE_WINDOW_INSTANCES) {
		std::cerr << CE << "Multiple Instances of Window Class is Illegal\n";
		std::terminate();
	}
}

