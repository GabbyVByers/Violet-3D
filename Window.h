
#pragma once

#include "Core.h"
#include "Error.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"
#include "Keyboard.h"

class Window {
public:
	// Constructor
	Window(size_t width, size_t height, std::string title);
	~Window();

	// Utilities
	bool isOpen();
	void setVerticalSyncEnable(bool vsync);
	static GLFWwindow* getGlfwWindowPtr();
	
	// Rendering
	void clear(const Color& color = { 0.0f, 0.0f, 0.0f, 1.0f });
	void draw(Camera& camera, Mesh& mesh);
	void display();

private:
	//Callback
	static void windowResizeCallback(GLFWwindow* glfwWindow, int width, int height);
	static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	
	inline static GLFWwindow* glfwWindow = nullptr;
	inline static size_t instanceCount = 0;
};

