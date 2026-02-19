
#pragma once

#include "Core.h"
#include "Error.h"
#include "Vec3.h"
#include "Vertex.h"
#include "Camera.h"
#include "Window.h"

class Mesh {
public:
	// Constructor
	Mesh(std::string path = "default", int primType = GL_TRIANGLES);
	~Mesh();
	const void assertVertexShader(uint vertProgram);
	const void assertFragmentShader(uint fragProgram);
	const void assertShaderProgram();

	// Members
	void setColor(const Color& color);
	void setRandomColors();
	void setPrimative(int primType);
	const int getPrimative() const;
	const uint& getShaderProgram() const;
	const uint& getVAO() const ;
	const uint& getVBO() const ;
	const std::vector<Vertex>& getVertices() const;
	void addVertex(const Vertex& vertex);
	double4x4 getModelMatrix();

	// Manipulation
	void resetPosition();
	void resetSize();
	void resetOrientation();
	void setPosition(double3 position);
	void setSize(double size);
	void translate(double3 offset);
	void scale(double scale);
	void rotate(double3 axis, double theta);

	// Shapes
	void sphere(double radius);
	void cube(double radius, uint subDivisions);

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

