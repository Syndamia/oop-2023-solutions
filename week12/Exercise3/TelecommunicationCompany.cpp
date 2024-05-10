#include "TelecommunicationCompany.h"
#include "MobileDevice.h"

void TelecommunicationCompany::free() {
	for (int i = 0; i < size; i++) {
		delete devices[i];
	}
	delete[] devices;
}

void TelecommunicationCompany::resize() {
	allocated *= 2;
	MobileDevice** moreDevices = new MobileDevice*[allocated];
	for (int i = 0; i < size; i++) {
		moreDevices[i] = devices[i];
	}
	delete[] devices;
	devices = moreDevices;
}

TelecommunicationCompany::TelecommunicationCompany() {
	devices = nullptr;
	allocated = size = 0;
}

TelecommunicationCompany::~TelecommunicationCompany() {
	free();
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
