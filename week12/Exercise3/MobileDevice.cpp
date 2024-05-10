#include "MobileDevice.h"
#include <cstring>
#include <iostream>

bool MobileDevice::CanAccept(const char* hyperMessage) {
	unsigned msgNumber = atoi(hyperMessage);
	return msgNumber == phoneNumber;
}

void MobileDevice::Accept(const char* hyperMessage) {
	if (!CanAccept(hyperMessage)) {
		throw "Can't accept message!";
	}
	strncpy(textMessage, strchr(hyperMessage, ' ') + 1, 512);
}
