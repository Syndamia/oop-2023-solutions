#pragma once
#include "Train.h"

class TrainNetwork {
	char id[8];
	Train trains[512];
	bool collided[512];

public:
	TrainNetwork(const char id[8], Train trains[512]);
	bool HaveCollided(int index1, int index2);
	int RunTrains();
};
