#pragma once

class MobileDevice {
protected:
	unsigned phoneNumber;
	char textMessage[512];

public:
	virtual ~MobileDevice() = default;

	virtual void Show() = 0;
	virtual MobileDevice* clone() = 0;
	bool CanAccept(const char* hyperMessage);
	void Accept(const char* hyperMessage);
};
