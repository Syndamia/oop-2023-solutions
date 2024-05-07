#pragma once

class User {
protected:
	char* name;
	char* password;

	void free();
	void copyFrom(const User& other);

public:
	User();
	~User();
	User(const User& other);
	User& operator=(const User& other);
	User(User&& other);
	User& operator=(User&& other);

	const char* GetName();
	const char* GetPassword();
};
