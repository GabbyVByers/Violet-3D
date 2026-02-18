
#pragma once

#include "Core.h"
#include "Vec3.h"
#include "Color.h"

class Vertex {
public:
	Vertex(float3 position = { 0.0f, 0.0f, 0.0f },
		   Color color = { 0.0f, 0.0f, 0.0f, 1.0f }) {
		this->position = position;
		this->color = color;
	}

	float3 position;
	Color color;
};

