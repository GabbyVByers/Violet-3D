
#include "Window.h"

#define Vi Violet

static void controlCamera(Vi::Camera& camera) {
	// todo: scale with framerate, implement Violet::Window::getFPS() and Violet::Window::getSPF()
	const double sensitivity = 0.1;

	if (Vi::Mouse::pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Vi::Vector2d mouseVelocity = Vi::Mouse::velocity();
		camera.transformation.pitch(sensitivity * mouseVelocity.y * -0.01);
		camera.transformation.rotate(Vi::Vector3d(0.0, 1.0, 0.0), sensitivity * mouseVelocity.x * -0.01);
	}

	Vi::Vector3d forward = camera.transformation.forward();
	Vi::Vector3d& position = camera.transformation.position;
	position = forward * -1.0;
}

int main() {
	Vi::Window::construct(1920, 1080, "My Window");
	
	Vi::Camera camera;
	Vi::Mesh mesh;
	Vi::Shape::sphere(mesh, 0.35, 40);

	while (Vi::Window::isOpen()) {
		Vi::Window::clear(Vi::Color(0.1, 0.1, 0.25));
		controlCamera(camera);

		Vi::Window::draw(camera, mesh);

		Vi::Vector2i size = Vi::Window::getSize();
		ImGui::SetNextWindowPos(ImVec2(0.0f, 0.0f), ImGuiCond_Always);
		ImGui::SetNextWindowSize(ImVec2(255.0f, (float)size.y), ImGuiCond_Always);
		ImGui::Begin(" ", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
		Vi::Vector3d forward = camera.transformation.forward();
		Vi::Vector3d right = camera.transformation.right();
		Vi::Vector3d up      = camera.transformation.up();
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

		Vi::Window::display();
	}

	Vi::Window::destruct();
	return 0;
}

