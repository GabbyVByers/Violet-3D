
#pragma once

#include "Core.h"

class Camera {
public:
	// Constructor
	Camera();

	// Getters
	static float getNearPlane();
	static float getFarPlane();
	static float getFOV();
	
	// Setters
	static void setNearPlane(float near);
	static void setFarPlane(float far);
	static void setFOV(float fov);

	// Projection
	float* getProjection(int width, int height);

private:
	inline static float nearPlane = 0.1f;
	inline static float farPlane = 100.0f;
	inline static float FOV = 60.0f;
	std::vector<float> projectionMatrix;
};

