#pragma once
#include "MixedArray.hpp"

template <class T, class U>
class DirectConcat : public MixedArray<T, U> {
public:
	virtual MixedArray<T, U>* operator+=(const MixedArray<T, U>* other) override;
};

template <class T, class U>
MixedArray<T, U>* DirectConcat<T, U>::operator+=(const MixedArray<T, U>* other) {
	T* biggerFirst = new T[this->allocated + other->allocated];
	U* biggerSecond = new U[this->allocated + other->allocated];

	for (int i = 0; i < this->size; i++) {
		biggerFirst[i] = this->first[i];
		biggerSecond[i] = this->second[i];
	}
	for (int i = 0; i < other->size; i++) {
		biggerFirst[this->size + i] = other->first[i];
		biggerSecond[this->size + i] = other->second[i];
	}

	delete[] this->first;
	this->first = biggerFirst;
	delete[] this->second;
	this->second = biggerSecond;
	this->allocated += other->allocated;
	this->size += other->size;

	return this;
}
