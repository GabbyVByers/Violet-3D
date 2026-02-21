
#pragma once

#include "Violet.h"
#include "Quaternion.h"
#include "Vector3d.h"

class Violet::Vector3f {
public:
	Vector3f(float new_x = 0.0f, float new_y = 0.0f, float new_z = 0.0f);
	Vector3d as_double() const;

	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
};

