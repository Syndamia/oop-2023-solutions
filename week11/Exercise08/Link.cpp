#include "Link.h"
#include <cstring>

void Link::free() {
	delete[] textMessage;
	delete[] address;
}

void Link::copyFrom(const Link& other) {
	this->address = new char[strlen(other.address) + 1];
	strcpy(this->address, other.address);
}

Link::Link() : Message() {
	this->address = nullptr;
}

Link::~Link() {
	free();
}

Link::Link(const Link& other) : Message(other) {
	copyFrom(other);
}

Link& Link::operator=(const Link& other) {
	if (this != &other) {
		Message::operator=(other);
		free();
		copyFrom(other);
	}
	return *this;
}

Link::Link(Link&& other) {
	Message::operator=(std::move(other));
	this->address = other.address;
	other.address = nullptr;
}

Link& Link::operator=(Link&& other) {
	if (this != &other) {
		free();

		Message::operator=(std::move(other));
		this->address = other.address;
		other.address = nullptr;
	}
	return *this;
}

unsigned Link::size() {
	return (Length() + 1) + (strlen(address) + 1);
}
