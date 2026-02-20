
#include "Vector.float3.h"

float3::float3(float new_x, float new_y, float new_z) {
	x = new_x;
	y = new_y;
	z = new_z;
}

double3 float3::as_double() const {
	return {
		(double)x,
		(double)y,
		(double)z
	};
}

