#pragma once

class Employee {
	int id;
	float paycheck;
	float efficiency;

public:
	virtual ~Employee() = default;

	virtual float Workload() = 0;

	// Това е за удобство, по-добрия вариант е гетъри и сетъри
	friend class Company;
};
