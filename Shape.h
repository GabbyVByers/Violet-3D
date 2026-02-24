
#pragma once

#include "Core.h"
#include "Mesh.h"
#include "Color.h"

class Violet::Shape {
public:
	// Shape.Utilities.cpp
	static void sphere(Mesh& mesh, double radius, uint subdivisions);
	static void cube(Mesh& mesh, double radius, uint subdivisions);

private:
	// Shape.Private.cpp
	Shape() = delete;
	~Shape() = delete;
	static std::vector<Vector3d> precisionCube(double radius, uint subdivisions);
};

