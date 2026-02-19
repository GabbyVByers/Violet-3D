
#include "Mesh.h"

inline static Color randColor() {
	return {
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		1.0
	};
}

void Mesh::setColor(const Color& color) {
	for (Vertex& vertex : vertices) {
		vertex.color = color;
	}
}

void Mesh::setRandomColors() {
	for (Vertex& vertex : vertices) {
		vertex.color = randColor();
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

