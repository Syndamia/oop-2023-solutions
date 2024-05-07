#include "ModernFN.h"
#include <iostream>
#include <cstring>

ModernFN::ModernFN(const char* fn) : FN(atoi(fn + 5)) {
	strncpy(this->prefix, fn, 5);
	this->prefix[5] = '\0';
}

void ModernFN::PrintNewFN() {
	std::cout << this->prefix;
	PrintOldFN();
}
