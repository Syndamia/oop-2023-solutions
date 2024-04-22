#include "Drone.h"
#include <cstring>
#include <fstream>
#include <iostream>

/* Голяма четворка */

void Drone::free() {
	delete[] id;
}
void Drone::copyFrom(const Drone& other) {
	id = new char[strlen(other.id) + 1];
	strcpy(id, other.id);
	strcpy(generatedPath, other.generatedPath);
	position = other.position;
}

Drone::Drone() {
	id = nullptr;
	generatedPath[0] = '\0';
	position = 0;
}
Drone::~Drone() {
	free();
}
Drone::Drone(const Drone& other) {
	copyFrom(other);
}
Drone& Drone::operator=(const Drone& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

/* Move семантики */

Drone::Drone(Drone&& other) {
	id = other.id;
	other.id = nullptr;

	strcpy(generatedPath, other.generatedPath);
	position = other.position;
}

Drone& Drone::operator=(Drone&& other) {
	if (this != &other) {
		free();

		id = other.id;
		other.id = nullptr;

		strcpy(generatedPath, other.generatedPath);
		position = other.position;
	}
	return *this;
}

/* Метод от 1.2 */
void Drone::printGeneratedPath() {
	std::ifstream inFile(generatedPath, std::ios::binary);
	if (!inFile.is_open()) {
		throw "Could not open generatedPath!"; // ок е и вместо това да се направи "return;"
	}

	while(!inFile.eof()) {
		double x, y;
		// Не е казано формата на този файл какъв е, затова допускаме най-простия възможен:
		// една голяма последователност от double-и, първия е х1, втория е y1, третия е x2, четвъртия е y2 и так. нат.
		inFile.read((char*)&x, sizeof(x));
		inFile.read((char*)&y, sizeof(y));

		std::cout << x << ", " << y << std::endl;
	}

	inFile.close();
}

/* Метод от 1.2 */
Coordinate Drone::moveWithOneStep() {
	std::ifstream inFile(generatedPath, std::ios::binary);
	if (!inFile.is_open()) {
		throw "Could not open generatedPath!"; // ок е вместо това да бъде "return;"
	}

	double x, y;
	for (int i = 0; i <= position + 1 && !inFile.eof(); i++) {
		inFile.read((char*)&x, sizeof(x));
		inFile.read((char*)&y, sizeof(y));
	}
	// Ако във файла не съществува координат на position+1
	if (inFile.eof()) {
		inFile.close();
		throw "No next position";
	}

	std::cout << x << ", " << y << std::endl;

	position++;
	inFile.close();
	return { x, y }; // Еквивалентно на "return Coordinate({ x, y });"
}

/* Помощна за 2.2, метод play */
// Кодът е почти еднакъв с moveWithOneStep, обаче при moveWithOneStep първо местим и връщаме новата позиция,
// докато тук връщаме сегашната и след това местим
// Хубаво е логиката да се изкара в някаква обща член-функция, но като за контролно така е коректно
Coordinate Drone::positionAndMove() {
	std::ifstream inFile(generatedPath, std::ios::binary);
	if (!inFile.is_open()) {
		throw "Could not open generatedPath!"; // ок е вместо това да бъде "return;"
	}

	double x, y;
	//                   vvvvvvvvvvv ето тук е единствената разлика с moveWithOneStep
	for (int i = 0; i <= position && !inFile.eof(); i++) {
		inFile.read((char*)&x, sizeof(x));
		inFile.read((char*)&y, sizeof(y));
	}
	// Ако във файла не съществува координат на position+1
	if (inFile.eof()) {
		inFile.close();
		throw "No next position";
	}

	std::cout << x << ", " << y << std::endl;

	position++;
	inFile.close();
	return { x, y }; // Еквивалентно на "return Coordinate({ x, y });"
}

/* Помощна за 3.1 */
Drone::Drone(const char* id, char generatedPath[64], int position) {
	this->id = new char[strlen(id)+1];
	strcpy(this->id, id);
	strcpy(this->generatedPath, generatedPath);
	this->position = position;
}
