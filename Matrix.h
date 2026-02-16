
#pragma once

#include "Vector.h"

class double4x4 {
public:
	double4x4() {
		reset();
	}

	void reset() {
		double4x4& A = (*this);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				A[i][j] = 0.0;
			}
			A[i][i] = 1.0;
		}
	}

	void set(double a, double b, double c, double d,
			 double e, double f, double g, double h,
			 double i, double j, double k, double l,
			 double m, double n, double o, double p) {
		double4x4& A = (*this);
		A[0][0] = a; A[0][1] = b; A[0][2] = c; A[0][3] = d;
		A[1][0] = e; A[1][1] = f; A[1][2] = g; A[1][3] = h;
		A[2][0] = i; A[2][1] = j; A[2][2] = k; A[2][3] = l;
		A[3][0] = m; A[3][1] = n; A[3][2] = o; A[3][3] = p;
	}

	void rotate(double3 axis, double theta) {
		axis.normalize();
		double c = cos(theta);
		double s = sin(theta);
		double t = 1.0 - c;
		double x = axis.x;
		double y = axis.y;
		double z = axis.z;
		double4x4 rotMatrix;
		rotMatrix.set(
			(t * x * x) + (c), (t * y * x) - (s * z), (t * z * x) + (s * y), 0.0,
			(t * x * y) + (s * z), (t * y * y) + (c), (t * z * y) - (s * x), 0.0,
			(t * x * z) - (s * y), (t * y * z) + (s * x), (t * z * z) + (c), 0.0,
			0.0, 0.0, 0.0, 1.0
		);
		(*this) = (*this) * rotMatrix;
	}

	void scale(double scale) {
		double4x4 scaleMatrix;
		scaleMatrix.set(
			scale, 0.0, 0.0, 0.0,
			0.0, scale, 0.0, 0.0,
			0.0, 0.0, scale, 0.0,
			0.0, 0.0, 0.0, 1.0
		);
		(*this) = (*this) * scaleMatrix;
	}

	void translate(double3 translation) {
		double x = translation.x;
		double y = translation.y;
		double z = translation.z;
		double4x4 transMatrix;
		transMatrix.set(
			1.0, 0.0, 0.0, x,
			0.0, 1.0, 0.0, y,
			0.0, 0.0, 1.0, z,
			0.0, 0.0, 0.0, 1.0
		);
		(*this) = (*this) * transMatrix;
	}

	double* operator[](size_t i) {
		assert(i < 4);  return data[i];
	}

	const double* operator[](size_t i) const {
		assert(i < 4); return data[i];
	}

	double4x4 operator*(const double4x4& otherMatrix) const {
		const double4x4& A = *this;
		const double4x4& B = otherMatrix;
		double4x4 result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				double dot = 0.0;
				for (int k = 0; k < 4; k++) {
					dot += A[i][k] * B[k][j];
				}
				result[i][j] = dot;
			}
		}
		return result;
	}

	const float* as_float() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				gl_dataFloat[i][j] = (float)data[i][j];
			}
		}
		return &gl_dataFloat[0][0];
	}
	
private:
	double data[4][4] = { 0.0 };
	float gl_dataFloat[4][4] = { 0.0f };
};

