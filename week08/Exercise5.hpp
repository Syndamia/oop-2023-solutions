#include <iostream>

template <class T>
class DynamicArray {
	T *values;
	int lastUnused;
	int allocated;

	void free();
	void copyFrom(const DynamicArray<T>& other);

	void resize();

public:
	DynamicArray();
	~DynamicArray();
	DynamicArray(const DynamicArray<T>& other);
	DynamicArray<T>& operator=(const DynamicArray<T>& other);
	DynamicArray(DynamicArray<T>&& other);
	DynamicArray<T>& operator=(DynamicArray<T>&& other);

	void Add(const T& newValue);

	// Тези оператори променят аргумента си, затова е по-добре да са член-функции
	DynamicArray<T>& operator+=(const DynamicArray<T>& other);
	DynamicArray<T>& operator+=(const T& newValue);
	// По дефиниция не може operator=, operator(), operator[] и operator-> да бъдат имплементирани
	// като приятелски функции
	T& operator[](int index);

	// Тези оператори не променят аргументите си, затова е по-добре да са приятелски
	template <class U>
	friend DynamicArray<U> operator+(const DynamicArray<U>& left, const DynamicArray<U>& right);
	template <class U>
	friend DynamicArray<U> operator+(const DynamicArray<U>& left, const U& right);
	template <class U>
	friend bool operator==(const DynamicArray<U>& left, const DynamicArray<U>& right);
	template <class U>
	friend bool operator!=(const DynamicArray<U>& left, const DynamicArray<U>& right);
	template <class U>
	friend std::ostream& operator<<(std::ostream& ostr, const DynamicArray<U>& right);
	template <class U>
	friend std::istream& operator>>(std::istream& ostr, DynamicArray<U>& right);
};

template <class T>
void DynamicArray<T>::free() {
	delete[] values;
}

template <class T>
void DynamicArray<T>::copyFrom(const DynamicArray<T>& other) {
	this->lastUnused = other.lastUnused;
	this->allocated = other.allocated;
	this->values = new T[allocated];
	for (int i = 0; i < this->lastUnused; i++) {
		this->values[i] = other.values[i];
	}
}

template <class T>
void DynamicArray<T>::resize() {
	allocated *= 2;
	T* moreValues = new T[allocated];
	for (int i = 0; i < lastUnused; i++) {
		moreValues[i] = values[i];
	}
	delete[] values;
	values = moreValues;
}

template <class T>
DynamicArray<T>::DynamicArray() {
	values = nullptr;
	lastUnused = allocated = 0;
}

template <class T>
DynamicArray<T>::~DynamicArray() {
	free();
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& other) {
	copyFrom(other);
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <class T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& other) {
	this->values = other.values;
	other.values = nullptr;

	this->lastUnused = other.lastUnused;
	this->allocated = other.allocated;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>&& other) {
	if (this != &other) {
		free();

		this->values = other.values;
		other.values = nullptr;

		this->lastUnused = other.lastUnused;
		this->allocated = other.allocated;
	}
	return *this;
}

template <class T>
void DynamicArray<T>::Add(const T& number) {
	if (allocated == lastUnused) {
		resize();
	}
	values[lastUnused++] = number;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator+=(const DynamicArray<T>& other) {
	for (int i = 0; i < other.lastUnused; i++) {
		this->Add(other.values[i]);
	}
	return *this;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator+=(const T& number) {
	for (int i = 0; i < lastUnused; i++) {
		values[i] += number;
	}
	return *this;
}

template <class T>
T& DynamicArray<T>::operator[](int index) {
	if (index < 0 || lastUnused <= index) {
		throw "Invalid index!";
	}
	return values[index];
}

template <class T>
DynamicArray<T> operator+(const DynamicArray<T>& left, const DynamicArray<T>& right) {
	DynamicArray<T> output;
	(output += left) += right;
	return output;
}

template <class T>
DynamicArray<T> operator+(const DynamicArray<T>& left, T right) {
	DynamicArray<T> output = left; // Копиращ конструктор
	output += right;
	return output;
}

template <class T>
bool operator==(const DynamicArray<T>& left, const DynamicArray<T>& right) {
	if (left.lastUnused != right.lastUnused) {
		return false;
	}
	for (int i = 0; i < left.lastUnused; i++) {
		if (left.values[i] != right.values[i]) {
			return false;
		}
	}
	return true;
}

template <class T>
bool operator!=(const DynamicArray<T>& left, const DynamicArray<T>& right) {
	return !(left == right);
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const DynamicArray<T>& right) {
	for (int i = 0; i < right.lastUnused; i++) {
		ostr << right.values[i] << " ";
	}
	return ostr;
}

template <class T>
std::istream& operator>>(std::istream& istr, DynamicArray<T>& right) {
	int length;
	istr >> length;
	right.lastUnused = 0;
	for (int i = 0; i < length; i++) {
		T temp;
		istr >> temp;
		right.Add(temp);
	}
	return istr;
}
