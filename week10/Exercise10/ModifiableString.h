#pragma once
#include "String.h"

class ModifiableString : protected String {
public:
	char& operator[](int index);
	char& operator[](int index) const;
	ModifiableString& operator+=(const ModifiableString& right);
};
