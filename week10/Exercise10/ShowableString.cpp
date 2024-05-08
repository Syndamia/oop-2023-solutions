#include "ShowableString.h"

std::ostream& operator<<(std::ostream& ostr, const ShowableString& str) {
	return ostr << str.str;
}

std::istream& operator>>(std::istream& istr, ShowableString& str) {
	unsigned size;
	istr >> size;
	str.free();
	str.str = new char[size];
	return istr >> str.str;
}
