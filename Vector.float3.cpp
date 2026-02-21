
#include "Vector3f.h"

Violet::Vector3f::Vector3f(float new_x, float new_y, float new_z) {
	x = new_x;
	y = new_y;
	z = new_z;
}

Violet::Vector3d Violet::Vector3f::as_double() const {
	return {
		(double)x,
		(double)y,
		(double)z
	};
}

