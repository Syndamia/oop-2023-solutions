#include "ShowableString.h"

std::ostream& operator<<(std::ostream& ostr, const ShowableString& str) {
	return ostr << str;
}

std::istream& operator>>(std::istream& istr, const ShowableString& str) {
	return istr >> str; // Лошо!
}
