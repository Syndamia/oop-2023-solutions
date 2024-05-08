#pragma once
#include "ModifiableString.h"
#include <iostream>

class ShowableString : ModifiableString {
public:
	friend std::ostream& operator<<(std::ostream& ostr, const ShowableString& str);
	friend std::istream& operator>>(std::istream& istr, ShowableString& str);
};
