#pragma once
#include "MobileDevice.h"

class Pager : public MobileDevice {
	char* fileName;

	void free();
	void copyFrom(const Pager& other);

public:
	Pager();
	~Pager();
	Pager(const Pager& other);
	Pager& operator=(const Pager& other);
	Pager(Pager&& other);
	Pager& operator=(Pager&& other);

	virtual void Show() override;
};
