#pragma once
#include "Indexable.hpp"
#include "Resizeable.hpp"

template <class T>
class Vector : public Indexable<T>, public Resizeable<T> {
public:
	void pop_back();
	void pop_front();
	void push_back(const T& element);
	void push_front(const T& element);
};

template <class T>
void Vector<T>::pop_back() {
	this->size--;
}

template <class T>
void Vector<T>::pop_front() {
	for (int i = 0; i < this->size - 1; i++) {
		this->arr[i] = this->arr[i+1];
	}
	this->size--;
}

template <class T>
void Vector<T>::push_back(const T& element) {
	this->InsertAt(this->size - 1, element);
}

template <class T>
void Vector<T>::push_front(const T& element) {
	this->InsertAt(0, element);
}
