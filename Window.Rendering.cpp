
#include "Window.h"

void Window::clear(const Color& color) {
	if (!glfwWindow)
		error(NULL_WINDOW);

	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Window::draw(Camera& camera, Mesh& mesh) {
	if (!glfwWindow)
		error(NULL_WINDOW);
	if (mesh.getNumVertices() == 0)
		error(MESH_HAS_NO_VERTICES);

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

void Window::display() {
	if (!glfwWindow)
		error(NULL_WINDOW);

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(glfwWindow);
	Keyboard::reset();
	glfwPollEvents();
}

