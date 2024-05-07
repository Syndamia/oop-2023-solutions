#include "Time24.h"
#include <iostream>

void Time24::Print24() {
	std::cout << hours << ":" << minutes;
}

Time24::Time24(unsigned hours, unsigned minutes) {
	this->hours = hours;
	this->minutes = minutes;
}
