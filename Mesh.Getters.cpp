
#include "Mesh.h"

const int Mesh::getPrimativeType() const {
	return this->primativeType;
}

const std::vector<Vertex>& Mesh::getVertices() const {
	return this->vertices;
}

const size_t Mesh::getNumVertices() const {
	return this->vertices.size();
}

const uint Mesh::getShaderProgram() const {
	return this->shaderProgram;
}

const uint Mesh::getVAO() const {
	return this->VAO;
}

const uint Mesh::getVBO() const {
	return this->VBO;
}

