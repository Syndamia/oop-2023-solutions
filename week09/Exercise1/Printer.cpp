#include "Printer.h"
#include <cstring>

void Printer::free() {
	delete[] model;
}

void Printer::copyFrom(const Printer& other) {
	this->model = new char[strlen(other.model) + 1];
	strcpy(this->model, other.model);
	this->printedPages = other.printedPages;
}

Printer::Printer() {
	model = nullptr;
	printedPages = 0;
}

Printer::~Printer() {
	free();
}

Printer::Printer(const Printer& other) {
	copyFrom(other);
}

Printer& Printer::operator=(const Printer& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Printer::Printer(Printer&& other) {
	this->model = other.model;
	other.model = nullptr;
	this->printedPages = other.printedPages;
}

Printer& Printer::operator=(Printer&& other) {
	if (this != &other) {
		free();

		this->model = other.model;
		other.model = nullptr;
		this->printedPages = other.printedPages;
	}
	return *this;
}
