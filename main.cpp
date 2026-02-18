
#include "Window.h"

Color randColor() {
	return {
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		(float)rand() / (float)RAND_MAX,
		1.0
	};
}

void makeCube(Mesh& mesh) {
	
}

int main() {
	Window window(1920, 1080, "My Window");
	Keyboard keyboard;

	Camera camera;
	Mesh mesh;

	mesh.setPrimative(GL_TRIANGLES);
	mesh.addVertex(Vertex(float3( 1.0f, 1.0f, 0.0f), Color(1.0f, 0.0f, 0.0f, 1.0f)));
	mesh.addVertex(Vertex(float3(-1.0f, 1.0f, 0.0f), Color(0.0f, 1.0f, 0.0f, 1.0f)));
	mesh.addVertex(Vertex(float3( 0.0f,-1.0f, 0.0f), Color(0.0f, 0.0f, 1.0f, 1.0f)));

	mesh.translate({ 0.0, 0.0, -10.0 });

	Mesh axies;
	axies.setPrimative(GL_LINES);
	axies.addVertex(Vertex(float3(-FLT_MAX, 0.0f, 0.0f), Color(1.0f, 0.0f, 0.0f)));
	axies.addVertex(Vertex(float3( FLT_MAX, 0.0f, 0.0f), Color(1.0f, 0.0f, 0.0f)));
	axies.addVertex(Vertex(float3( 0.0f,-FLT_MAX, 0.0f), Color(0.0f, 1.0f, 0.0f)));
	axies.addVertex(Vertex(float3( 0.0f, FLT_MAX, 0.0f), Color(0.0f, 1.0f, 0.0f)));
	axies.addVertex(Vertex(float3( 0.0f, 0.0f,-FLT_MAX), Color(0.0f, 0.0f, 1.0f)));
	axies.addVertex(Vertex(float3( 0.0f, 0.0f, FLT_MAX), Color(0.0f, 0.0f, 1.0f)));

	while (window.isOpen()) {
		window.clear(Color(0.1, 0.1, 0.25));
		window.draw(camera, mesh);
		window.draw(camera, axies);

		if (keyboard.keyPressed(GLFW_KEY_P)) { mesh.scale(1.1); }
		if (keyboard.keyPressed(GLFW_KEY_L)) { mesh.scale(0.9); }
		if (keyboard.keyPressed(GLFW_KEY_W))            { mesh.translate({ 0.0, 0.0,-0.1 }); }
		if (keyboard.keyPressed(GLFW_KEY_S))            { mesh.translate({ 0.0, 0.0, 0.1 }); }
		if (keyboard.keyPressed(GLFW_KEY_A))            { mesh.translate({-0.1, 0.0, 0.0 }); }
		if (keyboard.keyPressed(GLFW_KEY_D))            { mesh.translate({ 0.1, 0.0, 0.0 }); }
		if (keyboard.keyPressed(GLFW_KEY_LEFT_SHIFT))   { mesh.translate({ 0.0, 0.1, 0.0 }); }
		if (keyboard.keyPressed(GLFW_KEY_LEFT_CONTROL)) { mesh.translate({ 0.0,-0.1, 0.0 }); }
		if (keyboard.keyPressed(GLFW_KEY_Z)) { mesh.resetPosition(); }
		if (keyboard.keyPressed(GLFW_KEY_Q)) { mesh.rotate({0, 0, 1}, 0.05); }
		if (keyboard.keyPressed(GLFW_KEY_E)) { mesh.rotate({0, 0, 1},-0.05); }
		if (keyboard.keyPressed(GLFW_KEY_X)) { mesh.resetOrientation(); }
		if (keyboard.keyPressedEvent(GLFW_KEY_T, GLFW_RELEASE)) {
			std::cout << "Haii!!\n";
		}

		mesh.rotate(double3(0, 1, 0), 0.03);
		
		ImGui::Begin("Triangle");
		ImGui::DragFloat3("Vertex 1", (float*)&mesh.getVertices()[0].position, 0.02);
		ImGui::DragFloat3("Vertex 2", (float*)&mesh.getVertices()[1].position, 0.02);
		ImGui::DragFloat3("Vertex 3", (float*)&mesh.getVertices()[2].position, 0.02);
		ImGui::End();

		ImGui::Begin("Second Window Test");
		ImGui::Text("Test Text");
		ImGui::End();

		window.display();
	}

	return 0;
}

