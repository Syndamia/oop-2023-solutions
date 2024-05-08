#include <iostream>
#include <fstream>
#include <cstring>
#include "Train.h"
#include "TrainNetwork.h"

void railidToFilename(unsigned railID, char outputFileName[9]) {
	// възползваме се от факта, че най-често int се съставя от четири байта
	strncpy(outputFileName, (char*)&railID, sizeof(char));
	strcat(outputFileName, ".txt");
}

void splitRails(const char* fileName) {
	std::ifstream inFile(fileName, std::ios::binary);
	if (!inFile.is_open()) {
		throw "Couldn't open file!";
	}

	while (!inFile.eof()) {
		unsigned railID;
		inFile.read((char*)&railID, sizeof(railID));
		int regionsCount;
		inFile.read((char*)&regionsCount, sizeof(regionsCount));

		char outputFileName[9];
		railidToFilename(railID, outputFileName);

		std::ofstream outFile(outputFileName);
		if (!outFile.is_open()) {
			throw "Couldn't open file!";
		}

		while (regionsCount > 0) {
			char buffer;
			inFile.read(&buffer, sizeof(buffer));
			outFile.write(&buffer, sizeof(buffer));
			if (buffer == '\n') {
				regionsCount--;
			}
		}

		outFile.close();
	}

	inFile.close();
}

int main() {
	char fileName[1024];
	std::cin.getline(fileName, 1024);

	splitRails(fileName);

	int N;
	std::cin >> N;
	Train trains[512];

	char modelBuffer[128];
	unsigned railID;
	char filenameBuffer[9];
	for (int i = 0; i < N && i < 512; i++) {
		std::cin.ignore();
		std::cin.getline(modelBuffer, 128);
		std::cin >> railID;
		railidToFilename(railID, filenameBuffer);
		trains[i] = Train(modelBuffer, railID, filenameBuffer);
	}

	char tnIdBuffer[8];
	std::cin.ignore();
	std::cin.getline(tnIdBuffer, 8);

	TrainNetwork tn(tnIdBuffer, trains);
	std::cout << tn.RunTrains() << std::endl;
}
