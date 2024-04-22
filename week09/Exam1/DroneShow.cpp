#include "DroneShow.h"
#include <iostream>
#include <cstring>

/* Голяма петица */
void DroneShow::free() {
	delete[] name;
for (int i = 0; i < 1024; i++) {
		delete drones[i];
	}
}
void DroneShow::copyFrom(const DroneShow& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);
	for (int i = 0; i < 1024; i++) {
		drones[i] = new Drone(*other.drones[i]);
	}
}

DroneShow::DroneShow() {
	name = nullptr;
	for (int i = 0; i < 1024; i++) {
		drones[i] = nullptr;
	}
}

DroneShow::~DroneShow() {
	free();
}

DroneShow::DroneShow(const DroneShow& other) {
	copyFrom(other);
}

DroneShow& DroneShow::operator=(const DroneShow& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

DroneShow::DroneShow(DroneShow&& other) {
	this->name = other.name;
	other.name = nullptr;

	for (int i = 0; i < 1024; i++) {
		this->drones[i] = other.drones[i];
		other.drones[i] = nullptr;
	}
}

DroneShow& DroneShow::operator=(DroneShow&& other) {
	if (this != &other) {
		free();

		this->name = other.name;
		other.name = nullptr;

		for (int i = 0; i < 1024; i++) {
			this->drones[i] = other.drones[i];
			other.drones[i] = nullptr;
		}
	}
	return *this;
}

/* Метод от 2.2 */
bool DroneShow::isEmpty(int index) {
	return drones[index] == nullptr;
}

/* Конструктор от 2.2 */
DroneShow::DroneShow(const char* name, Drone* drones[1024]) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	for (int i = 0; i < 1024; i++) {
		this->drones[i] = new Drone(*drones[i]); // Директно извикваме копиращия конструктор
	}
}

/* Метод от 2.2 */
void DroneShow::play() {
	try {
		while(true) { // за всяка стъпка от шоуто
			for (int i = 0; i < 1024; i++) { // за всеки дрон
				if (isEmpty(i)) continue; // правим го за да не пишем код в още къдрави скоби

				// Всички дронове имат еднакъв брой въведени позиции, тоест първият дрон,
				// който се опита да отиде на следваща несъществуваща позиция ще хвърли грешка и това описва
				// края на шоуто
				Coordinate c = drones[i]->positionAndMove();
				std::cout << c.x << ", " << c.y << std::endl;
			}
		}
	}
	catch(const char* error) {
		// Няма какво да правим по условие
	}
}
