#pragma once

template <class T, class U>
class TwoArray {
	T* first;
	U* second;
	unsigned allocated;
	unsigned size;

	void free();
	void copyFrom(const TwoArray& other);

public:
	TwoArray();
	~TwoArray();
	TwoArray(const TwoArray& other);
	TwoArray& operator=(const TwoArray& other);
	TwoArray(TwoArray&& other);
	TwoArray& operator=(TwoArray&& other);

	T& operator[](int index);
	const T& operator[](int index) const;
	U& operator()(int index);
	const U& operator()(int index) const;
};

template <class T, class U>
void TwoArray<T, U>::free() {
	delete[] first;
	delete[] second;
}

template <class T, class U>
void TwoArray<T, U>::copyFrom(const TwoArray& other) {
	this->size = other.size;
	this->allocated = other.allocated;
	first = new T[allocated];
	second = new U[allocated];
	for (int i = 0; i < size; i++) {
		first[i] = other.first[i];
		second[i] = other.second[i];
	}
}

template <class T, class U>
TwoArray<T, U>::TwoArray() {
	first = second = nullptr;
	size = allocated = 0;
}

template <class T, class U>
TwoArray<T, U>::~TwoArray() {
	free();
}

template <class T, class U>
TwoArray<T, U>::TwoArray(const TwoArray& other) {
	copyFrom(other);
}

template <class T, class U>
TwoArray<T, U>& TwoArray<T, U>::operator=(const TwoArray& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <class T, class U>
TwoArray<T, U>::TwoArray(TwoArray&& other) {
	this->first = other.first;
	other.first = nullptr;
	this->second = other.second;
	other.second = nullptr;
	this->allocated = other.allocated;
	this->size = other.size;
}

template <class T, class U>
TwoArray<T, U>& TwoArray<T, U>::operator=(TwoArray&& other) {
	if (this != &other) {
		free();

		this->first = other.first;
		other.first = nullptr;
		this->second = other.second;
		other.second = nullptr;
		this->allocated = other.allocated;
		this->size = other.size;
	}
	return *this;
}

template <class T, class U>
T& TwoArray<T, U>::operator[](int index) {
	if (index < 0 || index >= size) throw "Invalid index!";
	return first[index];
}

template <class T, class U>
const T& TwoArray<T, U>::operator[](int index) const {
	if (index < 0 || index >= size) throw "Invalid index!";
	return first[index];
}

template <class T, class U>
U& TwoArray<T, U>::operator()(int index) {
	if (index < 0 || index >= size) throw "Invalid index!";
	return second[index];
}

template <class T, class U>
const U& TwoArray<T, U>::operator()(int index) const {
	if (index < 0 || index >= size) throw "Invalid index!";
	return second[index];
}
