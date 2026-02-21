
#include "Window.h"

void Violet::Window::clear(const Color& color) {
	if (!glfwWindow)
		error(NULL_WINDOW);

	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Violet::Window::draw(Camera& camera, Mesh& mesh) {
	if (!glfwWindow)
		error(NULL_WINDOW);
	if (mesh.getNumVertices() == 0)
		error(MESH_HAS_NO_VERTICES);

	const uint VAO = mesh.getVAO();
	const uint VBO = mesh.getVBO();
	const uint shaderProgram = mesh.getShaderProgram();
	const std::vector<Vertex>& vertices = mesh.getVertices();

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glUseProgram(shaderProgram);

	int width, height; glfwGetFramebufferSize(glfwWindow, &width, &height); // TODO REFACTOR TO USE NEW FUNCTION
	const Matrix modelMatrix = mesh.getModelMatrix();
	const Matrix viewMatrix = camera.getViewMatrix();
	const Matrix projectionMatrix = camera.getProjectionMatrix(width, height);

	Matrix modelViewProject = projectionMatrix * viewMatrix * modelMatrix;
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uModelViewProject"), 1, GL_FALSE, modelViewProject.as_float());

	// GL_STATIC_DRAW or GL_DYNAMIC_DRAW ?
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glDrawArrays(mesh.getPrimativeType(), 0, (GLsizei)vertices.size());
}

void Violet::Window::display() {
	if (!glfwWindow)
		error(NULL_WINDOW);

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(glfwWindow);

	Keyboard::reset();
	Mouse::reset();
	double x, y;
	glfwGetCursorPos(glfwWindow, &x, &y);
	Mouse::update(x, y);
	glfwPollEvents();
}

