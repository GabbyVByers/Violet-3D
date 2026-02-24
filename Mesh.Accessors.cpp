
#include "Mesh.h"

void Violet::Mesh::setPrimativeType(int primativeType) {
	m_primativeType = primativeType;
}

int& Violet::Mesh::getPrimativeType() {
	return m_primativeType;
}

std::vector<Violet::Vertex>& Violet::Mesh::getVertices() {
	return m_vertices;
}

Violet::uint& Violet::Mesh::getVAO() {
	return m_VAO;
}

Violet::uint& Violet::Mesh::getVBO() {
	return m_VBO;
}

Violet::uint& Violet::Mesh::getShaderProgram() {
	return m_shaderProgram;
}

