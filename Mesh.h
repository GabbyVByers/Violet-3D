
#pragma once

#include "Core.h"
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
	const void assertVertexShader(int vertProgram);
	const void assertFragmentShader(unsigned int fragProgram);
	const void assertShaderProgram();

	void setPrimative(int primType) { primativeType = primType; }
	const int getPrimative() const  { return primativeType; }

	const unsigned int& getShaderProgram() const { return shaderProgram; }
	const unsigned int& getVAO()           const { return VAO; }
	const unsigned int& getVBO()           const { return VBO; }

	const std::vector<Vertex>& getVertices() const { return vertices;}
	void addVertex(const Vertex& vertex)           { vertices.push_back(vertex); }

	void rotate(double3 axis, double theta) { modelMatrix.rotate(axis, theta); }
	void scale(double  scale)               { modelMatrix.scale(scale); }
	void translate(double3 translation)     { modelMatrix.translate(translation); }
	const double4x4& getModelMatrix() const { return modelMatrix; }

private:
	int primativeType = GL_TRIANGLES;
	unsigned int shaderProgram = 0;
	unsigned int VAO = 0, VBO = 0;
	std::vector<Vertex> vertices;
	double4x4 modelMatrix;
};

