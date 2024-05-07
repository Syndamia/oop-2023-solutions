#pragma once
#include "ModifiableString.h"

class SaveableString : ModifiableString {
public:
	void write(const char* fileName);
	void read(const char* fileName);
};
