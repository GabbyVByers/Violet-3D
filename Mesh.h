
#pragma once

#include "Core.h"
#include "Vertex.h"
#include "Camera.h"
#include "Window.h"
#include "Transformation.h"

class Violet::Mesh {
public:
	// Mesh.Accessors.cpp
	void setPrimativeType(int primativeType);
	int& getPrimativeType();
	std::vector<Vertex>& getVertices();
	uint& getVAO();
	uint& getVBO();
	uint& getShaderProgram();

	// Mesh.Transformation.cpp
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

	// Mesh.Utilities.cpp
	Mesh(std::string path = "default", int primativeType = GL_TRIANGLES);
	~Mesh();
	void assertVertexShader(uint vertProgram) const;
	void assertFragmentShader(uint fragProgram) const;
	void assertShaderProgram() const;
	static std::string loadFileAsString(std::string path);
	void setColor(const Color& color);
	void setRandomColors();
	const Matrix calculateModelMatrix() const;

private:
	Transformation m_transformation;
	int m_primativeType = GL_TRIANGLES;
	std::vector<Vertex> m_vertices;
	uint m_VAO = 0, m_VBO = 0;
	uint m_shaderProgram = 0;
};

