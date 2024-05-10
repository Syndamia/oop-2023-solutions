#include "Electronics.h"
#include <iostream>

void Electroics::Print() {
	std::cout << model << ' ' << needsVolts << ' ' << needsAmps;
}
