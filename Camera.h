
#pragma once

#include "Core.h"
#include "Matrix.h"
#include "Transformation.h"

class Violet::Camera : public Violet::Transformation {
public:
	// Camera.cpp
	void setFOV(double FOV);
	void setFarPlane(double farPlane);
	void setNearPlane(double nearPlane);
	double getFOV() const;
	double getFarPlane() const;
	double getNearPlane() const;
	Matrix calculateProjectionMatrix(int width, int height) const;
	
	// Deletions
	void setScale(double scale) = delete;
	double getScale() = delete;
	Matrix calculateModelMatrix() const = delete;

private:
	// Members
	double m_FOV = 60.0;
	double m_farPlane = 100.0;
	double m_nearPlane = 0.1;
};

