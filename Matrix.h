
#pragma once

#include "Double3.h"

class double4x4 {
public:
	// Matrix.cpp
	double4x4();
	void set(double a, double b, double c, double d, double e, double f, double g, double h,
		     double i, double j, double k, double l, double m, double n, double o, double p);
	void reset();
	void rotate(double3 axis, double theta);
	void scale(double scale);
	void translate(double3 translation);
	const float* as_float();
	double* operator[](size_t i);
	const double* operator[](size_t i) const;
	double4x4 operator*(const double4x4& otherMatrix) const;
	
private:
	double data[4][4] = { 0.0 };
	float gl_dataFloatColumnMajor[4][4] = { 0.0f };
};

