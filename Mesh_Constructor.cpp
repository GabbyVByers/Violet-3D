
#include "Mesh.h"

inline static std::string loadFileAsString(std::string path) {
	std::ifstream file(path);
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

Mesh::Mesh(std::string path = "shader") {
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	std::string vertSource = loadFileAsString(path + ".vert");
	std::string fragSource = loadFileAsString(path + ".frag");
	const char* vertCStr = vertSource.c_str();
	const char* fragCStr = fragSource.c_str();

	unsigned int vertProgram = 0;
	unsigned int fragProgram = 0;

	vertProgram = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertProgram, 1, &vertCStr, nullptr);
	glCompileShader(vertProgram);

	fragProgram = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragProgram, 1, &fragCStr, nullptr);
	glCompileShader(fragProgram);

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertProgram);
	glAttachShader(shaderProgram, fragProgram);
	glLinkProgram(shaderProgram);
	glDeleteShader(vertProgram);
	glDeleteShader(fragProgram);

	glEnable(GL_PROGRAM_POINT_SIZE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

Mesh::~Mesh() {
	glDeleteProgram(shaderProgram);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

