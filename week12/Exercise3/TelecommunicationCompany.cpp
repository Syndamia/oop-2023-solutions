#include "TelecommunicationCompany.h"
#include "MobileDevice.h"
#include "Telephone.h"

void TelecommunicationCompany::resize() {
	allocated *= 2;
	MobileDevice** moreDevices = new MobileDevice*[allocated];
	for (int i = 0; i < size; i++) {
		moreDevices[i] = devices[i];
	}
	delete[] devices;
	devices = moreDevices;
}

void TelecommunicationCompany::free() {
	for (int i = 0; i < size; i++) {
		delete devices[i];
	}
	delete[] devices;
}

void TelecommunicationCompany::copyFrom(const TelecommunicationCompany& other) {
	this->allocated = other.allocated;
	this->size = other.size;
	this->devices = new MobileDevice*[size];
	for (int i = 0; i < size; i++) {
		this->devices[i] = other.devices[i]->clone();
	}
}

TelecommunicationCompany::TelecommunicationCompany() {
	devices = nullptr;
	allocated = size = 0;
}

TelecommunicationCompany::~TelecommunicationCompany() {
	free();
}

TelecommunicationCompany::TelecommunicationCompany(const TelecommunicationCompany& other) {
	copyFrom(other);
}

TelecommunicationCompany& TelecommunicationCompany::operator=(const TelecommunicationCompany& other) {
	if (this != &other) {
		copyFrom(other);
		free();
	}
	return *this;
}

TelecommunicationCompany::TelecommunicationCompany(TelecommunicationCompany&& other) {
	this->size = other.size;
	this->allocated = other.allocated;
	this->devices = other.devices;
	other.devices = nullptr;
}

TelecommunicationCompany& TelecommunicationCompany::operator=(TelecommunicationCompany&& other) {
	if (this != &other) {
		free();

		this->size = other.size;
		this->allocated = other.allocated;
		this->devices = other.devices;
		other.devices = nullptr;
	}
	return *this;
}
