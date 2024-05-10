#include "String.h"
#include <cstring>

char& String::operator[](int index) {
	if (index <= 1) throw "Invalid index";

	for (int i = 0; i < size; i++) {
		if ('A' <= elems[i] && elems[i] <= 'Z') {
			index--;
			if (index == 0) {
				return elems[i];
			}
		}
	}
	return elems[size-1];
}

const char& String::operator[](int index) const {
	if (index <= 1) throw "Invalid index";

	for (int i = 0; i < size; i++) {
		if ('A' <= elems[i] && elems[i] <= 'Z') {
			index--;
			if (index == 0) {
				return elems[i];
			}
		}
	}
	return elems[size-1];
}

String& String::operator+=(const String& other) {
	char* biggerStr = new char[allocated + other.allocated];
	for (int i = 0; i < size; i++) {
		biggerStr[i] = elems[i];
	}
	for (int i = 0; i < other.size; i++) {
		biggerStr[size + i] = other.elems[i];
	}
	delete[] elems;
	elems = biggerStr;
	allocated += other.allocated;
	size += other.size;
	return *this;
}

DynamicArray<char>& String::operator+=(const DynamicArray<char>& other) {
	return *this += (const String&)other;
}
