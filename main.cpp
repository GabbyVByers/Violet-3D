
#include "Window.h"

static void controlCamera(Violet::Camera& camera) {
	if (Violet::Mouse::isImGuiCaptured())
		return;


	const double speed = 0.1;

	if (Violet::Keyboard::pressing(GLFW_KEY_SPACE)) {
		camera.move(Violet::Vector3d(0.0, 1.0, 0.0) * speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_LEFT_SHIFT)) {
		camera.move(Violet::Vector3d(0.0,-1.0, 0.0) * speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_W)) {
		camera.moveForward(speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_S)) {
		camera.moveForward(-speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_A)) {
		camera.moveRight(-speed);
	}
	if (Violet::Keyboard::pressing(GLFW_KEY_D)) {
		camera.moveRight(speed);
	}

	if (Violet::Mouse::pressing(GLFW_MOUSE_BUTTON_LEFT)) {
		Violet::Mouse::cursor(GLFW_CURSOR_DISABLED);
		camera.pitch(speed * Violet::Mouse::getVelocity().y * -0.01);
		camera.rotate(Violet::Vector3d(0.0, 1.0, 0.0), speed * Violet::Mouse::getVelocity().x * -0.01);
	}
	else {
		Violet::Mouse::cursor(GLFW_CURSOR_NORMAL);
	}


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

		if (Violet::Mouse::pressing(GLFW_MOUSE_BUTTON_RIGHT)) {
			std::cout << "Right Held\n";
		}
		if (Violet::Mouse::clicked(GLFW_MOUSE_BUTTON_LEFT, GLFW_PRESS)) {
			std::cout << "Left Press\n";
		}
		if (Violet::Mouse::clicked(GLFW_MOUSE_BUTTON_LEFT, GLFW_RELEASE)) {
			std::cout << "Left Release\n";
		}

		window.display();
	}

	return 0;
}

