#pragma once
#include <iostream>

class Train {
	char model[128];
	unsigned railID;
	char* regionsFileName;
	char* currentRegion;

	void free();
	void copyFrom(const Train& other);

	void setCurrentRegion(std::ifstream& inFile);

public:
	Train();
	~Train();
	Train(const Train& other);
	Train& operator=(const Train& other);
	Train(Train&& other);
	Train& operator=(Train&& other);

	Train(const char model[128], unsigned railID, const char* regionsFileName);

	void TransferNextRegion();
	void SwitchRailLine(unsigned railID, const char* regionsFileName);

	// Това е за удобство, по-добрия начин е да има get-ъри и set-ъри, но така е по-лесно
	friend class TrainNetwork;
};
