
#include "Mesh.h"

void Mesh::setPrimative(int primType) {
	primativeType = primType;
}

const int Mesh::getPrimative() const {
	return primativeType;
}

const unsigned int& Mesh::getShaderProgram() const {
	return shaderProgram;
}

const unsigned int& Mesh::getVAO() const {
	return VAO;
}

const unsigned int& Mesh::getVBO() const {
	return VBO;
}

std::vector<Vertex>& Mesh::getVertices() {
	return vertices;
}

void Mesh::addVertex(const Vertex& vertex) {
	vertices.push_back(vertex);
}

