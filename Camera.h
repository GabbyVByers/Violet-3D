
#pragma once

#include "Core.h"
#include "Matrix.h"
#include "Transformation.h"

class Violet::Camera {
public:
	// Camera.Accessors.cpp
	void setFOV(double FOV);
	void setFarPlane(double farPlane);
	void setNearPlane(double nearPlane);
	double& getFOV();
	double& getFarPlane();
	double& getNearPlane();

	// Camera.Transformation.cpp
	void setScale(double scale);
	void setPosition(Vector3d position);
	void setQuaternionRotation(Quaternion quaternion);
	double& getScale();
	Vector3d& getPosition();
	Quaternion& getQuaternionRotation();
	void rotateAroundAxis(Vector3d rotation_axis, double theta);
	Vector3d forward() const;
	Vector3d right() const;
	Vector3d up() const;
	void move(Vector3d direction, double distance);
	void pitch(double theta);
	void roll(double theta);
	void yaw(double theta);
	
	// Camera.Matrix.cpp
	Matrix calculateViewMatrix() const;
	Matrix calculateProjectionMatrix(int width, int height) const;

private:
	double m_FOV = 60.0;
	double m_farPlane = 100.0;
	double m_nearPlane = 0.1;
	Transformation m_transformation;
};

