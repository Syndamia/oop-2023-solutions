#include "Person.h"
#include <cstring>

void Person::free() {
	delete[] name;
}

void Person::copyFrom(const Person& other) {
	this->age = other.age;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

Person::Person() {
	this->name = nullptr;
	age = 0;
}

Person::~Person() {
	free();
}

Person::Person(const Person& other) {
	copyFrom(other);
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Person::Person(Person&& other) {
	this->age = other.age;
	this->name = other.name;
	other.name = nullptr;
}

Person& Person::operator=(Person&& other) {
	if (this != &other) {
		free();

		this->age = other.age;
		this->name = other.name;
		other.name = nullptr;
	}
	return *this;
}

bool operator==(const Person& left, const Person& right) {
	return strcmp(left.name, right.name) == 0;
}

bool operator!=(const Person& left, const Person& right) {
	return !(left == right);
}
