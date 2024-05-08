#include "Train.h"
#include <iostream>
#include <cstring>
#include <fstream>

void Train::free() {
	delete[] regionsFileName;
	delete[] currentRegion;
}

void Train::copyFrom(const Train& other) {
	strcpy(this->model, other.model);
	this->railID = other.railID;
	this->regionsFileName = new char[strlen(other.regionsFileName) + 1];
	strcpy(this->regionsFileName, other.regionsFileName);
	this->currentRegion = new char[strlen(other.currentRegion) + 1];
	strcpy(this->currentRegion, other.currentRegion);
}

Train::Train() {
	model[0] = '\0';
	railID = 0;
	regionsFileName = currentRegion = nullptr;
}

Train::~Train() {
	free();
}

Train::Train(const Train& other) {
	copyFrom(other);
}

Train& Train::operator=(const Train& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Train::Train(Train&& other) {
	strcpy(this->model, other.model);
	this->railID = other.railID;

	this->regionsFileName = other.regionsFileName;
	other.regionsFileName = nullptr;
	this->currentRegion = other.currentRegion;
	other.currentRegion = nullptr;
}

Train& Train::operator=(Train&& other) {
	if (this != &other) {
		free();

		strcpy(this->model, other.model);
		this->railID = other.railID;

		this->regionsFileName = other.regionsFileName;
		other.regionsFileName = nullptr;
		this->currentRegion = other.currentRegion;
		other.currentRegion = nullptr;
	}
	return *this;
}

void Train::setCurrentRegion(std::ifstream& inFile) {
	int start = inFile.tellg();
	while (!inFile.eof() && inFile.peek() != '\n') {
		inFile.get();
	}
	if (inFile.eof()) {
		inFile.clear();
		inFile.seekg(0, std::ios::end);
	}

	int length = inFile.tellg();
	this->currentRegion = new char[length + 1];

	inFile.seekg(start, std::ios::beg);
	inFile.getline(this->currentRegion, length);
	this->currentRegion[length] = '\0';
}

Train::Train(const char model[128], unsigned railID, const char* regionsFileName) {
	strcpy(this->model, model);
	this->railID = railID;
	this->regionsFileName = new char[strlen(regionsFileName) + 1];
	strcpy(this->regionsFileName, regionsFileName);

	std::ifstream inFile(regionsFileName);
	if (!inFile.is_open()) {
		throw "Couldn't open regions file!";
	}

	setCurrentRegion(inFile);

	inFile.close();
}

// Обикаля сегашния ред във файла и сравнява всяка буква със съответната от str
// Във всички случаи предвижва inFile напред към следващия ред
bool fileStringEq(std::ifstream& inFile, const char* str) {
	if (inFile.eof()) {
		inFile.close();
		throw -1;
	}

	bool equal = true;
	while (!inFile.eof() && inFile.peek() != '\n') {
		if (inFile.peek() != *str) {
			equal = false;
		}
		inFile.get();
		if (*str != '\0') str++;
	}

	if (!inFile.eof()) {
		inFile.get();
	}
	return equal && *str == '\0';
}

void Train::TransferNextRegion() {
	std::ifstream inFile(regionsFileName);
	if (!inFile.is_open()) {
		throw "Couldn't open regions file!";
	}

	while (!fileStringEq(inFile, currentRegion)) {
	}
	setCurrentRegion(inFile);

	inFile.close();
}

void Train::SwitchRailLine(unsigned railID, const char* regionsFileName) {
	this->railID = railID;
	delete[] this->regionsFileName;

	this->regionsFileName = new char[strlen(regionsFileName) + 1];
	strcpy(this->regionsFileName, regionsFileName);

	std::ifstream inFile(regionsFileName);
	if (!inFile.is_open()) {
		throw "Couldn't open regions file!";
	}

	setCurrentRegion(inFile);

	inFile.close();
}
