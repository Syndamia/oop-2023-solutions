#include "Moderator.h"
#include <cstring>
#include <iostream>

void Moderator::free() {
	delete[] signature;
}

void Moderator::copyFrom(const Moderator& other) {
	this->signature = new char[strlen(other.signature) + 1];
	strcpy(this->signature, other.signature);
}

Moderator::Moderator() : User() {
	signature = nullptr;
}

Moderator::~Moderator() {
	free();
}

Moderator::Moderator(const Moderator& other) : User(other) {
	copyFrom(other);
}

Moderator& Moderator::operator=(const Moderator& other) {
	if (this != &other) {
		User::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Moderator::Moderator(Moderator&& other) : User(other) {
	this->signature = other.signature;
	other.signature = nullptr;
}

Moderator& Moderator::operator=(Moderator&& other) {
	if (this != &other) {
		free();
		User::operator=(std::move(other));

		this->signature = other.signature;
		other.signature = nullptr;
	}
	return *this;
}

const char* Moderator::GetSignature() {
	return this->signature;
}
