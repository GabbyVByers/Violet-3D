
#include "Mesh.h"

unsigned int& Mesh::getShaderProgram() {
	return shaderProgram;
}

unsigned int& Mesh::getVAO() {
	return VAO;
}

unsigned int& Mesh::getVBO() {
	return VBO;
}

std::vector<Vertex>& Mesh::getVertices() {
	return vertices;
}

