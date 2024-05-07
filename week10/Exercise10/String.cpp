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
	str = nullptr;
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
}

String& String::operator=(String&& other) {
	if (this != &other) {
		free();

		this->str = other.str;
	}
	return *this;
}

bool operator==(const String& left, const String& right) {
	int i;
	for (i = 0; left.str[i] != '\0' && right.str[i] != '\0'; i++) {
		if (left.str[i] != right.str[i])
			return false;
	}
	return left.str[i] == '\0' && right.str[i] == '\0';
}

bool operator!=(const String& left, const String& right) {
	return !(left == right);
}

String operator+(const String& left, const String& right) {
	String concat;
	concat.str = new char[strlen(left.str) + strlen(right.str) + 1];
	int i;
	for (i = 0; left.str[i] != '\0'; i++) {
		concat.str[i] = left.str[i];
	}
	int j;
	for (j = 0; right.str[j] != '\0'; j++) {
		concat.str[i+j] = right.str[j];
	}
	return concat;
}
