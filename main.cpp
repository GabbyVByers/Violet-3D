
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
		camera.yaw(speed * Mouse::getVelocity().x * 0.01);
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

		//if (Keyboard::press(GLFW_KEY_P))             { mesh.scale(1.1); }
		//if (Keyboard::press(GLFW_KEY_L))             { mesh.scale(0.9); }
		//if (Keyboard::press(GLFW_KEY_W))             { mesh.move({ 0.0, 0.0,-0.1 }); }
		//if (Keyboard::press(GLFW_KEY_S))             { mesh.move({ 0.0, 0.0, 0.1 }); }
		//if (Keyboard::press(GLFW_KEY_A))             { mesh.move({-0.1, 0.0, 0.0 }); }
		//if (Keyboard::press(GLFW_KEY_D))             { mesh.move({ 0.1, 0.0, 0.0 }); }
		//if (Keyboard::press(GLFW_KEY_LEFT_SHIFT))    { mesh.move({ 0.0, 0.1, 0.0 }); }
		//if (Keyboard::press(GLFW_KEY_LEFT_CONTROL))  { mesh.move({ 0.0,-0.1, 0.0 }); }
		//if (Keyboard::press(GLFW_KEY_Z))             { mesh.setPosition({0.0, 0.0, 0.0}); }
		//if (Keyboard::press(GLFW_KEY_Q))             { mesh.rotate({0, 0, 1}, 0.05); }
		//if (Keyboard::press(GLFW_KEY_E))             { mesh.rotate({0, 0, 1},-0.05); }
		//if (Keyboard::press(GLFW_KEY_X))             { mesh.resetOrientation(); }
		//if (Keyboard::press(GLFW_KEY_T, GLFW_PRESS)) { std::cout << "Haii!!\n"; }

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
		//ImGui::DragFloat3("Vertex 1", (float*)&mesh.getVertices()[0].position, 0.02);
		//ImGui::DragFloat3("Vertex 2", (float*)&mesh.getVertices()[1].position, 0.02);
		//ImGui::DragFloat3("Vertex 3", (float*)&mesh.getVertices()[2].position, 0.02);
		ImGui::End();

		ImGui::Begin("Second Window Test");
		ImGui::Text("Test Text");
		ImGui::End();

		window.display();
	}

	return 0;
}

