
#include "Mesh.h"

void Mesh::setPrimativeType(int GL_PRIMATIVE) {
	this->primativeType = GL_PRIMATIVE;
}

void Mesh::setColor(const Color& color) {
	for (Vertex& vertex : this->vertices) {
		vertex.color = color;
	}
}

void Mesh::setRandomColors() {
	for (Vertex& vertex : this->vertices) {
		vertex.color = Color::Random();
	}
}

void Mesh::addVertex(const Vertex& vertex) {
	this->vertices.push_back(vertex);
}

