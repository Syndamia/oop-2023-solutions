#include "Manager.h"

void Manager::resize() {
	allocated *= 2;
	Person* moreManages = new Person[allocated];
	for (int i = 0; i < size; i++) {
		moreManages[i] = manages[i];
	}
	delete[] manages;
	manages = moreManages;
}

void Manager::free() {
	delete[] manages;
}

void Manager::copyFrom(const Manager& other) {
	this->size = other.size;
	this->allocated = other.allocated;
	this->manages = new Person[allocated + 1];
	for (int i = 0; i < size; i++) {
		manages[i] = other.manages[i];
	}
}

Manager::Manager() {
	manages = nullptr;
	size = allocated = 0;
}

Manager::~Manager() {
	free();
}

Manager::Manager(const Manager& other) {
	copyFrom(other);
}

Manager& Manager::operator=(const Manager& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Manager::Manager(Manager&& other) {
	this->allocated = other.allocated;
	this->size = other.size;
	this->manages = other.manages;
	other.manages = nullptr;
}

Manager& Manager::operator=(Manager&& other) {
	if (this != &other) {
		free();

		this->allocated = other.allocated;
		this->size = other.size;
		this->manages = other.manages;
		other.manages = nullptr;
	}
	return *this;
}

void Manager::StartManaging(Person& newEmp) {
	for (int i = 0; i < size; i++) {
		if (manages[i] == newEmp) {
			throw "Person already managed!";
		}
	}

	if (size >= allocated) {
		resize();
	}
	manages[size++] = newEmp;
}

void Manager::StopManaging(const Person& oldEmp) {
	int i;
	for (i = 0; i < size; i++) {
		if (manages[i] == oldEmp) {
			break;
		}
	}
	if (i == size) {
		throw "Not managing employee!";
	}

	for (; i < size - 1; i++) {
		manages[i] = manages[i+1];
	}
	size--;
}

float Manager::Workload() {
	return 0.6 * size;
}
