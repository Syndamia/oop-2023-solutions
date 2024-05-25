#pragma once
#include "Container.hpp"

template <class T>
class Resizeable : virtual public Container<T> {
	void resize();

public:
	void InsertAt(const T& element, unsigned index);
};

template <class T>
void Resizeable<T>::resize() {
	this->size++;
	T* biggerArr = new T[this->size];
	for (int i = 0; i < this->size - 1; i++) {
		biggerArr[i] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = biggerArr;
}

template <class T>
void Resizeable<T>::InsertAt(const T& element, unsigned index) {
	if (index >= this->size) {
		throw "Index out of range!";
	}

	resize();
	for (int i = this->size - 1; i > index; i++) {
		this->arr[i] = this->arr[i-1];
	}
	this->arr[index] = element;
}
