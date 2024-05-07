#include "String.h"
#include <cstring>

void String::free() {
	delete[] str;
}

void String::copyFrom(const String& other) {
	this->length = other.length;
	this->str = new char[strlen(other.str) + 1];
	strcpy(this->str, other.str);
}

String::String(const char* str) {
	this->length = strlen(str);
	this->str = new char[this->length + 1];
	strcpy(this->str, str);
}

String::String() {
	this->str = nullptr;
	this->length = 0;
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
	this->length = other.length;
	this->str = other.str;
	other.str = nullptr;
}

String& String::operator=(String&& other) {
	if (this != &other) {
		free();

		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
	return *this;
}

char& String::At(unsigned index) {
	if (index >= length) {
		throw "Index too big!";
	}
	return str[index];
}

const char* String::GetPtr() {
	return str;
}
