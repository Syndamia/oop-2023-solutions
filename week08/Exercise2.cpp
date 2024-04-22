#include "Exercise2.h"
#include <cstring>
#include <fstream>

void Person::free() {
	delete[] firstName;
	delete[] middleName;
	delete[] lastName;
}

void Person::copyFrom(const Person& other) {
	this->firstName = new char[strlen(other.firstName) + 1];
	strcpy(this->firstName, other.firstName);
	this->middleName = new char[strlen(other.middleName) + 1];
	strcpy(this->middleName, other.middleName);
	this->lastName = new char[strlen(other.lastName) + 1];
	strcpy(this->lastName, other.lastName);

	this->id = other.id;
}

Person::Person() {
	firstName = middleName = lastName = nullptr;
	id = 0;
}

Person::~Person() {
	free();
}

Person::Person(const Person& other) {
	copyFrom(other);
}

Person& Person::operator=(const Person& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Person::Person(Person&& other) {
	this->firstName = other.firstName;
	this->middleName = other.middleName;
	this->lastName = other.lastName;
	other.firstName = other.middleName = other.lastName = nullptr;

	this->id = other.id;
}

Person& Person::operator=(Person&& other) {
	if (this != &other) {
		free();

		this->firstName = other.firstName;
		this->middleName = other.middleName;
		this->lastName = other.lastName;
		other.firstName = other.middleName = other.lastName = nullptr;

		this->id = other.id;
	}
	return *this;
}

void Person::SaveText(const char* outFileName) {
	std::ofstream outFile(outFileName);
	if (!outFile.is_open()) {
		throw "Couldn't open file!";
	}

	outFile << firstName << '\n';
	outFile << middleName << '\n';
	outFile << lastName << '\n';
	outFile << id << '\n';

	outFile.close();
}

void Person::LoadText(const char* inFileName) {
	std::ifstream inFile(inFileName);
	if (!inFile.is_open()) {
		throw "Couldn't open file!";
	}

	free();

	char buffer[1024];

	inFile.getline(buffer, 1024);
	firstName = new char[strlen(buffer) + 1];
	strcpy(firstName, buffer);

	inFile.getline(buffer, 1024);
	middleName = new char[strlen(buffer) + 1];
	strcpy(middleName, buffer);

	inFile.getline(buffer, 1024);
	lastName = new char[strlen(buffer) + 1];
	strcpy(lastName, buffer);

	inFile >> id;

	inFile.close();
}

void Person::SaveBinary(const char* outFileName) {
	std::ofstream outFile(outFileName, std::ios::binary);
	if (!outFile.is_open()) {
		throw "Couldn't open file!";
	}

	int firstNameLen = strlen(firstName);
	int middleNameLen = strlen(middleName);
	int lastNameLen = strlen(lastName);

	outFile.write((const char*)&firstNameLen, sizeof(firstNameLen));
	outFile.write(firstName, sizeof(char) * firstNameLen);

	outFile.write((const char*)&middleNameLen, sizeof(middleNameLen));
	outFile.write(middleName, sizeof(char) * middleNameLen);

	outFile.write((const char*)&lastNameLen, sizeof(lastNameLen));
	outFile.write(lastName, sizeof(char) * lastNameLen);

	outFile.write((const char*)&id, sizeof(id));

	outFile.close();
}

void Person::LoadBinary(const char* inFileName) {
	std::ifstream inFile(inFileName, std::ios::binary);
	if (!inFile.is_open()) {
		throw "Couldn't open file!";
	}

	free();


	int currentLength;

	inFile.read((char*)&currentLength, sizeof(currentLength));
	firstName = new char[currentLength + 1];
	inFile.read(firstName, sizeof(char) * currentLength);
	firstName[currentLength] = '\0';

	inFile.read((char*)&currentLength, sizeof(currentLength));
	middleName = new char[currentLength + 1];
	inFile.read(middleName, sizeof(char) * currentLength);
	middleName[currentLength] = '\0';

	inFile.read((char*)&currentLength, sizeof(currentLength));
	lastName = new char[currentLength + 1];
	inFile.read(lastName, sizeof(char) * currentLength);
	lastName[currentLength] = '\0';

	inFile.read((char*)&id, sizeof(id));

	inFile.close();
}
