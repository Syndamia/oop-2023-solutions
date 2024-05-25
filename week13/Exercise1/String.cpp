#include "String.h"
#include <cstring>

void String::free() {
	delete[] str;
}

void String::copyFrom(const String& other) {
	this->str = new char[strlen(other.str) + 1];
	strcpy(this->str, other.str);
}

String::String() {
	this->str = nullptr;
}

String::~String() {
	free();
}

String::String(const String& other) {
	copyFrom(other);
}

String& String::operator=(const String& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

String::String(String&& other) {
	this->str = other.str;
	other.str = nullptr;
}

String& String::operator=(String&& other) {
	if (this != &other) {
		free();

		this->str = other.str;
		other.str = nullptr;
	}
	return *this;
}

String::String(const char* str) {
	this->str = new char[strlen(str) + 1];
	strcpy(this->str, str);
}
