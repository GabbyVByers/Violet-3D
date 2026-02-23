
#include "Window.h"

// CONSTRUCTORS

void Violet::Window::construct(size_t width, size_t height, std::string title) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindow = glfwCreateWindow((int)width, (int)height, title.c_str(), nullptr, nullptr);
	glfwMakeContextCurrent(glfwWindow);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glEnable(GL_DEPTH_TEST);

	glfwSetFramebufferSizeCallback(glfwWindow, framebufferSizeCallback);
	glfwSetKeyCallback(glfwWindow, keyCallback);
	glfwSetMouseButtonCallback(glfwWindow, mouseButtonCallback);

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.FontGlobalScale = 2.0f;
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	vSync(true);
}

void Violet::Window::destruct() {
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
	glfwDestroyWindow(glfwWindow);
	glfwTerminate();
}

// INTERFACE

bool Violet::Window::isOpen() {
	return !glfwWindowShouldClose(glfwWindow);
}

void Violet::Window::vSync(bool vsync) {
	glfwSwapInterval((int)vsync);
}

Violet::Vector2i Violet::Window::getSize() {
	int width, height; glfwGetFramebufferSize(glfwWindow, &width, &height);
	return {
		width,
		height
	};
}

GLFWwindow* Violet::Window::getGLFW() {
	return glfwWindow;
}

void Violet::Window::framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
	glViewport(0, 0, width, height);
}

void Violet::Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	gl_keyEvent keyEvent = {
		window,
		key,
		scancode,
		action,
		mods
	};
	Keyboard::addKeyEvent(keyEvent);
}

void Violet::Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	gl_mouseEvent mouseEvent = {
		window,
		button,
		action,
		mods
	};
	Mouse::addMouseEvent(mouseEvent);
}

// RENDERING

void Violet::Window::clear(const Color& color) {
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Violet::Window::draw(Mesh& mesh, Camera& camera) {
	if (mesh.vertices.size() == 0)
		return;

	const uint VAO = mesh.VAO;
	const uint VBO = mesh.VBO;
	const uint shaderProgram = mesh.shaderProgram;
	const std::vector<Vertex>& vertices = mesh.vertices;

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glUseProgram(shaderProgram);

	Vector2i size = getSize();
	const Matrix modelMatrix = mesh.getModelMatrix();
	const Matrix viewMatrix = camera.getViewMatrix();
	const Matrix projectionMatrix = camera.getProjectionMatrix(size.x, size.y);

	Matrix modelViewProject = projectionMatrix * viewMatrix * modelMatrix;
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uModelViewProject"), 1, GL_FALSE, modelViewProject.as_float());

	// GL_STATIC_DRAW or GL_DYNAMIC_DRAW ?
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_DYNAMIC_DRAW);
	glDrawArrays(mesh.primativeType, 0, (GLsizei)vertices.size());
}

void Violet::Window::display() {
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	glfwSwapBuffers(glfwWindow);

	Keyboard::reset();
	Mouse::reset();
	double x, y;
	glfwGetCursorPos(glfwWindow, &x, &y);
	Mouse::update(x, y);
	glfwPollEvents();
}

