#pragma once

class CommunicationPacket {
protected:
	unsigned startAddress;
	unsigned endAddress;
	unsigned dataSize;

public:
	CommunicationPacket(unsigned startAddress, unsigned endAddress);
	CommunicationPacket();
};
