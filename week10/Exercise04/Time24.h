#pragma once

class Time24 {
protected:
	unsigned hours;
	unsigned minutes;

public:
	Time24(unsigned hours, unsigned minutes);
	void Print24();
};
