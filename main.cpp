
#include "Core.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Window.h"

/*
	TODO:
	More robust header validation in Mesh_PLY.
	Mesh Tranformation Matrix (Camera Fixed at Origin)
	Actually Render Stuff
*/

int main() {
	Window window(1920, 1080, "My Window");
	Mesh mesh;

	while (window.isOpen()) {
		window.draw(mesh);
	}
	return 0;
}

