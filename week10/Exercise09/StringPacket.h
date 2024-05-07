#pragma once

#include "CommunicationPacket.h"
class StringPacket : CommunicationPacket {
	char* data;

	void free();
	void copyFrom(const StringPacket& other);

public:
	StringPacket();
	~StringPacket();
	StringPacket(const StringPacket& other);
	StringPacket& operator=(const StringPacket& other);
	StringPacket(StringPacket&& other);
	StringPacket& operator=(StringPacket&& other);

	StringPacket(unsigned startAddress, unsigned endAddress, const char* data);
};
