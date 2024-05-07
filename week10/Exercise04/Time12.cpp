#include "Time12.h"
#include <iostream>

Time12::Time12(unsigned hours, unsigned minutes, bool pm) : Time24(hours, minutes) {
	this->pm = pm;
}

void Time12::Print12() {
	std::cout << hours << ":" << minutes << " " << (pm ? "PM" : "AM");
}
