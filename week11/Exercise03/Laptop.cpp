#include "Laptop.h"
#include <iostream>

void Laptop::Print() {
	Electroics::Print();
	std::cout << ' ' << screenSize;
}
