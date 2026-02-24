
#include "Mesh.h"

Violet::Mesh::Mesh(std::string path, int primativeType) {
	m_primativeType = primativeType;
	glGenVertexArrays(1, &m_VAO);
	glGenBuffers(1, &m_VBO);

	glBindVertexArray(m_VAO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	std::string vertSource = loadFileAsString(path + ".vert");
	std::string fragSource = loadFileAsString(path + ".frag");
	const char* vertCStr = vertSource.c_str();
	const char* fragCStr = fragSource.c_str();

	uint vertProgram = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertProgram, 1, &vertCStr, nullptr);
	glCompileShader(vertProgram);
	assertVertexShader(vertProgram);

	uint fragProgram = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragProgram, 1, &fragCStr, nullptr);
	glCompileShader(fragProgram);
	assertFragmentShader(fragProgram);

	m_shaderProgram = glCreateProgram();
	glAttachShader(m_shaderProgram, vertProgram);
	glAttachShader(m_shaderProgram, fragProgram);
	glLinkProgram(m_shaderProgram);
	glDeleteShader(vertProgram);
	glDeleteShader(fragProgram);
	assertShaderProgram();

	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Violet::Mesh::~Mesh() {
	glDeleteProgram(m_shaderProgram);
	glDeleteBuffers(1, &m_VBO);
	glDeleteVertexArrays(1, &m_VAO);
}

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

