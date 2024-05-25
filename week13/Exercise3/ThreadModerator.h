#pragma once
#include "User.h"
#include "Thread.h"

class ThreadModerator : virtual public User {
public:
	void RemoveMessage(Thread& thread, unsigned index);
	void RemoveByUser(Thread& thread, const User& poster);
};
