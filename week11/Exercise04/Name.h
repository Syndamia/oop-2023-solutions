#pragma once
#include "String.h"

class Name : public String {
	unsigned nameNumber;

public:
	virtual unsigned Length() override;
};
