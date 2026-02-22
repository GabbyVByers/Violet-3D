
#include "Window.h"

static void controlCamera(Violet::Camera& camera) {
	const double speed = 0.1;
	static double altitude = 0.0;
	
	if (Violet::Mouse::isImGuiCaptured())
		return;

	if (Violet::Keyboard::pressing(GLFW_KEY_SPACE)) {
		altitude += speed;
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_LEFT_SHIFT)) {
		altitude -= speed;
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_W)) {
		camera.transformation.moveForward(speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_S)) {
		camera.transformation.moveForward(-speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_A)) {
		camera.transformation.moveRight(-speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_D)) {
		camera.transformation.moveRight(speed);
	}

	if (Violet::Mouse::pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Violet::Mouse::cursor(GLFW_CURSOR_DISABLED);
		camera.transformation.pitch(speed * Violet::Mouse::velocity().y * -0.01);
		camera.transformation.rotate(Violet::Vector3d(0.0, 1.0, 0.0), speed * Violet::Mouse::velocity().x * -0.01);
	}
	else {
		Violet::Mouse::cursor(GLFW_CURSOR_NORMAL);
	}

	camera.transformation.position.y = altitude;
}

int main() {
	Violet::Window window(1920, 1080, "My Window");
	Violet::Camera camera;
	Violet::Mesh mesh;

	mesh.cube(1.0, 4);

	while (window.isOpen()) {
		window.clear(Violet::Color(0.1, 0.1, 0.25));
		controlCamera(camera);

		window.draw(camera, mesh);

		Violet::Vector2i size = Violet::Window::getWindowSize();
		ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(255.0f, (float)size.y), ImGuiCond_Always);
		ImGui::Begin(" ", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
		Violet::Vector3d forward = camera.transformation.forward();
		Violet::Vector3d right   = camera.transformation.right();
		Violet::Vector3d up      = camera.transformation.up();
		ImGui::Text(" Camera Position");
		ImGui::Text("  X: %.4f", camera.transformation.position.x);
		ImGui::Text("  Y: %.4f", camera.transformation.position.y);
		ImGui::Text("  Z: %.4f", camera.transformation.position.z);
		ImGui::Text(" ");
		ImGui::Text(" Camera Forward");
		ImGui::Text("  X: %.4f", forward.x);
		ImGui::Text("  Y: %.4f", forward.y);
		ImGui::Text("  Z: %.4f", forward.z);
		ImGui::Text(" ");
		ImGui::Text(" Camera Right");
		ImGui::Text("  X: %.4f", right.x);
		ImGui::Text("  Y: %.4f", right.y);
		ImGui::Text("  Z: %.4f", right.z);
		ImGui::Text(" ");
		ImGui::Text(" Camera Up");
		ImGui::Text("  X: %.4f", up.x);
		ImGui::Text("  Y: %.4f", up.y);
		ImGui::Text("  Z: %.4f", up.z);
		ImGui::End();

		window.display();
	}

	return 0;
}

