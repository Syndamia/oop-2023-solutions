#include "CommunicationPacket.h"

CommunicationPacket::CommunicationPacket(unsigned startAddress, unsigned endAddress) {
	this->startAddress = startAddress;
	this->endAddress = endAddress;
	dataSize = 0;
}

CommunicationPacket::CommunicationPacket() : CommunicationPacket(0, 0) {
}
