
#include "Matrix.h"

Violet::Matrix::Matrix() {
	setIdentity();
}

Violet::Matrix::Matrix(double a, double b, double c, double d,
	           double e, double f, double g, double h,
	           double i, double j, double k, double l,
	           double m, double n, double o, double p) {
	m_data[0][0] = a; m_data[0][1] = b; m_data[0][2] = c; m_data[0][3] = d;
	m_data[1][0] = e; m_data[1][1] = f; m_data[1][2] = g; m_data[1][3] = h;
	m_data[2][0] = i; m_data[2][1] = j; m_data[2][2] = k; m_data[2][3] = l;
	m_data[3][0] = m; m_data[3][1] = n; m_data[3][2] = o; m_data[3][3] = p;
}

void Violet::Matrix::setIdentity() {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			m_data[i][j] = 0.0;
		}
		m_data[i][i] = 1.0;
	}
}

Violet::Matrix Violet::Matrix::buildScalarMatrix(const double scale) {
	Matrix matrix(
		scale, 0.0, 0.0, 0.0,
		0.0, scale, 0.0, 0.0,
		0.0, 0.0, scale, 0.0,
		0.0, 0.0, 0.0, 1.0
	);
	return matrix;
}

Violet::Matrix Violet::Matrix::buildTranslationMatrix(const Vector3d& position) {
	Matrix matrix(
		1.0, 0.0, 0.0, position.x,
		0.0, 1.0, 0.0, position.y,
		0.0, 0.0, 1.0, position.z,
		0.0, 0.0, 0.0, 1.0
	);
	return matrix;
}

Violet::Matrix Violet::Matrix::buildQuaternionRotationMatrix(const Quaternion& quat) {
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

const float* Violet::Matrix::as_float() {
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			m_gl_dataFloatColumnMajor[j][i] = (float)m_data[i][j];
		}
	}
	return &m_gl_dataFloatColumnMajor[0][0];
}

double* Violet::Matrix::operator [] (size_t i) {
	assert(i < 4);  return m_data[i];
}

const double* Violet::Matrix::operator [] (size_t i) const {
	assert(i < 4); return m_data[i];
}

Violet::Matrix Violet::Matrix::operator * (const Matrix& otherMatrix) const {
	Matrix result;
	for (size_t i = 0; i < 4; i++) {
		for (size_t j = 0; j < 4; j++) {
			double dot = 0.0;
			for (int k = 0; k < 4; k++) {
				dot += m_data[i][k] * otherMatrix[k][j];
			}
			result[i][j] = dot;
		}
	}
	return result;
}

