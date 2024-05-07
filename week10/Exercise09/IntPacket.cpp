#include "IntPacket.h"
#include "CommunicationPacket.h"

IntPacket::IntPacket() : CommunicationPacket() {
	data = 0;
}

IntPacket::IntPacket(unsigned startAddress, unsigned endAddress, int data) : CommunicationPacket(startAddress, endAddress) {
	this->data = data;
	this->dataSize = sizeof(int);
}
