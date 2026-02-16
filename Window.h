
#pragma once

#include "Core.h"
#include "Algebra.h"
#include "Camera.h"
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
		glfwSetKeyCallback(glfwWindow, keyCallback);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.FontGlobalScale = 2.0f;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}

	void draw(Camera& camera, Mesh& mesh) {
		const unsigned int& shaderProgram = mesh.getShaderProgram();
		const unsigned int& VAO = mesh.getVAO();
		const unsigned int& VBO = mesh.getVBO();
		const std::vector<Vertex>& vertices = mesh.getVertices();

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glUseProgram(shaderProgram);

		const float transform[16] = {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float view[16] = {
			1, 0, 0, 0,
			0, 0,-1, 0,
			0, 1, 0, 0,
			0, 0, 0, 1
		};

		int width, height; glfwGetFramebufferSize(glfwWindow, &width, &height);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uTransform"), 1, GL_FALSE, transform);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uView"), 1, GL_FALSE, view);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uProject"), 1, GL_FALSE, camera.getProjection(width, height));

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
		glDrawArrays(mesh.getPrimative(), 0, (GLsizei)vertices.size());
	}

	bool isOpen() {
		return !glfwWindowShouldClose(glfwWindow);
	}

	void setVerticalSyncEnable(bool vsync) {
		glfwSwapInterval((int)vsync);
	}

	void clear(const Color& color = { 0.0f, 0.0f, 0.0f, 0.0f }) {
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void display() {
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(glfwWindow);
		glfwPollEvents();
	}

private:
	GLFWwindow* glfwWindow = nullptr;

	static void framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
		glViewport(0, 0, width, height);
	}

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}
};

