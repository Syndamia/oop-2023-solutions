#include "Administrator.h"
#include <iostream>

void Administrator::resize() {
	allocated *= 2;
	int* bigger = new int[allocated];
	for (int i = 0; i < size; i++) {
		bigger[i] = arr[i];
	}
	delete[] arr;
	arr = bigger;
}

void Administrator::free() {
	delete[] arr;
}

void Administrator::copyFrom(const Administrator& other) {
	this->arr = new int[other.allocated];
	for (int i = 0; i < other.size; i++) {
		this->arr[i] = other.arr[i];
	}
}

Administrator::Administrator() : Moderator() {
	arr = nullptr;
	size = allocated = 0;
}

Administrator::~Administrator() {
	free();
}

Administrator::Administrator(const Administrator& other) : Moderator(other) {
	copyFrom(other);
}

Administrator& Administrator::operator=(const Administrator& other) {
	if (this != &other) {
		Moderator::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Administrator::Administrator(Administrator&& other) : Moderator(other) {
	this->arr = other.arr;
	other.arr = nullptr;
	this->size = other.size;
	this->allocated = other.allocated;
}

Administrator& Administrator::operator=(Administrator&& other) {
	if (this != &other) {
		free();
		Moderator::operator=(std::move(other));

		this->arr = other.arr;
		other.arr = nullptr;
		this->size = other.size;
		this->allocated = other.allocated;
	}
	return *this;
}

void Administrator::AddID(int value) {
	if (allocated <= size) {
		resize();
	}

	arr[size++] = value;
}

void Administrator::RemoveID(int value) {
	int i;
	for (i = 0; i < size; i++) {
		if (arr[i] == value) {
			break;
		}
	}
	for (; i < size - 1; i++) {
		arr[i] = arr[i+1];
	}
	size--;
}
