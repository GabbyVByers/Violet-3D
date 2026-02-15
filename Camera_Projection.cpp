
#include "Camera.h"

float* Camera::getProjection(int width, int height) {
	float aspectRatio = (float)width / (float)height;
	float fovRadians = FOV * (float)PI / 180.0f;
	float f = 1.0f / tanf(fovRadians / 2.0f);
	projectionMatrix = {
		(f / aspectRatio), 0.0f, 0.0f, 0.0f,
		0.0f, f, 0.0f, 0.0f,
		0.0f, 0.0f, ((farPlane + nearPlane) / (nearPlane - farPlane)), -1.0f,
		0.0f, 0.0f, ((2.0f * farPlane * nearPlane) / (nearPlane - farPlane)), 0.0f
	};
	return &projectionMatrix[0];
}

