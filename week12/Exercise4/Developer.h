#pragma once
#include "Employee.h"
#include "Person.h"

class Developer : public Employee, public Person {
	unsigned countProjects;
	unsigned countProjectsSoonRelease;

public:
	Developer& operator++();
	Developer& operator++(int);
	Developer& operator--();
	Developer& operator--(int);

	virtual float Workload() override;
};
