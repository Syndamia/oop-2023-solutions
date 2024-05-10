#pragma once
#include "Electronics.h"

class Camera : Electronics {
	float resolution;

public:
	virtual void Print() override;
};
