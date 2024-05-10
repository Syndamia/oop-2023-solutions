#pragma once
#include "Person.h"
#include "Employee.h"

class Company {
	Employee* employees[128];

public:
	~Company();

	float PaymentDifference();
	void WorkloadByAge();
};
