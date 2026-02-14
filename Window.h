#pragma once

#include "Core.h"
#include "Vertex.h"
#include "Mesh.h"

class Window {
public:

	Window(size_t width, size_t height, std::string title) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(glfwWindow);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glViewport(0, 0, width, height);
		glfwSetFramebufferSizeCallback(glfwWindow, framebufferSizeCallback);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.FontGlobalScale = 1.0f;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}

	void draw(Mesh& mesh) {
		unsigned int& shaderProgram = mesh.getShaderProgram();
		unsigned int& VAO = mesh.getVAO();
		unsigned int& VBO = mesh.getVBO();
		std::vector<Vertex>& vertices = mesh.getVertices();

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glUseProgram(shaderProgram);

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
		glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertices.size());
	}

	bool isOpen() {
		return true;
	}

private:

	GLFWwindow* glfwWindow = nullptr;

	inline static void framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
		glViewport(0, 0, width, height);
	}
};

