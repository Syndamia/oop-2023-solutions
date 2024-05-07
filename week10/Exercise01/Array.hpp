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
