#include "Exercise4.h"
#include <fstream>
#include <iostream>
#include <cstring>

/* Private */

void Street::free() {
	delete[] name;
}
void Street::copyFrom(const Street& other) {
	this->number = other.number;
	this->name = new char[strlen(other.name)+1];
	strcpy(this->name, other.name);
}

/* Public */

Street::Street(const char* name, int number) {
	this->number = number;
	this->name = new char[strlen(name)+1];
	strcpy(this->name, name);
}

void Street::Print() {
	std::cout << name << " " << number << std::endl;
}

Street::Street() {
	this->name = nullptr;
	this->number = 0;
}
Street::~Street() {
	free();
}
Street::Street(const Street& other) {
	copyFrom(other);
}
Street& Street::operator=(const Street& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
Street::Street(Street&& other) {
	this->name = other.name;
	this->number = other.number;

	other.name = nullptr;
}
Street& Street::operator=(Street&& other) {
	if (this != &other) {
		free();

		this->name = other.name;
		this->number = other.number;

		other.name = nullptr;
	}
	return *this;
}

void Street::SaveText(const char* fileName) {
	std::ofstream outFile(fileName);
	if (!outFile.is_open()) {
		return;
	}

	outFile << number << ',' << name;
	outFile.close();
}
void Street::LoadText(const char* fileName) {
	std::ifstream inFile(fileName);
	if (!inFile.is_open()) {
		return;
	}

	free();

	inFile >> number;
	inFile.ignore();

	unsigned nameStart = inFile.tellg();
	inFile.seekg(0, std::ios::end);
	unsigned nameLen = (unsigned)inFile.tellg() - nameStart + 1;
	inFile.seekg(nameStart, std::ios::beg);

	name = new char[nameLen+1];
	inFile.get(name, nameLen);
	name[nameLen] = '\0';

	inFile.close();
}

void Street::SaveBinary(const char* fileName) {
	std::ofstream outFile(fileName, std::ios::binary);
	if (!outFile.is_open()) {
		return;
	}

	outFile.write((const char*)&number, sizeof(number));
	outFile.write(name, sizeof(char) * (strlen(name)+1));

	outFile.close();
}
void Street::LoadBinary(const char* fileName) {
	std::ifstream inFile(fileName, std::ios::binary);
	if (!inFile.is_open()) {
		return;
	}

	inFile.seekg(0, std::ios::end);
	unsigned nameLen = (unsigned)inFile.tellg() - sizeof(number);
	inFile.seekg(0, std::ios::beg);

	free();

	inFile.read((char*)&number, sizeof(number));
	name = new char[nameLen];
	inFile.read(name, nameLen);

	inFile.close();
}

int main() {
	Street s1("Hollywood Blvd", 13);
	s1.SaveText("s1.txt");

	Street s2("Djeims Baucher", 5);
	s2.SaveBinary("s2.dat");

	Street s3;
	s3.LoadText("s1.txt");
	s3.Print();

	s3.LoadBinary("s2.dat");
	s3.Print();
}
