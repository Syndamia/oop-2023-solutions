#include "Exercise6.h"
#include <iostream>

NumberInput::NumberInput(int min, int max) {
	std::cout << "Enter number [" << min << ", " << max << "]: ";
	std::cin >> value;
	if (value < min || max < value) {
		throw "Number outside of range!";
	}
}

int NumberInput::GetValue() {
	return value;
}

int main() {
	while(true) {
		try {
			NumberInput a(5, 10);
			std::cout << a.GetValue() * 2 << std::endl;
			break;
		}
		catch (const char* error) {
			std::cout << error << std::endl;
		}
	}
}
