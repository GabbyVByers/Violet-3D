
#include "Window.h"

void Violet::Window::construct(size_t width, size_t height, std::string title) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_glfwWindow = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(m_glfwWindow);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glEnable(GL_DEPTH_TEST);

	glfwSetFramebufferSizeCallback(m_glfwWindow, framebufferSizeCallback);
	glfwSetKeyCallback(m_glfwWindow, keyCallback);
	glfwSetMouseButtonCallback(m_glfwWindow, mouseButtonCallback);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.FontGlobalScale = 2.0f;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(m_glfwWindow, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	vSync(true);
}

void Violet::Window::destruct() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(m_glfwWindow);
	glfwTerminate();
}

