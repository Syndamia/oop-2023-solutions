#include "FN.h"
#include <iostream>

FN::FN(unsigned facultyNumber) {
	this->facultyNumber = facultyNumber;
}

void FN::PrintOldFN() {
	std::cout << facultyNumber;
}
