#pragma once

class Person {
	char* name;
	unsigned age;

	void free();
	void copyFrom(const Person& other);

public:
	Person();
	virtual ~Person();
	Person(const Person& other);
	Person& operator=(const Person& other);
	Person(Person&& other);
	Person& operator=(Person&& other);

	friend bool operator==(const Person& left, const Person& right);
	friend bool operator!=(const Person& left, const Person& right);
};
