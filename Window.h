
#pragma once

#include "Core.h"
#include "Error.h"
#include "Vec3.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"
#include "Keyboard.h"

class Window {
public:
	// Utilities
	static void start(size_t width, size_t height, std::string title);
	static void terminate();
	static bool isOpen();
	static void setVerticalSyncEnable(bool vsync);
	static GLFWwindow* getGlfwWindowPtr();
	
	// Rendering
	static void clear(const Color& color = { 0.0f, 0.0f, 0.0f, 1.0f });
	static void draw(Camera& camera, Mesh& mesh);
	static void display();

private:
	//Callback
	static void framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	
	inline static GLFWwindow* glfwWindow = nullptr;
	inline static size_t instanceCount = 0;
};

