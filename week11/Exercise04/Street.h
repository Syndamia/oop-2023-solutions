#pragma once
#include "String.h"

class Street : public String {
	unsigned streetNumber;

public:
	virtual unsigned Length() override;
};
