#pragma once
#include "Electronics.h"

class Laptop : Electronics {
	float screenSize;

public:
	virtual void Print() override;
};
