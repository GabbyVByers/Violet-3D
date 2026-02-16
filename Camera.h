
#pragma once

#include "Core.h"
#include "Algebra.h"

class Camera {
public:
	Camera() {
		projectionMatrix.reserve(16);
	}

	float getNearPlane() const { return nearPlane; }
	float getFarPlane()  const { return farPlane; }
	float getFOV()       const { return FOV; }
	void setNearPlane(float near) { nearPlane = near; }
	void setFarPlane(float far)   { farPlane = far; }
	void setFOV(float fov)        { FOV = fov; }

	float* getProjection(int width, int height) {
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

private:
	float nearPlane = 0.1f;
	float farPlane = 100.0f;
	float FOV = 60.0f;
	std::vector<float> projectionMatrix;
};

