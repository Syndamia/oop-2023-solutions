#include "WashingMachine.h"
#include <iostream>

void WashingMachine::Print() {
	Electroics::Print();
	std::cout << ' ' << maxLaundryWeight;
}
