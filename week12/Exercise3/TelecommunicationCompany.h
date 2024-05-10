#pragma once
#include "MobileDevice.h"

class TelecommunicationCompany {
	MobileDevice** devices;
	unsigned size;
	unsigned allocated;

	void resize();

	void free();
	void copyFrom(const TelecommunicationCompany& other);

public:
	TelecommunicationCompany();
	~TelecommunicationCompany();
	TelecommunicationCompany(const TelecommunicationCompany& other);
	TelecommunicationCompany& operator=(const TelecommunicationCompany& other);
	TelecommunicationCompany(TelecommunicationCompany&& other);
	TelecommunicationCompany& operator=(TelecommunicationCompany&& other);
};
