#include "Date.h"
#include <iostream>
#include <fstream>

Date::Date() {
	day = month = year = 0;
}

Date::Date(unsigned day, unsigned month, unsigned year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::print() {
	std::cout << day << " " << month << " " << year << std::endl;
}

void Date::StoreText(const char* outFileName) {
	std::ofstream outFile(outFileName, std::ios::app);
	if (!outFile.is_open()) {
		throw "Couldn't open file!";
	}

	outFile << year << " " << month << " " << day << std::endl;

	outFile.close();
}

void Date::StoreBinary(const char* outFileName) {
	std::ofstream outFile(outFileName, std::ios::binary | std::ios::app);
	if (!outFile.is_open()) {
		throw "Couldn't open file!";
	}

	outFile.write((const char*)&year, sizeof(year));
	outFile.write((const char*)&month, sizeof(month));
	outFile.write((const char*)&day, sizeof(day));

	outFile.close();
}

void Date::LoadText(const char* inFileName) {
	std::fstream file(inFileName, std::ios::in | std::ios::out);
	if (!file.is_open()) {
		throw "Couldn't open file!";
	}

	file >> year >> month >> day;

	while (!file.fail()) {
		file.put(' ');
		file.seekg(-2, std::ios::cur);
	}
	file.clear();

	file.close();
}

void Date::LoadBinary(const char* inFileName) {
	std::ifstream inFile(inFileName);
	if (!inFile.is_open()) {
		throw "Couldn't open file!";
	}

	inFile.read((char*)&year, sizeof(year));
	inFile.read((char*)&month, sizeof(month));
	inFile.read((char*)&day, sizeof(day));

	inFile.close();
}
