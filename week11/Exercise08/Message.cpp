#include "Message.h"
#include <cstring>
#include <iostream>

void Message::free() {
	delete[] textMessage;
}

void Message::copyFrom(const Message& other) {
	this->textMessage = new char[strlen(other.textMessage) + 1];
	strcpy(this->textMessage, other.textMessage);
}

Message::Message() {
	this->textMessage = nullptr;
}

Message::~Message() {
	free();
}

Message::Message(const Message& other) {
	copyFrom(other);
}

Message& Message::operator=(const Message& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Message::Message(Message&& other) {
	this->textMessage = other.textMessage;
	other.textMessage = nullptr;
}

Message& Message::operator=(Message&& other) {
	if (this != &other) {
		free();

		this->textMessage = other.textMessage;
		other.textMessage = nullptr;
	}
	return *this;
}

unsigned Message::Length() {
	return strlen(textMessage);
}

std::ostream& operator<<(std::ostream& ostr, const Message& obj) {
	return ostr << obj.textMessage;
}
