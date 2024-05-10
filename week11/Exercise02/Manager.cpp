#include "Manager.h"

void Manager::free() {
	delete[] managedTeam;
}

void Manager::copyFrom(const Manager& other) {
	this->length = other.length;
	this->managedTeam = new Employee[other.length + 1];
	for (int i = 0; i < length; i++) {
		this->managedTeam[i] = other.managedTeam[i];
	}
}

Manager::Manager() {
	this->managedTeam = nullptr;
	this->length = 0;
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
	this->length = other.length;
	this->managedTeam = other.managedTeam;
	other.managedTeam = nullptr;
}

Manager& Manager::operator=(Manager&& other) {
	if (this != &other) {
		free();

		this->length = other.length;
		this->managedTeam = other.managedTeam;
		other.managedTeam = nullptr;
	}
	return *this;
}
