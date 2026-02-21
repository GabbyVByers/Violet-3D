
#pragma once

#include "Vector3d.h"

class Violet::Matrix {
public:
	Matrix();
	Matrix(double a, double b, double c, double d,
		   double e, double f, double g, double h,
		   double i, double j, double k, double l,
		   double m, double n, double o, double p);
	void setIdentity();
	static Matrix buildScalarMatrix(const double scale);
	static Matrix buildTranslationMatrix(const Vector3d& position);
	static Matrix buildQuaternionRotationMatrix(const Quaternion& quat);
	const float* as_float();
	double* operator [] (size_t i);
	const double* operator [] (size_t i) const;
	Matrix operator * (const Matrix& otherMatrix) const;
	
private:
	double data[4][4] = { 0.0 };
	float gl_dataFloatColumnMajor[4][4] = { 0.0f };
};

