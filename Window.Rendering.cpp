
#include "Window.h"

void Violet::Window::clear(Color color) {
	Keyboard::reset();
	Mouse::reset();
	double x, y; glfwGetCursorPos(m_glfwWindow, &x, &y); Mouse::update(x, y);
	glfwPollEvents();

	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Violet::Window::draw(Mesh& mesh, Camera& camera) {
	const uint VAO = mesh.getVAO();
	const uint VBO = mesh.getVBO();
	const uint shaderProgram = mesh.getShaderProgram();
	const std::vector<Vertex>& vertices = mesh.vertices;

	assert(VAO != 0);
	assert(VBO != 0);
	assert(shaderProgram != 0);
	assert(vertices.size() != 0);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glUseProgram(shaderProgram);

	Vector2i size = getWindowSize();
	const Matrix modelMatrix = mesh.calculateModelMatrix();
	const Matrix viewMatrix = camera.calculateViewMatrix();
	const Matrix projectionMatrix = camera.calculateProjectionMatrix(size.x, size.y);

	Matrix modelViewProject = projectionMatrix * viewMatrix * modelMatrix;
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uModelViewProject"), 1, GL_FALSE, modelViewProject.as_float());

	// GL_STATIC_DRAW or GL_DYNAMIC_DRAW ?
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_DYNAMIC_DRAW);
	glDrawArrays(mesh.getPrimativeType(), 0, (GLsizei)vertices.size());
}

void Violet::Window::display() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(m_glfwWindow);
}

