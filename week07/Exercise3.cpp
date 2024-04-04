#include "Exercise3.h"
#include <fstream>
#include <iostream>

/* Public */

Thermometer::Thermometer(unsigned maxMeasurable, unsigned minMeasurable, unsigned currentTemperature) {
	this->maxMeasurable = maxMeasurable;
	this->minMeasurable = minMeasurable;
	this->currentTemperature = currentTemperature;
}

void Thermometer::Print() {
	std::cout << maxMeasurable << " " << minMeasurable << " " << currentTemperature << std::endl;
}

void Thermometer::SaveText(const char* fileName) {
	std::ofstream outFile(fileName);
	if (!outFile.is_open()) {
		return;
	}

	outFile << maxMeasurable << "," << minMeasurable << "," << currentTemperature;
	outFile.close();
}
void Thermometer::LoadText(const char* fileName) {
	std::ifstream inFile(fileName);
	if (!inFile.is_open()) {
		return;
	}

	inFile >> maxMeasurable;
	inFile.ignore();
	inFile >> minMeasurable;
	inFile.ignore();
	inFile >> currentTemperature;
	inFile.close();
}

void Thermometer::SaveBinary(const char* fileName) {
	std::ofstream outFile(fileName, std::ios::binary);
	if (!outFile.is_open()) {
		return;
	}

	outFile.write((const char*)&maxMeasurable, sizeof(maxMeasurable));
	outFile.write((const char*)&minMeasurable, sizeof(minMeasurable));
	outFile.write((const char*)&currentTemperature, sizeof(currentTemperature));
	outFile.close();
}
void Thermometer::LoadBinary(const char* fileName) {
	std::ifstream inFile(fileName, std::ios::binary);
	if (!inFile.is_open()) {
		return;
	}

	inFile.read((char*)&maxMeasurable, sizeof(maxMeasurable));
	inFile.read((char*)&minMeasurable, sizeof(minMeasurable));
	inFile.read((char*)&currentTemperature, sizeof(currentTemperature));
	inFile.close();
}

int main() {
	Thermometer t1(100, 0, 20);
	t1.SaveText("t1.txt");

	Thermometer t2(50, 20, 36);
	t2.SaveBinary("t2.dat");

	Thermometer t3(5, 5, 5);

	t3.LoadText("t1.txt");
	t3.Print();

	t3.LoadBinary("t2.dat");
	t3.Print();
}
