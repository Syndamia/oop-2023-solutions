#include "ModifiableString.h"

char& ModifiableString::operator[](int index) {
	return str[index];
}

char& ModifiableString::operator[](int index) const {
	return str[index];
}

ModifiableString& ModifiableString::operator+=(const ModifiableString& right) {
	String::operator=(*this + right);
	return *this;
}
