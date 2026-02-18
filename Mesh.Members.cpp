
#include "Mesh.h"

void Mesh::setPrimative(int primType) {
	primativeType = primType;
}

const int Mesh::getPrimative() const {
	return primativeType;
}

const uint& Mesh::getShaderProgram() const {
	return shaderProgram;
}

const uint& Mesh::getVAO() const {
	return VAO;
}

const uint& Mesh::getVBO() const {
	return VBO;
}

const std::vector<Vertex>& Mesh::getVertices() const {
	return vertices;
}

void Mesh::addVertex(const Vertex& vertex) {
	vertices.push_back(vertex);
}

double4x4 Mesh::getModelMatrix() {
	return modelTranslation * modelScale * modelRotation;
}

