#include "Exercise6.h"
#include <iostream>

/* Private */

void Matrix::addBy(int amount) {
	for (int i = 0; i < 4; i++) {
		values[i] += amount;
	}
}

/* Public */

Matrix::Matrix(int a, int b, int c, int d) {
	values[0] = a;
	values[1] = b;
	values[2] = c;
	values[3] = d;
}

Matrix& Matrix::operator++() { // ++matrix
	addBy(+1);
	return *this;
}
Matrix Matrix::operator++(int) { // matrix++
	Matrix copy = *this;
	addBy(+1);
	return copy;
}
Matrix& Matrix::operator--() { // --matrix
	addBy(-1);
	return *this;
}
Matrix Matrix::operator--(int) { // matrix--
	Matrix copy = *this;
	addBy(-1);
	return copy;
}

Matrix& Matrix::operator+=(const Matrix& rhs) {
	for (int i = 0; i < 4; i++) {
		values[i] += rhs.values[i];
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& rhs) {
	for (int i = 0; i < 4; i++) {
		values[i] -= rhs.values[i];
	}
	return *this;
}
Matrix& Matrix::operator*=(const Matrix& rhs) {
	values[0] = values[0] * rhs.values[0] + values[1] * rhs.values[2];
	values[1] = values[0] * rhs.values[1] + values[1] * rhs.values[3];
	values[2] = values[2] * rhs.values[0] + values[3] * rhs.values[2];
	values[3] = values[2] * rhs.values[1] + values[3] * rhs.values[3];
	return *this;
}

/* Friend */

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
	Matrix ret = lhs;
	ret += rhs;
	return ret;
}
Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
	Matrix ret = lhs;
	ret -= rhs;
	return ret;
}
Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
	Matrix ret = lhs;
	ret *= rhs;
	return ret;
}

std::ostream& operator<<(std::ostream& lhs, const Matrix& rhs) {
	return lhs << rhs.values[0] << "," << rhs.values[1] << std::endl << rhs.values[2] << "," << rhs.values[3] << std::endl;
}
std::istream& operator>>(std::istream& lhs, Matrix& rhs) {
	return lhs >> rhs.values[0] >> rhs.values[1] >> rhs.values[2] >> rhs.values[3];
}
