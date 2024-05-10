#pragma once

class Electroics {
	char model[256];
	float needsVolts;
	float needsAmps;

public:
	virtual void Print();
};
