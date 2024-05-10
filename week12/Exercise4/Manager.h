#pragma once
#include "Employee.h"
#include "Person.h"

class Manager : public Person, public Employee {
	Person* manages;
	unsigned size;
	unsigned allocated;

	void resize();

	void free();
	void copyFrom(const Manager& other);

public:
	Manager();
	~Manager();
	Manager(const Manager& other);
	Manager& operator=(const Manager& other);
	Manager(Manager&& other);
	Manager& operator=(Manager&& other);

	void StartManaging(Person& newEmp);
	void StopManaging(const Person& oldEmp);

	virtual float Workload() override;
};
