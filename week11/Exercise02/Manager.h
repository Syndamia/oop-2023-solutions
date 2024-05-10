#pragma once
#include "Employee.h"

class Manager : Employee {
	Employee* managedTeam;
	unsigned length;

	void free();
	void copyFrom(const Manager& other);

public:
	Manager();
	~Manager();
	Manager(const Manager& other);
	Manager& operator=(const Manager& other);
	Manager(Manager&& other);
	Manager& operator=(Manager&& other);
};
