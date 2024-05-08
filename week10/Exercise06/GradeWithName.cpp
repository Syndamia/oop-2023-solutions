#include "GradeWithName.h"
#include "Grade.h"
#include <cstring>

void GradeWithName::free() {
	delete[] name;
}

void GradeWithName::copyFrom(const GradeWithName& other) {
	this->numericValue = other.numericValue;
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

GradeWithName::GradeWithName(unsigned numericValue, const char* name) : Grade(numericValue) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

GradeWithName::~GradeWithName() {
	free();
}

GradeWithName::GradeWithName(const GradeWithName& other) : Grade(other) {
	copyFrom(other);
}

GradeWithName& GradeWithName::operator=(const GradeWithName& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

GradeWithName::GradeWithName(GradeWithName&& other) : Grade(other.numericValue) {
	this->name = other.name;
	other.name = nullptr;
}

GradeWithName& GradeWithName::operator=(GradeWithName&& other) {
	if (this != &other) {
		free();

		this->numericValue = other.numericValue;
		this->name = other.name;
		other.name = nullptr;
	}
	return *this;
}
