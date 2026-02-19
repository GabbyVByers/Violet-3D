
#include "Window.h"

int main() {
	Window window(1920, 1080, "My Window");
	Keyboard keyboard;
	Camera camera;
	Mesh mesh;

	mesh.cube(1.0, 10);
	//mesh.setColor(Color::RED());

	while (window.isOpen()) {
		window.clear(Color(0.1, 0.1, 0.25));
		window.draw(camera, mesh);

		if (keyboard.press(GLFW_KEY_P))             { mesh.scale(1.1); }
		if (keyboard.press(GLFW_KEY_L))             { mesh.scale(0.9); }
		if (keyboard.press(GLFW_KEY_W))             { mesh.translate({ 0.0, 0.0,-0.1 }); }
		if (keyboard.press(GLFW_KEY_S))             { mesh.translate({ 0.0, 0.0, 0.1 }); }
		if (keyboard.press(GLFW_KEY_A))             { mesh.translate({-0.1, 0.0, 0.0 }); }
		if (keyboard.press(GLFW_KEY_D))             { mesh.translate({ 0.1, 0.0, 0.0 }); }
		if (keyboard.press(GLFW_KEY_LEFT_SHIFT))    { mesh.translate({ 0.0, 0.1, 0.0 }); }
		if (keyboard.press(GLFW_KEY_LEFT_CONTROL))  { mesh.translate({ 0.0,-0.1, 0.0 }); }
		if (keyboard.press(GLFW_KEY_Z))             { mesh.resetPosition(); }
		if (keyboard.press(GLFW_KEY_Q))             { mesh.rotate({0, 0, 1}, 0.05); }
		if (keyboard.press(GLFW_KEY_E))             { mesh.rotate({0, 0, 1},-0.05); }
		if (keyboard.press(GLFW_KEY_X))             { mesh.resetOrientation(); }
		if (keyboard.press(GLFW_KEY_T, GLFW_PRESS)) { std::cout << "Haii!!\n"; }

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

