#include <iostream>

class FloatArray {
	float *numbers;
	int lastUnused;
	int allocated;

	void free();
	void copyFrom(const FloatArray& other);

	void resize();

public:
	FloatArray();
	~FloatArray();
	FloatArray(const FloatArray& other);
	FloatArray& operator=(const FloatArray& other);
	FloatArray(FloatArray&& other);
	FloatArray& operator=(FloatArray&& other);

	void Add(float number);

	// Тези оператори променят аргумента си, затова е по-добре да са член-функции
	FloatArray& operator+=(const FloatArray& other);
	FloatArray& operator+=(float number);
	// По дефиниция не може operator=, operator(), operator[] и operator-> да бъдат имплементирани
	// като приятелски функции
	float& operator[](int index);

	// Тези оператори не променят аргументите си, затова е по-добре да са приятелски
	friend FloatArray operator+(const FloatArray& left, const FloatArray& right);
	friend FloatArray operator+(const FloatArray& left, float right);
	friend bool operator==(const FloatArray& left, const FloatArray& right);
	friend bool operator!=(const FloatArray& left, const FloatArray& right);
	friend std::ostream& operator<<(std::ostream& ostr, const FloatArray& right);
	friend std::istream& operator>>(std::istream& ostr, FloatArray& right);
};
