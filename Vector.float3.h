
#pragma once

#include "Core.h"
#include "Quaternion.h"
#include "Vector.double3.h"

class float3 {
public:
	float3(float new_x = 0.0f, float new_y = 0.0f, float new_z = 0.0f);
	double3 as_double() const;

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

