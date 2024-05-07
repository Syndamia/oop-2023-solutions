#include "Moderator.h"
#include <cstring>

void Moderator::free() {
	User::free();
	delete[] signature;
}

void Moderator::copyFrom(const Moderator& other) {
	User::copyFrom(other);
	this->signature = new char[strlen(other.signature) + 1];
	strcpy(this->signature, other.signature);
}

Moderator::Moderator() : User() {
	signature = nullptr;
}

Moderator::~Moderator() {
	Moderator::free();
}

Moderator::Moderator(const Moderator& other) {
	Moderator::copyFrom(other);
}

Moderator& Moderator::operator=(const Moderator& other) {
	if (this != &other) {
		Moderator::free();
		Moderator::copyFrom(other);
	}
	return *this;
}

Moderator::Moderator(Moderator&& other) {
	this->name = other.name;
	other.name = nullptr;
	this->password = other.password;
	other.password = nullptr;
	this->signature = other.signature;
	other.signature = nullptr;
}

Moderator& Moderator::operator=(Moderator&& other) {
	if (this != &other) {
		Moderator::free();

		this->name = other.name;
		other.name = nullptr;
		this->password = other.password;
		other.password = nullptr;
		this->signature = other.signature;
		other.signature = nullptr;
	}
	return *this;
}

const char* Moderator::GetSignature() {
	return this->signature;
}
