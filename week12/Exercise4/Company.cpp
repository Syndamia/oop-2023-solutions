#include "Company.h"
#include <iostream>

Company::~Company() {
	for (int i = 0; i < 128; i++) {
		delete employees[i];
	}
}

float Company::PaymentDifference() {
	float total = 0, performanced = 0;
	for (int i = 0; i < 128; i++) {
		if (employees[i] == nullptr) continue;

		total += employees[i]->paycheck;
		performanced += employees[i]->paycheck * employees[i]->efficiency;
	}
	return total - performanced;
}
