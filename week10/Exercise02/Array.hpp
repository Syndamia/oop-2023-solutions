#pragma once

template <class T>
class Array {
	T* arr;
	unsigned size;
	unsigned allocated;

	void resize();

	void free();
	void copyFrom(const Array& other);

public:
	Array();
	~Array();
	Array(const Array& other);
	Array& operator=(const Array& other);
	Array(Array&& other);
	Array& operator=(Array&& other);

	T& operator[](unsigned index);
	T& operator[](unsigned index) const;
	Array<T>& operator+=(const Array<T>& right);
	friend bool operator==(const Array<T>& left, const Array<T>& right);
	friend bool operator!=(const Array<T>& left, const Array<T>& right);
	friend Array<T> operator+(const Array<T>& left, const Array<T>& right);
};

template <class T>
void Array<T>::resize() {
	allocated *= 2;
	T* biggerArr = new T[allocated];
	for (int i = 0; i < size; i++) {
		biggerArr[i] = arr[i];
	}
	delete[] arr;
	arr = biggerArr;
}

template <class T>
void Array<T>::free() {
	delete[] arr;
}

template <class T>
void Array<T>::copyFrom(const Array& other) {
	this->size = other.size;
	this->allocated = other.allocated;
	this->arr = new T[allocated];
	for (int i = 0; i < size; i++) {
		this->arr[i] = other.arr[i];
	}
}

template <class T>
Array<T>::Array() {
	this->arr = nullptr;
	allocated = size = 0;
}

template <class T>
Array<T>::~Array() {
	free();
}

template <class T>
Array<T>::Array(const Array<T>& other) {
	copyFrom(other);
}

template <class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <class T>
Array<T>::Array(Array<T>&& other) {
	this->arr = other.arr;
	other.arr = nullptr;
}

template <class T>
Array<T>& Array<T>::operator=(Array<T>&& other) {
	if (this != &other) {
		free();

		this->arr = other.arr;
		other.arr = nullptr;
	}
	return *this;
}

template <class T>
T& Array<T>::operator[](unsigned index) {
	return arr[index];
}

template <class T>
T& Array<T>::operator[](unsigned index) const {
	return arr[index];
}

template <class T>
Array<T>& Array<T>::operator+=(const Array<T>& right) {
	for (int i = 0; i < right.size; i++) {
		if (size == allocated) {
			resize();
		}
		arr[size++] = right[i];
	}
}

template <class T>
bool operator==(const Array<T>& left, const Array<T>& right) {
	if (left.size != right.size) {
		return false;
	}

	for (int i = 0; i < left.size; i++) {
		if (left.arr[i] != right.arr[i]) {
			return false;
		}
	}
	return true;
}

template <class T>
bool operator!=(const Array<T>& left, const Array<T>& right) {
	return !(left == right);
}

template <class T>
Array<T> operator+(const Array<T>& left, const Array<T>& right) {
	Array<T> concat;
	concat += left;
	concat += right;
	return concat;
}
