#pragma once
#include "MixedArray.hpp"

template <class T, class U>
class MixedConcat : public MixedArray<T, U> {
public:
	virtual MixedArray<T, U>* operator+=(const MixedArray<T, U>* other) override;
};

template <class T, class U>
MixedArray<T, U>* MixedConcat<T, U>::operator+=(const MixedArray<T, U>* other) {
	T* biggerFirst = new T[this->allocated + other->allocated];
	U* biggerSecond = new U[this->allocated + other->allocated];

	for (int i = 0; i < this->size + other->size; i++) {
		if (i % 2 == 0) {
			biggerFirst[i] = this->first[i / 2];
			biggerSecond[i] = this->second[i / 2];
		}
		else {
			biggerFirst[i] = other->first[(i - 1) / 2];
			biggerSecond[i] = other->second[(i - 1) / 2];
		}
	}

	delete[] this->first;
	this->first = biggerFirst;
	delete[] this->second;
	this->second = biggerSecond;
	this->allocated += other->allocated;
	this->size += other->size;

	return this;
}
