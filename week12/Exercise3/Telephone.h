#pragma once
#include "MobileDevice.h"

class Telephone : public MobileDevice {
	virtual MobileDevice* clone() override;
	virtual void Show() override;
};
