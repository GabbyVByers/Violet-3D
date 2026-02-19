
#include "Mesh.h"

void Mesh::setColor(const Color& color) {
	for (Vertex& vertex : vertices) {
		vertex.color = color;
	}
}

void Mesh::setRandomColors() {
	for (Vertex& vertex : vertices) {
		vertex.color = Color::Random();
	}
}

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

size_t Mesh::getNumVertices() {
	return vertices.size();
}

double4x4 Mesh::getModelMatrix() {
	return modelTranslation * modelScale * modelRotation;
}

