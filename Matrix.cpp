
#include "Matrix.h"

Matrix::Matrix() {
	setIdentity();
}

Matrix::Matrix(double a, double b, double c, double d,
	           double e, double f, double g, double h,
	           double i, double j, double k, double l,
	           double m, double n, double o, double p) {
	data[0][0] = a; data[0][1] = b; data[0][2] = c; data[0][3] = d;
	data[1][0] = e; data[1][1] = f; data[1][2] = g; data[1][3] = h;
	data[2][0] = i; data[2][1] = j; data[2][2] = k; data[2][3] = l;
	data[3][0] = m; data[3][1] = n; data[3][2] = o; data[3][3] = p;
}

void Matrix::setIdentity() {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			data[i][j] = 0.0;
		}
		data[i][i] = 1.0;
	}
}

Matrix Matrix::buildScalarMatrix(const double scale) {
	Matrix matrix(
		scale, 0.0, 0.0, 0.0,
		0.0, scale, 0.0, 0.0,
		0.0, 0.0, scale, 0.0,
		0.0, 0.0, 0.0, 1.0
	);
	return matrix;
}

Matrix Matrix::buildTranslationMatrix(const double3& position) {
	Matrix matrix(
		1.0, 0.0, 0.0, position.x,
		0.0, 1.0, 0.0, position.y,
		0.0, 0.0, 1.0, position.z,
		0.0, 0.0, 0.0, 1.0
	);
	return matrix;
}

Matrix Matrix::buildQuaternionRotationMatrix(const Quaternion& quat) {
	double xx = quat.x * quat.x;
	double yy = quat.y * quat.y;
	double zz = quat.z * quat.z;
	double xy = quat.x * quat.y;
	double xz = quat.x * quat.z;
	double yz = quat.y * quat.z;
	double wx = quat.w * quat.x;
	double wy = quat.w * quat.y;
	double wz = quat.w * quat.z;
	Matrix matrix(
		1.0 - 2.0 * (yy + zz), 2.0 * (xy - wz), 2.0 * (xz + wy), 0.0,
		2.0 * (xy + wz), 1.0 - 2.0 * (xx + zz), 2.0 * (yz - wx), 0.0,
		2.0 * (xz - wy), 2.0 * (yz + wx), 1.0 - 2.0 * (xx + yy), 0.0,
		0.0, 0.0, 0.0, 1.0
	);
	return matrix;
}

const float* Matrix::as_float() {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			gl_dataFloatColumnMajor[j][i] = (float)data[i][j];
		}
	}
	return &gl_dataFloatColumnMajor[0][0];
}

double* Matrix::operator [] (size_t i) {
	assert(i < 4);  return data[i];
}

const double* Matrix::operator [] (size_t i) const {
	assert(i < 4); return data[i];
}

Matrix Matrix::operator * (const Matrix& otherMatrix) const {
	Matrix result;
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			double dot = 0.0;
			for (int k = 0; k < 4; k++) {
				dot += data[i][k] * otherMatrix[k][j];
			}
			result[i][j] = dot;
		}
	}
	return result;
}

