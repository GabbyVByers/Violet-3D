
#include "Mesh.h"

inline static std::vector<double3> doublePrecisionCube(double radius, size_t sub) {
	std::vector<double3> cubePoints;
	double stride = (2.0 * radius) / ((double)sub + 1.0);
	static std::vector<double3> facePoints;
	for (size_t side = 0; side < 6; side++) {
		facePoints.clear();
		for (size_t i = 0; i < sub + 1; i++) {
			for (size_t j = 0; j < sub + 1; j++) {
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
			for (double3& point : facePoints) {
				point.z += radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 1) {
			for (double3& point : facePoints) {
				point.rotate(double3(1.0, 0.0, 0.0), PI / 2.0);
				point.y += radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 2) {
			for (double3& point : facePoints) {
				point.rotate(double3(1.0, 0.0, 0.0), PI);
				point.z -= radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 3) {
			for (double3& point : facePoints) {
				point.rotate(double3(1.0, 0.0, 0.0), -PI / 2.0);
				point.y -= radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 4) {
			for (double3& point : facePoints) {
				point.rotate(double3(0.0, 1.0, 0.0), PI / 2.0);
				point.x += radius;
				cubePoints.push_back(point);
			}
		}
		if (side == 5) {
			for (double3& point : facePoints) {
				point.rotate(double3(0.0, 1.0, 0.0), -PI / 2.0);
				point.x -= radius;
				cubePoints.push_back(point);
			}
		}
	}
	return cubePoints;
}

void Mesh::sphere(double radius, size_t sub) { // mind precision loss
	std::vector<double3> cubePoints = doublePrecisionCube(1.0, sub);
	vertices.clear();
	for (double3 point : cubePoints) {
		point.normalize();
		point = point * radius;
		vertices.push_back(Vertex(point.as_float(), Color::Random()));
	}
}

void Mesh::cube(double radius, size_t sub) {
	std::vector<double3> cubePoints = doublePrecisionCube(radius, sub);
	vertices.clear();
	for (double3 point : cubePoints) {
		vertices.push_back(Vertex(point.as_float(), Color::Random()));
	}
}

