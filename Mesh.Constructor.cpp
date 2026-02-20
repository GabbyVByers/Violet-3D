
#include "Mesh.h"

Mesh::Mesh(std::string path, int primType) {
	if (!Window::getGlfwWindowPtr())
		error(NULL_WINDOW);

	primativeType = primType;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	std::string vertSource = this->loadFileAsString(path + ".vert");
	std::string fragSource = this->loadFileAsString(path + ".frag");
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

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertProgram);
	glAttachShader(shaderProgram, fragProgram);
	glLinkProgram(shaderProgram);
	glDeleteShader(vertProgram);
	glDeleteShader(fragProgram);
	assertShaderProgram();

	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Mesh::~Mesh() {
	glDeleteProgram(shaderProgram);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

const void Mesh::assertVertexShader(uint vertProgram) {
	int success = -1;
	char log[1024] = { '\0' };
	glGetShaderiv(vertProgram, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertProgram, 1024, nullptr, log);
		std::cerr << log;
		error(VERTEX_SHADER_FAILED);
	}
}

const void Mesh::assertFragmentShader(uint fragProgram) {
	int success = -1;
	char log[1024] = { '\0' };
	glGetShaderiv(fragProgram, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragProgram, 1024, nullptr, log);
		std::cerr << log;
		error(FRAGMENT_SHADER_FAILED);
	}
}

const void Mesh::assertShaderProgram() {
	int success = -1;
	char log[1024] = { '\0' };
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 1024, nullptr, log);
		std::cerr << log;
		error(SHADER_PROGRAM_FAILED);
	}
}

std::string Mesh::loadFileAsString(std::string path) {
	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

