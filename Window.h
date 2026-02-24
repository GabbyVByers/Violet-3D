
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
	// Window.Lifetime.cpp
	static void construct(size_t width, size_t height, std::string title);
	static void destruct();

	// Window.Utilities.cpp
	static bool isOpen();
	static void vSync(bool vsync);
	static Vector2i getSize();
	static GLFWwindow* getGLFW();
	static void framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height);
	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	// Window.Rendering.cpp
	static void clear(Color color = { 0.0f, 0.0f, 0.0f, 1.0f });
	static void draw(Mesh& mesh, Camera& camera);
	static void display();

private:
	Window() = delete;
	~Window() = delete;
	inline static GLFWwindow* m_glfwWindow = nullptr;
};

