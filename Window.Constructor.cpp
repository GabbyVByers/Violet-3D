
#include "Window.h"

Window::Window(size_t width, size_t height, std::string title) {
	instanceCount++;
	if (instanceCount > 1)
		error(MULTIPLE_WINDOW_INSTANCES);

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindow = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
	if (!glfwWindow)
		error(WINDOW_CREATION_FAILED);
	glfwMakeContextCurrent(glfwWindow);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glEnable(GL_DEPTH_TEST);

	glfwSetFramebufferSizeCallback(glfwWindow, windowResizeCallback);
	glfwSetKeyCallback(glfwWindow, keyboardCallback);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.FontGlobalScale = 2.0f;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	setVerticalSyncEnable(true);
}

Window::~Window() {
	if (!glfwWindow)
		error(NULL_WINDOW);

	instanceCount--;
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(glfwWindow);
	glfwTerminate();
}

bool Window::isOpen() {
	if (!glfwWindow)
		error(NULL_WINDOW);
	return !glfwWindowShouldClose(glfwWindow);
}

void Window::setVerticalSyncEnable(bool vsync) {
	if (!glfwWindow)
		error(NULL_WINDOW);
	glfwSwapInterval((int)vsync);
}

GLFWwindow* Window::getGlfwWindowPtr() {
	if (!glfwWindow)
		error(NULL_WINDOW);
	return glfwWindow;
}

