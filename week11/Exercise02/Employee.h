#pragma once

class Employee {
	float paycheck;

protected:
	char name[512];
	char position[128];
	char department[64];

public:
	// Може да имаме полиморфизъм, затова се нуждаем от виртуален деструктор
	// В бъдеще ще използваме = default вместо {}
	virtual ~Employee() {};
};
