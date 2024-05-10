#pragma once
#include "Electronics.h"

class WashingMachine : Electronics {
	unsigned maxLaundryWeight;

public:
	virtual void Print() override;
};
