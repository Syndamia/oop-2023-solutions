#include "Exercise5.h"
#include <fstream>
#include <iostream>
#include <cstring>

/* Private */

void TransportTicket::free() {
	delete[] source;
	delete[] destination;
}
void TransportTicket::copyFrom(const TransportTicket& other) {
	this->id = other.id;
	this->source = new char[strlen(other.source)+1];
	strcpy(this->source, other.source);
	this->destination = new char[strlen(other.destination)+1];
	strcpy(this->destination, other.destination);
	this->price = other.price;
}

/* Public */

TransportTicket::TransportTicket(unsigned id, const char* source, const char* destination, float price) {
	this->id = id;
	this->source = new char[strlen(source)+1];
	strcpy(this->source, source);
	this->destination = new char[strlen(destination)+1];
	strcpy(this->destination, destination);
	this->price = price;
}
void TransportTicket::Print() {
	std::cout << id << " " << source << " " << destination << " " << price << std::endl;
}

TransportTicket::TransportTicket() {
	id = price = 0;
	source = destination = nullptr;
}
TransportTicket::~TransportTicket() {
	free();
}
TransportTicket::TransportTicket(const TransportTicket& other) {
	copyFrom(other);
}
TransportTicket& TransportTicket::operator=(const TransportTicket& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
TransportTicket::TransportTicket(TransportTicket&& other) {
	this->id = other.id;
	this->source = other.source;
	this->destination = other.destination;
	this->price = other.price;

	other.source = nullptr;
	other.destination = nullptr;
}
TransportTicket& TransportTicket::operator=(TransportTicket&& other) {
	if (this != &other) {
		free();

		this->id = other.id;
		this->source = other.source;
		this->destination = other.destination;
		this->price = other.price;

		other.destination = nullptr;
		other.source = nullptr;
	}
	return *this;
}

void TransportTicket::SaveText(const char* fileName) {
	std::ofstream outFile(fileName);
	if (!outFile.is_open()) {
		return;
	}

	outFile << id << ',' << source << ',' << destination << ',' << price;
	outFile.close();
}

unsigned distanceUntilComma(std::ifstream& inFile) {
	unsigned start = inFile.tellg();
	while (inFile.peek() != ',') {
		inFile.get();
	}
	unsigned len = (unsigned)inFile.tellg() - start + 1;
	inFile.seekg(start, std::ios::beg);
	return len;
}
void TransportTicket::LoadText(const char* fileName) {
	std::ifstream inFile(fileName);
	if (!inFile.is_open()) {
		return;
	}

	free();

	inFile >> id;
	inFile.ignore();

	unsigned sourceLen = distanceUntilComma(inFile);
	source = new char[sourceLen+1];
	inFile.get(source, sourceLen);
	source[sourceLen] = '\0';

	inFile.ignore();

	unsigned destinationLen = distanceUntilComma(inFile);
	destination = new char[destinationLen+1];
	inFile.get(destination, destinationLen);
	destination[destinationLen] = '\0';

	inFile.ignore();
	inFile >> price;

	inFile.close();
}

void TransportTicket::SaveBinary(const char* fileName) {
	std::ofstream outFile(fileName, std::ios::binary);
	if (!outFile.is_open()) {
		return;
	}

	outFile.write((const char*)&id, sizeof(id));
	outFile.write((const char*)&price, sizeof(price));

	unsigned sourceLen = strlen(source)+1;
	outFile.write((const char*)&sourceLen, sizeof(sourceLen));
	outFile.write(source, sizeof(char) * sourceLen);

	unsigned destinationLen = strlen(destination)+1;
	outFile.write((const char*)&destinationLen, sizeof(destinationLen));
	outFile.write(destination, sizeof(char) * destinationLen);

	outFile.close();
}
void TransportTicket::LoadBinary(const char* fileName) {
	std::ifstream inFile(fileName, std::ios::binary);
	if (!inFile.is_open()) {
		return;
	}

	free();

	inFile.read((char*)&id, sizeof(id));
	inFile.read((char*)&price, sizeof(price));

	unsigned sourceLen = 0;
	inFile.read((char*)&sourceLen, sizeof(sourceLen));
	source = new char[sourceLen+1];
	inFile.read(source, sizeof(char) * sourceLen);

	unsigned destinationLen = 0;
	inFile.read((char*)&destinationLen, sizeof(destinationLen));
	destination = new char[destinationLen+1];
	inFile.read(destination, sizeof(char) * destinationLen);

	inFile.close();
}

int main() {
	TransportTicket t1(193, "Sofia", "Bourgas", 15.50);
	t1.SaveText("t1.txt");

	TransportTicket t2(782, "Sofia", "Plovdiv", 8.99);
	t2.SaveBinary("t2.dat");

	TransportTicket t3;
	t3.LoadText("t1.txt");
	t3.Print();

	t3.LoadBinary("t2.dat");
	t3.Print();
}
