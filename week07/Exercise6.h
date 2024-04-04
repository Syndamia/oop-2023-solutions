#include <iostream>

class Matrix {
	int values[4];

	void addBy(int amount);

public:
	Matrix(int a, int b, int c, int d);

	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);

	Matrix& operator+=(const Matrix& rhs);
	Matrix& operator-=(const Matrix& rhs);
	Matrix& operator*=(const Matrix& rhs);

	friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
	friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

	friend std::ostream& operator<<(std::ostream& lhs, const Matrix& rhs);
	friend std::istream& operator>>(std::istream& lhs, Matrix& rhs);
};

