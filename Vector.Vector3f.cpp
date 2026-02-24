
#include "Vector.h"

Violet::Vector3f::Vector3f(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

Violet::Vector3d Violet::Vector3f::as_double() const {
	return {
		(double)x,
		(double)y,
		(double)z
	};
}

