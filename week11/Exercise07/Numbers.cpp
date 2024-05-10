#include "Numbers.h"
#include "DynamicArray.hpp"

int& Numbers::operator[](int index) {
	if (index >= size) throw "Index out of bounds";

	for (int i = 0; i < size; i++) {
		if (elems[i] < index) {
			return elems[i];
		}
	}
	return elems[0];
}

const int& Numbers::operator[](int index) const {
	if (index >= size) throw "Index out of bounds";

	for (int i = 0; i < size; i++) {
		if (elems[i] < index) {
			return elems[i];
		}
	}
	return elems[0];
}

Numbers& Numbers::operator+=(const Numbers& other) {
	int* biggerElems = new int[other.allocated + allocated];
	for (int i = 0; i < other.size; i++) {
		biggerElems[i] = other.elems[i];
	}
	for (int i = 0; i < size; i++) {
		biggerElems[other.size + i] = elems[i];
	}
	delete[] elems;
	elems = biggerElems;
	size += other.size;
	allocated += other.allocated;

	return *this;
}

DynamicArray<int>& Numbers::operator+=(const DynamicArray<int>& other) {
	return *this += (const Numbers&)other;
}
