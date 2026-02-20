
#include "Mesh.h"

void Mesh::setPrimativeType(int GL_PRIMATIVE) {
	primativeType = GL_PRIMATIVE;
}

void Mesh::setColor(const Color& color) {
	for (Vertex& vertex : vertices) {
		vertex.color = color;
	}
}

void Mesh::setRandomColors() {
	for (Vertex& vertex : vertices) {
		vertex.color = Color::Random();
	}
}

void Mesh::addVertex(const Vertex& vertex) {
	vertices.push_back(vertex);
}

