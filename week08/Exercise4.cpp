#include "Exercise4.h"

void FloatArray::free() {
	delete[] numbers;
}

void FloatArray::copyFrom(const FloatArray& other) {
	this->lastUnused = other.lastUnused;
	this->allocated = other.allocated;
	this->numbers = new float[allocated];
	for (int i = 0; i < this->lastUnused; i++) {
		this->numbers[i] = other.numbers[i];
	}
}

void FloatArray::resize() {
	allocated *= 2;
	float* moreNumbers = new float[allocated];
	for (int i = 0; i < lastUnused; i++) {
		moreNumbers[i] = numbers[i];
	}
	delete[] numbers;
	numbers = moreNumbers;
}

FloatArray::FloatArray() {
	numbers = nullptr;
	lastUnused = allocated = 0;
}

FloatArray::~FloatArray() {
	free();
}

FloatArray::FloatArray(const FloatArray& other) {
	copyFrom(other);
}

FloatArray& FloatArray::operator=(const FloatArray& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

FloatArray::FloatArray(FloatArray&& other) {
	this->numbers = other.numbers;
	other.numbers = nullptr;

	this->lastUnused = other.lastUnused;
	this->allocated = other.allocated;
}

FloatArray& FloatArray::operator=(FloatArray&& other) {
	if (this != &other) {
		free();

		this->numbers = other.numbers;
		other.numbers = nullptr;

		this->lastUnused = other.lastUnused;
		this->allocated = other.allocated;
	}
	return *this;
}

void FloatArray::Add(float number) {
	if (allocated == lastUnused) {
		resize();
	}
	numbers[lastUnused++] = number;
}

FloatArray& FloatArray::operator+=(const FloatArray& other) {
	for (int i = 0; i < other.lastUnused; i++) {
		this->Add(other.numbers[i]);
	}
	return *this;
}

FloatArray& FloatArray::operator+=(float number) {
	for (int i = 0; i < lastUnused; i++) {
		numbers[i] += number;
	}
	return *this;
}

float& FloatArray::operator[](int index) {
	if (index < 0 || lastUnused <= index) {
		throw "Invalid index!";
	}
	return numbers[index];
}

FloatArray operator+(const FloatArray& left, const FloatArray& right) {
	FloatArray output;
	(output += left) += right;
	return output;
}

FloatArray operator+(const FloatArray& left, float right) {
	FloatArray output = left; // Копиращ конструктор
	output += right;
	return output;
}

bool operator==(const FloatArray& left, const FloatArray& right) {
	if (left.lastUnused != right.lastUnused) {
		return false;
	}
	for (int i = 0; i < left.lastUnused; i++) {
		if (left.numbers[i] != right.numbers[i]) {
			return false;
		}
	}
	return true;
}

bool operator!=(const FloatArray& left, const FloatArray& right) {
	return !(left == right);
}

std::ostream& operator<<(std::ostream& ostr, const FloatArray& right) {
	ostr << right.lastUnused << " ";
	for (int i = 0; i < right.lastUnused; i++) {
		ostr << right.numbers[i] << " ";
	}
	return ostr;
}

std::istream& operator>>(std::istream& istr, FloatArray& right) {
	int length;
	istr >> length;
	right.lastUnused = 0;
	for (int i = 0; i < length; i++) {
		float temp;
		istr >> temp;
		right.Add(temp);
	}
	return istr;
}
