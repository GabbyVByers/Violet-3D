
#pragma once

#include "Violet.h"
#include "Error.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Vector.h"

class Violet::Window {
public:
	// Constructor
	Window(size_t width, size_t height, std::string title);
	~Window();
	bool isOpen();
	void setVerticalSyncEnable(bool vsync);
	static Vector2i getWindowSize();
	static GLFWwindow* getGlfwWindowPtr();

	// Rendering
	void clear(const Color& color = { 0.0f, 0.0f, 0.0f, 1.0f });
	void draw(Camera& camera, Mesh& mesh);
	void display();

private:
	// Callback
	static void framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	inline static GLFWwindow* glfwWindow = nullptr;
	inline static size_t instanceCount = 0;
};

