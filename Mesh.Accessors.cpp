
#include "Mesh.h"

int Violet::Mesh::getPrimativeType() const {
	return m_primativeType;
}

Violet::uint Violet::Mesh::getVAO() const {
	return m_VAO;
}

Violet::uint Violet::Mesh::getVBO() const {
	return m_VBO;
}

Violet::uint Violet::Mesh::getShaderProgram() const {
	return m_shaderProgram;
}

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

