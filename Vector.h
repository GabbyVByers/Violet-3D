
#pragma once

#include "Core.h"

struct double3 {
	double x;
	double y;
	double z;

	double3(double x = 0.0,
		    double y = 0.0,
		    double z = 0.0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void normalize() {
		double len = sqrt((x * x) + (y * y) + (z * z));
		x /= len;
		y /= len;
		z /= len;
	}
};

struct float3 {
	float x;
	float y;
	float z;

	float3(float x = 0.0f,
		   float y = 0.0f,
		   float z = 0.0f) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

