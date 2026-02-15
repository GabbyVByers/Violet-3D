
#include "Camera.h"

struct float3 {
	float x;
	float y;
	float z;

	float3(float x = 0.0f,
		   float y = 0.0f,
		   float z = 0.0f) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

class Color {
public:
	float r;
	float g;
	float b;
	float a;

	Color(float r = 1.0f,
		  float g = 1.0f,
		  float b = 1.0f,
		  float a = 1.0f) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}
};

struct Vertex {
	float3 pos;
	Color color;
};

class Mesh {
public:

	Mesh(std::string path = "default") {
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		std::string vertSource = loadFileAsString(path + ".vert");
		std::string fragSource = loadFileAsString(path + ".frag");
		const char* vertCStr = vertSource.c_str();
		const char* fragCStr = fragSource.c_str();

		unsigned int vertProgram = 0;
		unsigned int fragProgram = 0;

		vertProgram = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertProgram, 1, &vertCStr, nullptr);
		glCompileShader(vertProgram);
		assertVertexShader(vertProgram);

		fragProgram = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragProgram, 1, &fragCStr, nullptr);
		glCompileShader(fragProgram);
		assertFragmentShader(fragProgram);

		shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertProgram);
		glAttachShader(shaderProgram, fragProgram);
		glLinkProgram(shaderProgram);
		glDeleteShader(vertProgram);
		glDeleteShader(fragProgram);
		assertShaderProgram();

		glEnable(GL_PROGRAM_POINT_SIZE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	const void assertVertexShader(int vertProgram) {
		int success = -1;
		char log[1024] = { '\0' };
		glGetShaderiv(vertProgram, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(vertProgram, 1024, nullptr, log);
			std::cerr << "Vertex shader compilation failed:\n" << log << std::endl;
		}
	}

	const void assertFragmentShader(unsigned int fragProgram) {
		int success = -1;
		char log[1024] = { '\0' };
		glGetShaderiv(fragProgram, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragProgram, 1024, nullptr, log);
			std::cerr << "Fragment shader compilation failed:\n" << log << std::endl;
		}
	}

	const void assertShaderProgram() {
		int success = -1;
		char log[1024] = { '\0' };
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 1024, nullptr, log);
			std::cerr << "Shader program linking failed:\n" << log << std::endl;
		}
	}

	~Mesh() {
		glDeleteProgram(shaderProgram);
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &VAO);
	}

	void addVertex(const Vertex& vertex) {
		vertices.push_back(vertex);
	}

	const unsigned int& getShaderProgram() {
		return shaderProgram;
	}

	const unsigned int& getVAO() {
		return VAO;
	}

	const unsigned int& getVBO() {
		return VBO;
	}

	std::vector<Vertex>& getVertices() {
		return vertices;
	}

private:
	unsigned int shaderProgram = 0;
	unsigned int VAO = 0, VBO = 0;
	std::vector<Vertex> vertices;

	inline static std::string loadFileAsString(std::string path) {
		std::ifstream file(path);
		std::stringstream buffer;
		buffer << file.rdbuf();
		return buffer.str();
	}
};

class Window {
public:

	Window(size_t width, size_t height, std::string title) {
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		this->camera = Camera();
		glfwWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(glfwWindow);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glViewport(0, 0, width, height);

		glfwSetFramebufferSizeCallback(glfwWindow, framebufferSizeCallback);
		glfwSetKeyCallback(glfwWindow, keyCallback);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.FontGlobalScale = 1.0f;
		ImGui::StyleColorsDark();
		ImGui_ImplGlfw_InitForOpenGL(glfwWindow, true);
		ImGui_ImplOpenGL3_Init("#version 330");
	}

	void draw(Mesh& mesh) {
		const unsigned int& shaderProgram = mesh.getShaderProgram();
		const unsigned int& VAO = mesh.getVAO();
		const unsigned int& VBO = mesh.getVBO();
		const std::vector<Vertex>& vertices = mesh.getVertices();

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glUseProgram(shaderProgram);
		
		const float transform[16] = {
			1, 0, 0, 0,
			0, 1, 0, 0,
			0, 0, 1, 0,
			0, 0, 0, 1
		};

		const float view[16] = {
			1,  0,  0,  0,
			0,  0, -1,  0,
			0,  1,  0,  0,
			0,  0,  0,  1
		};

		int width, height; glfwGetFramebufferSize(glfwWindow, &width, &height);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uTransform"), 1, GL_FALSE, transform);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uView"), 1, GL_FALSE, view);
		glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "uProject"), 1, GL_FALSE, camera.getProjection(width, height));

		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
		glDrawArrays(GL_TRIANGLES, 0, (GLsizei)vertices.size());
	}

	bool isOpen() {
		return !glfwWindowShouldClose(glfwWindow);
	}

	void setVSYNC(bool vsync) {
		glfwSwapInterval((int)vsync);
	}

	void clear(const Color& color = { 0.0f, 0.0f, 0.0f, 0.0f }) {
		glClearColor(color.r, color.g, color.b, color.a);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void display() {
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		glfwSwapBuffers(glfwWindow);
		glfwPollEvents();
	}

private:
	Camera camera;
	GLFWwindow* glfwWindow = nullptr;

	static void framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
		glViewport(0, 0, width, height);
	}

	static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
			glfwSetWindowShouldClose(window, true);
		}
	}
};

int main() {
	Window window(1920, 1080, "My Window");
	Mesh mesh;

	mesh.addVertex({ float3( 1.0f, 5.0f, 1.0f), Color(0.0f, 1.0f, 1.0f, 1.0f) });
	mesh.addVertex({ float3(-1.0f, 5.0f, 1.0f), Color(1.0f, 0.0f, 1.0f, 1.0f) });
	mesh.addVertex({ float3( 0.0f, 5.0f,-1.0f), Color(1.0f, 1.0f, 0.0f, 1.0f) });

	while (window.isOpen()) {
		window.clear(Color(0.1, 0.1, 0.25));
		window.draw(mesh);
		
		ImGui::Begin("Triangle");
		ImGui::DragFloat3("Vertex 1", (float*)&mesh.getVertices()[0].pos, 0.001);
		ImGui::DragFloat3("Vertex 2", (float*)&mesh.getVertices()[1].pos, 0.001);
		ImGui::DragFloat3("Vertex 3", (float*)&mesh.getVertices()[2].pos, 0.001);
		ImGui::End();

		ImGui::Begin("Second Window Test");
		ImGui::Text("Test Text");
		ImGui::End();

		window.display();
	}
	return 0;
}

