
#include "Shape.h"

void Violet::Shape::sphere(Mesh& mesh, double radius, uint subdivisions) {
	mesh.getVertices().clear();
	std::vector<Vector3d> cubePoints = precisionCube(1.0, subdivisions);
	for (Vector3d point : cubePoints) {
		point.normalize();
		point = point * radius;
		mesh.getVertices().push_back({ point.as_float(), Color::Random() });
	}
}

void Violet::Shape::cube(Mesh& mesh, double radius, uint subdivisions) {
	mesh.getVertices().clear();
	std::vector<Vector3d> cubePoints = precisionCube(radius, subdivisions);
	for (const Vector3d& point : cubePoints) {
		mesh.getVertices().push_back({ point.as_float(), Color::Random() });
	}
}

