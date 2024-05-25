#pragma once
#include "Container.hpp"

template <class T>
class Indexable : virtual public Container<T> {
public:
	T& operator[](unsigned index);
	const T& operator[](unsigned index) const;
};

template <class T>
T& Indexable<T>::operator[](unsigned index) {
	if (index > this->size) {
		throw "Index out of range!";
	}
	return this->arr[index];
}

template <class T>
const T& Indexable<T>::operator[](unsigned index) const {
	if (index > this->size) {
		throw "Index out of range!";
	}
	return this->arr[index];
}
