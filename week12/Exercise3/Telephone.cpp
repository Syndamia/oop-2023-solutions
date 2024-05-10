#include "Telephone.h"
#include <iostream>

MobileDevice* Telephone::clone() {
	return new Telephone(*this);
}

void Telephone::Show() {
	std::cout << textMessage << std::endl;
}
