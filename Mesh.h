
#pragma once

#include "Core.h"
#include "Algebra.h"
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

struct Vertex {
	float3 pos;
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

	// Accessors
	void setPrimative(int primType);
	const int getPrimative() const;
	const unsigned int& getShaderProgram() const;
	const unsigned int& getVAO() const;
	const unsigned int& getVBO() const;
	std::vector<Vertex>& getVertices();
	void addVertex(const Vertex& vertex);

private:
	int primativeType = GL_TRIANGLES;
	unsigned int shaderProgram = 0;
	unsigned int VAO = 0, VBO = 0;
	std::vector<Vertex> vertices;
};

