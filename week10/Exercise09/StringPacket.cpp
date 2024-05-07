#include "StringPacket.h"
#include "CommunicationPacket.h"
#include <cstring>

void StringPacket::free() {
	delete[] data;
}

void StringPacket::copyFrom(const StringPacket& other) {
	this->startAddress = other.startAddress;
	this->endAddress = other.endAddress;
	this->dataSize = other.dataSize;
	this->data = new char[dataSize + 1];
	strcpy(this->data, other.data);
}

StringPacket::StringPacket() : CommunicationPacket() {
	data = nullptr;
}

StringPacket::~StringPacket() {
	free();
}

StringPacket::StringPacket(const StringPacket& other) {
	copyFrom(other);
}

StringPacket& StringPacket::operator=(const StringPacket& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

StringPacket::StringPacket(StringPacket&& other) {
	this->startAddress = other.startAddress;
	this->endAddress = other.endAddress;
	this->dataSize = other.dataSize;
	this->data = other.data;
	other.data = nullptr;
}

StringPacket& StringPacket::operator=(StringPacket&& other) {
	if (this != &other) {
		free();

		this->startAddress = other.startAddress;
		this->endAddress = other.endAddress;
		this->dataSize = other.dataSize;
		this->data = other.data;
		other.data = nullptr;
	}
	return *this;
}

StringPacket::StringPacket(unsigned startAddress, unsigned endAddress, const char* data) : CommunicationPacket(startAddress, endAddress) {
	this->dataSize = strlen(data);
	this->data = new char[dataSize + 1];
	strcpy(this->data, data);
}
