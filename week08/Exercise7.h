#include <iostream>

class UserError {
	char* className;
	char* propertyName;

	void free();
	void copyFrom(const UserError& other);

	inline static int createdCount = 0;

public:
	UserError();
	~UserError();
	UserError(const UserError& other);
	UserError& operator=(const UserError& other);
	UserError(UserError&& other);
	UserError& operator=(UserError&& other);

	UserError(const char* className, const char* propertyName);

	friend std::ostream& operator<<(std::ostream& ostr, const UserError& right);

	static int GetCreatedCount();
};

class NumberInput {
	int value;

public:
	NumberInput(int min, int max);
	int GetValue();
};
