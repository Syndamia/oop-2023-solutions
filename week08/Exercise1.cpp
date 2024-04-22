#include "Exercise1.h"
#include <cstring>

void StreetList::free() {
	for (int i = 0; i < lastUnused; i++) {
		delete[] streetNames[i];
	}
	delete[] streetNames;
}

void StreetList::copyFrom(const StreetList& other) {
	this->lastUnused = other.lastUnused;
	this->allocated = other.allocated;

	this->streetNames = new char*[allocated];
	for (int i = 0; i < lastUnused; i++) {
		this->streetNames[i] = new char[strlen(other.streetNames[i]) + 1];
		strcpy(this->streetNames[i], other.streetNames[i]);
	}
}

void StreetList::resize() {
	allocated *= 2;
	char** biggerList = new char*[allocated];
	for (int i = 0; i < lastUnused; i++) {
		// Понеже са указатели в динамичната памет, можем да си спестим new char[] и strcpy
		biggerList[i] = streetNames[i];
	}
	delete[] streetNames;
	streetNames = biggerList;
}

StreetList::StreetList() {
	streetNames = nullptr;
	lastUnused = allocated = 0;
}

StreetList::~StreetList() {
	free();
}

StreetList::StreetList(const StreetList& other) {
	copyFrom(other);
}

StreetList& StreetList::operator=(const StreetList& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

StreetList::StreetList(StreetList&& other) {
	this->streetNames = other.streetNames;
	other.streetNames = nullptr;
	this->lastUnused = other.lastUnused;
	this->allocated = other.allocated;
}

StreetList& StreetList::operator=(StreetList&& other) {
	if (this != &other) {
		free();

		this->streetNames = other.streetNames;
		other.streetNames = nullptr;
		this->lastUnused = other.lastUnused;
		this->allocated = other.allocated;
	}
	return *this;
}

void StreetList::Add(const char* newString) {
	if (lastUnused == allocated) {
		resize();
	}
	streetNames[lastUnused] = new char[strlen(newString) + 1];
	strcpy(streetNames[lastUnused], newString);
	lastUnused++;
}
