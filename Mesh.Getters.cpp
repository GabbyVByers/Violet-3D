
#include "Mesh.h"

const int Mesh::getPrimativeType() const {
	return primativeType;
}

const std::vector<Vertex>& Mesh::getVertices() const {
	return vertices;
}

const size_t Mesh::getNumVertices() const {
	return vertices.size();
}

const uint Mesh::getShaderProgram() const {
	return shaderProgram;
}

const uint Mesh::getVAO() const {
	return VAO;
}

const uint Mesh::getVBO() const {
	return VBO;
}

