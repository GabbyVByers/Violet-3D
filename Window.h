
#pragma once

#include "Core.h"
#include "Error.h"
#include "Vector.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"

class Window {
public:
	// Constructor
	Window(size_t width, size_t height, std::string title);
	~Window();

	// Draw
	void draw(Camera& camera, Mesh& mesh);

	// Member
	bool isOpen();
	void setVerticalSyncEnable(bool vsync);
	void clear(const Color& color = { 0.0f, 0.0f, 0.0f, 1.0f });
	void display();
	GLFWwindow* getGlfwWindowPtr();

private:
	//Callback
	static void framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	
	GLFWwindow* glfwWindow = nullptr;
	inline static size_t instanceCount = 0;
};

