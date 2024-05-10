#pragma once
#include "Message.h"

class Link : public Message {
	char* address;

	void free();
	void copyFrom(const Link& other);

public:
	Link();
	virtual ~Link() override;
	Link(const Link& other);
	Link& operator=(const Link& other);
	Link(Link&& other);
	Link& operator=(Link&& other);

	virtual unsigned size() override;
};
