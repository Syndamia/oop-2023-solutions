#pragma once
#include "MobileDevice.h"

class TelecommunicationCompany {
	MobileDevice** devices;
	unsigned size;
	unsigned allocated;

	void resize();

	void free();

public:
	TelecommunicationCompany();
	~TelecommunicationCompany();
	TelecommunicationCompany(TelecommunicationCompany&& other);
	TelecommunicationCompany& operator=(TelecommunicationCompany&& other);
};
