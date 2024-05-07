#pragma once
#include "CommunicationPacket.h"

class IntPacket : CommunicationPacket {
	int data;

public:
	IntPacket();
	IntPacket(unsigned startAddress, unsigned endAddress, int data);
};
