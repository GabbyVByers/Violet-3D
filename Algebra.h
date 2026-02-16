
#pragma once

#include "Core.h"

struct double3 {
	double x;
	double y;
	double z;

	double3(double x = 0.0,
		    double y = 0.0,
		    double z = 0.0) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void normalize() {
		double len = sqrt((x * x) + (y * y) + (z * z));
		x /= len;
		y /= len;
		z /= len;
	}
};

struct float3 {
	float x;
	float y;
	float z;

	float3(float x = 0.0f,
		   float y = 0.0f,
		   float z = 0.0f) {
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

class double4x4 {
public:
	double4x4() {
		setIdentity();
	}

	void setIdentity() {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				data[i][j] = 0.0;
			}
			data[i][i] = 1.0;
		}
	}

	void setMatrix(double a, double b, double c, double d,
				   double e, double f, double g, double h,
				   double i, double j, double k, double l,
				   double m, double n, double o, double p) {
		data[0][0] = a; data[0][1] = b; data[0][2] = c; data[0][3] = d;
		data[1][0] = e; data[1][1] = f; data[1][2] = g; data[1][3] = h;
		data[2][0] = i; data[2][1] = j; data[2][2] = k; data[2][3] = l;
		data[3][0] = m; data[3][1] = n; data[3][2] = o; data[3][3] = p;
	}

	const double* getMatrix() const {
		return &data[0][0];
	}

	// Rodrigues' Rotation Formula
	void rotate(double3 axis, double theta) {
		axis.normalize();
		double c = cos(theta);
		double s = sin(theta);
		double t = 1.0 - c;
		double x = axis.x;
		double y = axis.y;
		double z = axis.z;
		double4x4 rotMatrix;
		rotMatrix.setMatrix((t * x * x) + (c),     (t * y * x) - (s * z), (t * z * x) + (s * y), 0.0,
			                (t * x * y) + (s * z), (t * y * y) + (c),     (t * z * y) - (s * x), 0.0,
							(t * x * z) - (s * y), (t * y * z) + (s * x), (t * z * z) + (c),     0.0,
							0.0,                   0.0,                   0.0,                   1.0);
		*this = multiply(*this, rotMatrix);
	}

	void scale(double3 scale) {
		double4x4 scaleMatrix;
		scaleMatrix.setMatrix(scale.x, 0.0,     0.0,     0.0,
			                  0.0,     scale.y, 0.0,     0.0,
			                  0.0,     0.0,     scale.z, 0.0,
			                  0.0,     0.0,     0.0,     1.0);
		*this = multiply(*this, scaleMatrix);
	}

	void scale(double scale) {
		double4x4 scaleMatrix;
		scaleMatrix.setMatrix(scale, 0.0,   0.0,   0.0,
			                  0.0,   scale, 0.0,   0.0,
			                  0.0,   0.0,   scale, 0.0,
			                  0.0,   0.0,   0.0,   1.0);
		*this = multiply(*this, scaleMatrix);
	}

	void translate(double3 translation) {
		double x = translation.x;
		double y = translation.y;
		double z = translation.z;
		double4x4 transMatrix;
		transMatrix.setMatrix(1.0, 0.0, 0.0, x,
			                  0.0, 1.0, 0.0, y,
			                  0.0, 0.0, 1.0, z,
			                  0.0, 0.0, 0.0, 1.0);
		*this = multiply(*this, transMatrix);
	}

private:
	double data[4][4] = { 0.0 };

	double4x4 multiply(const double4x4& A, const double4x4& B) const {
		double4x4 result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				double dot = 0.0;
				for (int k = 0; k < 4; k++) {
					dot += A.data[i][k] * B.data[k][j];
				}
				result.data[i][j] = dot;
			}
		}
		return result;
	}
};

