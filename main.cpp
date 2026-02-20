
#include "Window.h"

static void controlCamera(Camera& camera) {
	const double speed = 0.1;

	if (Keyboard::pressing(GLFW_KEY_SPACE)) {
		camera.move(double3(0.0, 1.0, 0.0) * speed);
	}
	if (Keyboard::pressing(GLFW_KEY_LEFT_SHIFT)) {
		camera.move(double3(0.0,-1.0, 0.0) * speed);
	}
	if (Keyboard::pressing(GLFW_KEY_W)) {
		camera.moveForward(speed);
	}
	if (Keyboard::pressing(GLFW_KEY_S)) {
		camera.moveForward(-speed);
	}
	if (Keyboard::pressing(GLFW_KEY_A)) {
		camera.moveRight(-speed);
	}
	if (Keyboard::pressing(GLFW_KEY_D)) {
		camera.moveRight(speed);
	}

	if (Mouse::pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		camera.pitch(speed * Mouse::getVelocity().y * 0.01);
		camera.yaw(speed * Mouse::getVelocity().x * -0.01);
	}
}

int main() {
	Window window(1920, 1080, "My Window");
	Camera camera;
	Mesh mesh;

	mesh.cube(1.0, 4);

	while (window.isOpen()) {
		window.clear(Color(0.1, 0.1, 0.25));

		controlCamera(camera);

		window.draw(camera, mesh);

		if (Mouse::pressing(GLFW_MOUSE_BUTTON_RIGHT)) {
			std::cout << "Right Held\n";
		}
		if (Mouse::clicked(GLFW_MOUSE_BUTTON_LEFT, GLFW_PRESS)) {
			std::cout << "Left Press\n";
		}
		if (Mouse::clicked(GLFW_MOUSE_BUTTON_LEFT, GLFW_RELEASE)) {
			std::cout << "Left Release\n";
		}

		mesh.rotate(double3(0, 1, 0), 0.03);
		
		ImGui::Begin("Triangle");
		ImGui::End();

		ImGui::Begin("Second Window Test");
		ImGui::Text("Test Text");
		ImGui::End();

		window.display();
	}

	return 0;
}

