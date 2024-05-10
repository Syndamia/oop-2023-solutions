#pragma once
#include "MobileDevice.h"

class Telephone : public MobileDevice {
public:
	virtual MobileDevice* clone() override;
	virtual void Show() override;
};
