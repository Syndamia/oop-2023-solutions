#pragma once
#include "User.h"

class Moderator : public User {
protected:
	char* signature;

	void free();
	void copyFrom(const Moderator& other);

public:
	Moderator();
	~Moderator();
	Moderator(const Moderator& other);
	Moderator& operator=(const Moderator& other);
	Moderator(Moderator&& other);
	Moderator& operator=(Moderator&& other);

	const char* GetSignature();
};
