#pragma once
#include "Message.h"

class Location : public Message {
	float longitude;
	float lattitude;

public:
	virtual unsigned size() override;
};
