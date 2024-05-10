#include "Pager.h"
#include <iostream>
#include <cstring>
#include <fstream>

void Pager::free() {
	delete[] fileName;
}

void Pager::copyFrom(const Pager& other) {
	this->fileName = new char[strlen(other.fileName) + 1];
	strcpy(this->fileName, other.fileName);
}

Pager::Pager() {
	this->fileName = nullptr;
}

Pager::~Pager() {
	free();
}

Pager::Pager(const Pager& other) {
	copyFrom(other);
}

Pager& Pager::operator=(const Pager& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Pager::Pager(Pager&& other) {
	this->fileName = other.fileName;
	other.fileName = nullptr;
}

Pager& Pager::operator=(Pager&& other) {
	if (this != &other) {
		free();

		this->fileName = other.fileName;
		other.fileName = nullptr;
	}
	return *this;
}

MobileDevice* Pager::clone() {
	return new Pager(*this);
}

void Pager::Show() {
	std::ofstream outFile(fileName);
	if (!outFile.is_open()) {
		throw "Coudldn't open file!";
	}

	outFile << textMessage << std::endl;

	outFile.close();
}
