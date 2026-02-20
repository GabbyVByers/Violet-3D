
#pragma once

#include "Core.h"
#include "Error.h"
#include "Vertex.h"
#include "Camera.h"
#include "Window.h"
#include "Transformation.h"

class Mesh {
public:
	// Constructor
	Mesh(std::string path = "default", int primType = GL_TRIANGLES);
	~Mesh();
	void assertVertexShader(uint vertProgram);
	void assertFragmentShader(uint fragProgram);
	void assertShaderProgram();
	static std::string loadFileAsString(std::string path);

	// Utilitys
	void setPrimativeType(int GL_PRIMATIVE);
	void setColor(const Color& color);
	void setRandomColors();
	void addVertex(const Vertex& vertex);

	// Getters
	const int getPrimativeType() const;
	const std::vector<Vertex>& getVertices() const;
	const size_t getNumVertices() const;
	const uint getShaderProgram() const;
	const uint getVAO() const;
	const uint getVBO() const;

	// Transformation
	void scale(double scale);
	void setScale(double scale);
	double getScale() const;
	void moveForward(double dist);
	void moveRight(double dist);
	void moveUp(double dist);
	void move(double3 position);
	void setPosition(double3 position);
	double3 getPosition() const;
	void resetOrientation();
	void rotate(double3 rot_axis, double theta);
	void pitch(double theta);
	void roll(double theta);
	void yaw(double theta);
	double3 getForwardDirection() const;
	double3 getRightDirection() const;
	double3 getUpDirection() const;
	const Matrix getModelMatrix() const;

	// Shape
	void sphere(double radius, size_t sub);
	void cube(double radius, size_t sub);

private:
	Transformation transformation;
	std::vector<Vertex> vertices;
	int primativeType = GL_TRIANGLES;
	uint shaderProgram = 0;
	uint VAO = 0;
	uint VBO = 0;
};

