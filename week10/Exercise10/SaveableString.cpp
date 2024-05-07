#include "SaveableString.h"
#include <cstring>
#include <fstream>

void SaveableString::write(const char* fileName) {
	std::ofstream outFile(fileName);
	if (!outFile.is_open()) {
		throw "Coudln't open file!";
	}

	outFile.write(fileName, sizeof(char) * strlen(str));

	outFile.close();
}

void SaveableString::read(const char* fileName) {
	std::ifstream inFile(fileName);
	if (!inFile.is_open()) {
		throw "Coudln't open file!";
	}

	inFile.seekg(0, std::ios::end);
	unsigned length = inFile.tellg();
	inFile.seekg(0, std::ios::beg);

	free();
	str = new char[length + 1];
	inFile.read(str, sizeof(char) * length);
	str[length] = '\0';

	inFile.close();
}
