
#include "Window.h"

int main() {
	Window window(1920, 1080, "My Window");
	window.setVerticalSyncEnable(true);

	Camera camera;
	Mesh mesh;

	mesh.setPrimative(GL_TRIANGLES);
	mesh.addVertex({ float3( 1.0f, 5.0f, 1.0f), Color(0.0f, 1.0f, 1.0f, 1.0f) });
	mesh.addVertex({ float3(-1.0f, 5.0f, 1.0f), Color(1.0f, 0.0f, 1.0f, 1.0f) });
	mesh.addVertex({ float3( 0.0f, 5.0f,-1.0f), Color(1.0f, 1.0f, 0.0f, 1.0f) });

	while (window.isOpen()) {
		window.clear(Color(0.1, 0.1, 0.25));
		window.draw(camera, mesh);
		
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

