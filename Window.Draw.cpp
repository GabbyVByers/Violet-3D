
#include "Window.h"

void Window::draw(Camera& camera, Mesh& mesh) {
	const uint& VAO = mesh.getVAO();
	const uint& VBO = mesh.getVBO();
	const uint& shaderProgram = mesh.getShaderProgram();
	const std::vector<Vertex>& vertices = mesh.getVertices();

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glUseProgram(shaderProgram);

	int width, height; glfwGetFramebufferSize(glfwWindow, &width, &height);
	const double4x4& modelMatrix = mesh.getModelMatrix();
	const double4x4& viewMatrix = camera.getViewMatrix();
	const double4x4& projectionMatrix = camera.getProjectionMatrix(width, height);

	double4x4 modelViewProject = projectionMatrix * viewMatrix * modelMatrix;
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uModelViewProject"), 1, GL_FALSE, modelViewProject.as_float());

	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glDrawArrays(mesh.getPrimative(), 0, (GLsizei)vertices.size());
}

