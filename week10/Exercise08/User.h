#pragma once

class User {
	void free();
	void copyFrom(const User& other);

protected:
	char* name;
	char* password;

public:
	User();
	~User();
	User(const User& other);
	User& operator=(const User& other);
	User(User&& other);
	User& operator=(User&& other);

	const char* GetName();
	void SetName(const char* newName);
	const char* GetPassword();
	void SetPassword(const char* newPassword);
};
