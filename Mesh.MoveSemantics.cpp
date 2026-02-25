
#include "Mesh.h"

Violet::Mesh::Mesh(Mesh&& other) noexcept
	: m_transformation(other.m_transformation)
	, m_primativeType(other.m_primativeType)
	, m_vertices(std::move(other.m_vertices))
	, m_VAO(other.m_VAO)
	, m_VBO(other.m_VBO)
	, m_shaderProgram(other.m_shaderProgram)
{
	other.m_VAO = 0;
	other.m_VBO = 0;
	other.m_shaderProgram = 0;
}

Violet::Mesh& Violet::Mesh::operator = (Mesh&& other) noexcept {
	if (this != &other) {
		// Clean up our current resources
		glDeleteProgram(m_shaderProgram);
		glDeleteBuffers(1, &m_VBO);
		glDeleteVertexArrays(1, &m_VAO);

		// Steal other's resources
		m_transformation = other.m_transformation;
		m_primativeType = other.m_primativeType;
		m_vertices = std::move(other.m_vertices);
		m_VAO = other.m_VAO;
		m_VBO = other.m_VBO;
		m_shaderProgram = other.m_shaderProgram;

		other.m_VAO = 0;
		other.m_VBO = 0;
		other.m_shaderProgram = 0;
	}
	return *this;
}

