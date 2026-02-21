
#include "Mesh.h"

void Violet::Mesh::setColor(const Color& color) {
	for (Vertex& vertex : vertices) {
		vertex.color = color;
	}
}

void Violet::Mesh::setRandomColors() {
	for (Vertex& vertex : vertices) {
		vertex.color = Color::Random();
	}
}

int& Violet::Mesh::borrowPrimativeType() {
	return primativeType;
}

std::vector<Violet::Vertex>& Violet::Mesh::borrowVertices() {
	return vertices;
}

uint& Violet::Mesh::borrowShaderProgram() {
	return shaderProgram;
}

uint& Violet::Mesh::borrowVAO() {
	return VAO;
}

uint& Violet::Mesh::borrowVBO() {
	return VBO;
}

const Violet::Matrix Violet::Mesh::getModelMatrix() const {
	return transformation.getModelMatrix();
}

