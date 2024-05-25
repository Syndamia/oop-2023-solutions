#include "Thread.h"
#include <cstring>

void Thread::resize() {
	this->allocated *= 2;
	char** moreMessages = new char*[this->allocated];
	for (int i = 0; i < this->size; i++) {
		moreMessages[i] = this->messages[i];
	}
	delete[] this->messages;
	this->messages = moreMessages;
}

void Thread::free() {
	for (int i = 0; i < size; i++) {
		delete[] messages[i];
	}
	delete[] messages;
}

void Thread::copyFrom(const Thread& other) {
	this->size = other.size;
	this->allocated = other.allocated;
	this->messages = new char*[allocated];
	for (int i = 0; i < size; i++) {
		this->messages[i] = new char[strlen(other.messages[i] + 1)];
		strcpy(this->messages[i], other.messages[i]);
	}
}

Thread::Thread() {
	this->messages = nullptr;
	this->size = this->allocated = 0;
}

Thread::~Thread() {
	free();
}

Thread::Thread(const Thread& other) {
	copyFrom(other);
}

Thread& Thread::operator=(const Thread& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Thread::Thread(Thread&& other) {
	this->size = other.size;
	this->allocated = other.allocated;
	this->messages = other.messages;
	other.messages = nullptr;
}

Thread& Thread::operator=(Thread&& other) {
	if (this != &other) {
		free();

		this->size = other.size;
		this->allocated = other.allocated;
		this->messages = other.messages;
		other.messages = nullptr;
	}
	return *this;
}

void Thread::PostMessage(const User& poster, const char* message) {
	if (poster.IsBanned()) {
		throw "User cannot post!";
	}
	if (this->size == this->allocated) {
		resize();
	}

	char* newMessage = new char[strlen(poster.GetUsername()) + 1 + strlen(message) + 1];
	strcpy(newMessage, poster.GetUsername());
	strcat(newMessage, " "); // За да знаем къде свършва потребителското име
	strcat(newMessage, message);

	this->messages[this->size++] = newMessage;
}
