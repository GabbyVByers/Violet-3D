
#include "Mesh.h"

void Violet::Mesh::assertVertexShader(uint vertProgram) const {
	int success = -1;
	char log[1024] = { '\0' };
	glGetShaderiv(vertProgram, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertProgram, 1024, nullptr, log);
		std::cerr << "Vertex Shader Failed!\n";
		std::cerr << log << std::endl;
	}
}

void Violet::Mesh::assertFragmentShader(uint fragProgram) const {
	int success = -1;
	char log[1024] = { '\0' };
	glGetShaderiv(fragProgram, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragProgram, 1024, nullptr, log);
		std::cerr << "Fragment Shader Failed!\n";
		std::cerr << log << std::endl;
	}
}

void Violet::Mesh::assertShaderProgram() const {
	int success = -1;
	char log[1024] = { '\0' };
	glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_shaderProgram, 1024, nullptr, log);
		std::cerr << "Shader Program Failed!\n";
		std::cerr << log << std::endl;
	}
}

std::string Violet::Mesh::loadFileAsString(std::string path) {
	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

