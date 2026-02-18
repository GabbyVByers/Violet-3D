
#pragma once

#include "Core.h"
#include "Error.h"
#include "Vector.h"
#include "Camera.h"

class Color {
public:
	float r;
	float g;
	float b;
	float a;

	Color(float r = 1.0f,
		  float g = 1.0f,
		  float b = 1.0f,
		  float a = 1.0f) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};

class Vertex {
public:
	Vertex(float3 position = { 0.0f, 0.0f, 0.0f },
		   Color color = { 0.0f, 0.0f, 0.0f, 1.0f }) {
		this->position = position;
		this->color = color;
	}

	float3 position;
	Color color;
};

class Mesh {
public:
	// Constructor
	Mesh(std::string path = "default", int primType = GL_TRIANGLES);
	~Mesh();
	const void assertVertexShader(uint vertProgram);
	const void assertFragmentShader(uint fragProgram);
	const void assertShaderProgram();

	void setPrimative(int primType) { primativeType = primType; }
	const int getPrimative() const  { return primativeType; }

	const uint& getShaderProgram() const { return shaderProgram; }
	const uint& getVAO()           const { return VAO; }
	const uint& getVBO()           const { return VBO; }

	const std::vector<Vertex>& getVertices() const { return vertices;}
	void addVertex(const Vertex& vertex)           { vertices.push_back(vertex); }

	double4x4 getModelMatrix() {
		return modelTranslation * modelScale * modelRotation;
	}

	// Manipulation
	void resetPosition();
	void resetSize();
	void resetOrientation();
	void setPosition(double3 position);
	void setSize(double size);
	void translate(double3 offset);
	void rotate(double3 axis, double theta);
	void scale(double scale);

private:
	int primativeType = GL_TRIANGLES;
	uint shaderProgram = 0;
	uint VAO = 0;
	uint VBO = 0;
	std::vector<Vertex> vertices;

	double4x4 modelTranslation;
	double4x4 modelScale;
	double4x4 modelRotation;
	double4x4 modelMatrix;
};

