
#pragma once

#include "Core.h"
#include "Quaternions.h"
#include "Double3.h"

class float3 {
public:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;

	// Members
	float3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	double3 as_double() const;
};

