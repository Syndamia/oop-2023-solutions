#pragma once

template <class T>
class Set {
	T* elements;
	unsigned size;

	void free();
	void copyFrom(const Set& other);

public:
	Set();
	~Set();
	Set(const Set& other);
	Set& operator=(const Set& other);
	Set(Set&& other);
	Set& operator=(Set&& other);

	Set& operator+=(const Set& right);
	template <class U>
	friend Set<U> operator+(const Set<U>& left, const Set<U>& right);

	Set& operator*=(const Set& right);
	template <class U>
	friend Set<U> operator*(const Set<U>& left, const Set<U>& right);

	Set& operator-=(const Set& right);
	template <class U>
	friend Set operator-(const Set& left, const Set& right);
};

template <class T>
void Set<T>::free() {
	delete[] elements;
}

template <class T>
void Set<T>::copyFrom(const Set& other) {
	this->size = other.size;
	this->elements = new T[size];
	for (int i = 0; i < size; i++) {
		this->elements[i] = other.elements[i];
	}
}

template <class T>
Set<T>::Set() {
	elements = nullptr;
	size = 0;
}

template <class T>
Set<T>::~Set() {
	delete[] elements;
}

template <class T>
Set<T>::Set(const Set& other) {
	copyFrom(other);
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template <class T>
Set<T>::Set(Set<T>&& other) {
	this->size = other.size;
	this->elements = other.elements;
	other.elements = nullptr;
}

template <class T>
Set<T>& Set<T>::operator=(Set<T>&& other) {
	if (this != &other) {
		free();

		this->size = other.size;
		this->elements = other.elements;
		other.elements = nullptr;
	}
	return *this;
}

template <class T>
Set<T>& Set<T>::operator+=(const Set<T>& right) {
	T* biggerArray = new T[size + right.size];
	for (int i = 0; i < size; i++) {
		biggerArray[i] = elements[i];
	}
	for (int i = 0; i < right.size; i++) {
		biggerArray[i+size] = right.elements[i];
	}
	delete[] elements;
	elements = biggerArray;
	size += right.size;

	return *this;
}

template <class T>
Set<T> operator+(const Set<T>& left, const Set<T>& right) {
	Set<T> setUnion = left;
	setUnion += right;
	return setUnion;
}

template <class T>
Set<T>& Set<T>::operator*=(const Set<T>& right) {
	T* commonArray = new T[size];
	unsigned commonCount = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < right.size; j++) {
			if (elements[i] == right.elements[j]) {
				commonArray[commonCount++] = elements[i];
				break;
			}
		}
	}

	size = commonCount;
	delete[] elements;
	elements = new T[size];
	for (int i = 0; i < size; i++) {
		elements[i] = commonArray[i];
	}
	delete[] commonArray;

	return *this;
}

template <class T>
Set<T> operator*(const Set<T>& left, const Set<T>& right) {
	Set<T> setIntersection = left;
	setIntersection *= right;
	return setIntersection;
}

template <class T>
Set<T>& Set<T>::operator-=(const Set& right) {
	Set complement = right * (*this);
	*this = complement;
	return *this;
}

template <class T>
Set<T> operator-(const Set<T>& left, const Set<T>& right) {
	Set<T> setComplement = left;
	setComplement -= right;
	return setComplement;
}
