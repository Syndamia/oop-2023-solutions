#include "User.h"
#include <cstring>

void User::free() {
	delete[] name;
	delete[] password;
}

void User::copyFrom(const User& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->password = new char[strlen(other.password) + 1];
	strcpy(this->password, other.password);
}

User::User() {
	name = password = nullptr;
}

User::~User() {
	free();
}

User::User(const User& other) {
	copyFrom(other);
}

User& User::operator=(const User& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

User::User(User&& other) {
	this->name = other.name;
	other.name = nullptr;
	this->password = other.password;
	other.password = nullptr;
}

User& User::operator=(User&& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

const char* User::GetName() {
	return this->name;
}

const char* User::GetPassword() {
	return this->password;
}
