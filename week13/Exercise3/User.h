#pragma once

class User {
	void free();
	void copyFrom(const User& other);

protected:
	char *name;
	char *password;
	bool banned;

public:
	User();
	virtual ~User();
	User(const User& other);
	User& operator=(const User& other);
	User(User&& other);
	User& operator=(User&& other);

	bool IsBanned() const;
	const char* GetUsername() const;

	friend class UserModerator;
};
