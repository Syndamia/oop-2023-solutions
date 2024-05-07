#pragma once
#include "FN.h"

class ModernFN : public FN {
	char prefix[6];

public:
	ModernFN(const char* fn);
	void PrintNewFN();
};
