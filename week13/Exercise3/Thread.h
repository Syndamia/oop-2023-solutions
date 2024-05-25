#pragma once
#include "User.h"

class Thread {
	char** messages;
	unsigned size;
	unsigned allocated;

	void resize();

	void free();
	void copyFrom(const Thread& other);

public:
	Thread();
	virtual ~Thread();
	Thread(const Thread& other);
	Thread& operator=(const Thread& other);
	Thread(Thread&& other);
	Thread& operator=(Thread&& other);

	void PostMessage(const User& poster, const char* message);

	friend class ThreadModerator;
};
