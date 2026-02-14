
#include "Core.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Window.h"

int main() {
	Window window(1920, 1080, "My Window");
	Mesh mesh;

	while (window.isOpen()) {
		window.draw(mesh);
	}
	return 0;
}

