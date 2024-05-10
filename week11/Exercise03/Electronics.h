#pragma once

class Electronics {
	char model[256];
	float needsVolts;
	float needsAmps;

public:
	virtual ~Electronics() = default;

	virtual void Print();
};
