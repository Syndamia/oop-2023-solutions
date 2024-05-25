#include "IndexArray.h"
#include <cstring>

void IndexArray::free() {
	delete[] indecies;
}

void IndexArray::copyFrom(const IndexArray& other) {
	this->size = other.size;
	this->indecies = new int[size];
	for (int i = 0; i < size; i++) {
		this->indecies[i] = other.indecies[i];
	}
}

IndexArray::IndexArray() {
	this->indecies = nullptr;
	this->size = 0;
}

IndexArray::~IndexArray() {
	free();
}

IndexArray::IndexArray(const IndexArray& other) {
	copyFrom(other);
}

IndexArray& IndexArray::operator=(const IndexArray& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

IndexArray::IndexArray(IndexArray&& other) {
	this->indecies = other.indecies;
	other.indecies = nullptr;
}

IndexArray& IndexArray::operator=(IndexArray&& other) {
	if (this != &other) {
		free();

		this->indecies = other.indecies;
		other.indecies = nullptr;
	}
	return *this;
}

