
#pragma once

#include "Violet.h"
#include "Matrix.h"
#include "Camera.h"
#include "Mesh.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Vector.h"
#include "Shape.h"

class Violet::Window {
public:
	// Window
	static void construct(size_t width, size_t height, std::string title);
	static void destruct();
	static bool isOpen();
	static void vSync(bool vsync);
	static Vector2i getSize();
	static GLFWwindow* getGLFW();
	static void framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	// Rendering
	static void clear(const Color& color = { 0.0f, 0.0f, 0.0f, 1.0f });
	static void draw(Camera& camera, Mesh& mesh);
	static void display();

private:
	Window() = delete;
	~Window() = delete;
	inline static GLFWwindow* glfwWindow = nullptr;
};

