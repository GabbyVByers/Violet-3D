
#include "Float3.h"

float3::float3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

double3 float3::as_double() const {
	return {
		(double)this->x,
		(double)this->y,
		(double)this->z
	};
}

