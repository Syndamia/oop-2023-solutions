#pragma once
#include "Time24.h"

class Time12 : Time24 {
	bool pm;
public:
	Time12(unsigned hours, unsigned minutes, bool pm);
	void Print12();
};
