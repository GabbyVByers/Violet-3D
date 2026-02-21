
#include "Window.h"

namespace Vi = Violet;

static void controlCamera(Violet::Camera& camera) {
	const double speed = 0.1;
	static double altitude = 0.0;
	Violet::Transformation& cameraTrans = camera.borrowTrans();
	
	if (Violet::Mouse::isImGuiCaptured())
		return;

	if (Violet::Keyboard::pressing(GLFW_KEY_SPACE)) {
		altitude += speed;
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_LEFT_SHIFT)) {
		altitude -= speed;
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_W)) {
		cameraTrans.moveForward(speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_S)) {
		cameraTrans.moveForward(-speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_A)) {
		cameraTrans.moveRight(-speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_D)) {
		cameraTrans.moveRight(speed);
	}

	if (Violet::Mouse::pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Violet::Mouse::cursor(GLFW_CURSOR_DISABLED);
		cameraTrans.pitch(speed * Violet::Mouse::getVelocity().y * -0.01);
		cameraTrans.rotate(Violet::Vector3d(0.0, 1.0, 0.0), speed * Violet::Mouse::getVelocity().x * -0.01);
	}
	else {
		Violet::Mouse::cursor(GLFW_CURSOR_NORMAL);
	}

	cameraTrans.setPosY(altitude);
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
		ImGui::SetNextWindowSize(ImVec2(200.0f, (float)size.y), ImGuiCond_Always);
		ImGui::Begin("Left Panel", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse);
		ImGui::End();

		window.display();
	}

	return 0;
}

