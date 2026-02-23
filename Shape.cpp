
#include "Shape.h"

void Violet::Shape::sphere(Mesh& mesh, double radius, uint subdivisions) {
	mesh.vertices.clear();
	std::vector<Vector3d> cubePoints = precisionCube(1.0, subdivisions);
	for (Vector3d point : cubePoints) {
		point.normalize();
		point = point * radius;
		mesh.vertices.push_back({ point.as_float(), Color::Random() });
	}
}

void Violet::Shape::cube(Mesh& mesh, double radius, uint subdivisions) {
	mesh.vertices.clear();
	std::vector<Vector3d> cubePoints = precisionCube(radius, subdivisions);
	for (const Vector3d& point : cubePoints) {
		mesh.vertices.push_back({ point.as_float(), Color::Random() });
	}
}

std::vector<Violet::Vector3d> Violet::Shape::precisionCube(double radius, uint subdivisions) {
	std::vector<Violet::Vector3d> cubePoints;
	double stride = (2.0 * radius) / ((double)subdivisions + 1.0);
	std::vector<Violet::Vector3d> facePoints;
	for (size_t side = 0; side < 6; side++) {
		facePoints.clear();
		for (size_t i = 0; i < subdivisions + 1; i++) {
			for (size_t j = 0; j < subdivisions + 1; j++) {
				double x = -radius + (stride * (double)i);
				double y = -radius + (stride * (double)j);
				facePoints.push_back({ x,          y,          0.0 });
				facePoints.push_back({ x + stride, y,          0.0 });
				facePoints.push_back({ x,          y + stride, 0.0 });
				facePoints.push_back({ x + stride, y,          0.0 });
				facePoints.push_back({ x + stride, y + stride, 0.0 });
				facePoints.push_back({ x,          y + stride, 0.0 });
			}
		}
		if (side == 0) {
			for (Violet::Vector3d& point : facePoints) {
				point.z += radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 1) {
			for (Violet::Vector3d& point : facePoints) {
				point.rotate(Violet::Vector3d(1.0, 0.0, 0.0), PI / 2.0);
				point.y += radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 2) {
			for (Violet::Vector3d& point : facePoints) {
				point.rotate(Violet::Vector3d(1.0, 0.0, 0.0), PI);
				point.z -= radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 3) {
			for (Violet::Vector3d& point : facePoints) {
				point.rotate(Violet::Vector3d(1.0, 0.0, 0.0), -PI / 2.0);
				point.y -= radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 4) {
			for (Violet::Vector3d& point : facePoints) {
				point.rotate(Violet::Vector3d(0.0, 1.0, 0.0), PI / 2.0);
				point.x += radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 5) {
			for (Violet::Vector3d& point : facePoints) {
				point.rotate(Violet::Vector3d(0.0, 1.0, 0.0), -PI / 2.0);
				point.x -= radius;
				cubePoints.push_back(point);
			}
		}
	}
	return cubePoints;
}

