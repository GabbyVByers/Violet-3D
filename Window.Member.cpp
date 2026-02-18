
#include "Window.h"

bool Window::isOpen() {
	return !glfwWindowShouldClose(glfwWindow);
}

void Window::setVerticalSyncEnable(bool vsync) {
	glfwSwapInterval((int)vsync);
}

void Window::clear(const Color& color) {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Window::display() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(glfwWindow);
	glfwPollEvents();
}

GLFWwindow* Window::getGlfwWindowPtr() {
	return glfwWindow;
}

