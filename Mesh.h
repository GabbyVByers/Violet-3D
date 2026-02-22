
#pragma once

#include "Violet.h"
#include "Error.h"
#include "Vertex.h"
#include "Camera.h"
#include "Window.h"
#include "Transformation.h"

class Violet::Mesh {
public:
	// Constructor
	Mesh(std::string path = "default", int primType = GL_TRIANGLES);
	~Mesh();
	void assertVertexShader(uint vertProgram);
	void assertFragmentShader(uint fragProgram);
	void assertShaderProgram();
	static std::string loadFileAsString(std::string path);
	void setColor(const Color& color);
	void setRandomColors();
	const Matrix getModelMatrix() const;

	// Shape
	void sphere(double radius, size_t sub);
	void cube(double radius, size_t sub);

	Transformation transformation;
	std::vector<Vertex> vertices;
	int primativeType = GL_TRIANGLES;
	uint shaderProgram = 0;
	uint VAO = 0;
	uint VBO = 0;
};

