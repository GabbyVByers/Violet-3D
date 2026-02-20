
#include "Camera.h"

const Matrix Camera::getViewMatrix() const {
	return transformation.getMatrix();
}

