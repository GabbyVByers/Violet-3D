#pragma once

#include "Core.h"
#include "Vertex.h"

class Mesh {
public:
	// Constructor
	Mesh(std::string path = "shader");
	~Mesh();
	
	// Getters
	unsigned int& getShaderProgram();
	unsigned int& getVAO();
	unsigned int& getVBO();
	std::vector<Vertex>& getVertices();

	// PLY
	void loadPLY(std::string path);

private:
	unsigned int shaderProgram = 0;
	unsigned int VAO = 0, VBO = 0;
	std::vector<Vertex> vertices;
};

