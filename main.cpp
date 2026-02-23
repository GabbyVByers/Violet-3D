
#include "Window.h"
#include "Map.h"

int main() {
	Vi::Window::construct(1920, 1080, "My Window");
	Keplar::constructSolarSystem();

	while (Vi::Window::isOpen()) {
		Vi::Window::clear(Vi::Color::BLACK());
		Map::controlMapViewCamera();
		Map::render();
		Vi::Window::display();
	}

	Vi::Window::destruct();
	return 0;
}

