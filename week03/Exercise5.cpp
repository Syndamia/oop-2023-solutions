#include <cstring>

struct Car {
private:
	char* model;
	unsigned int doors;
	unsigned int seats;

public:
	Car() {
		model = nullptr;
		doors = 0;
		seats = 0;
	}
	Car(const char* model, unsigned int doors, unsigned int seats) {
		this->model = nullptr;
		setModel(model);
		setDoors(doors);
		setSeats(seats);
	}
	~Car() {
		delete[] model;
	}

	const char* getModel() {
		return model;
	}
	void setModel(const char* newModel) {
		delete[] model;
		model = new char[strlen(newModel) + 1];
		strcpy(model, newModel);
	}

	unsigned int getDoors() {
		return doors;
	}
	void setDoors(unsigned int newDoorsCount) {
		doors = newDoorsCount;
	}

	unsigned int getSeats() {
		return seats;
	}
	void setSeats(unsigned int newSeatsCount) {
		seats = newSeatsCount;
	}

	void CopyDataTo(Car& destination) {
		destination.setModel(model);
		destination.setDoors(doors);
		destination.setSeats(seats);
	}
};

struct TrafficJam {
private:
	Car* cars;
	int size;
	int lastIndex;

	void resize() {
		Car* newCars = new Car[size * 2];
		for (int i = 0; i < size; i++) {
			cars[i].CopyDataTo(newCars[i]);
		}
		delete[] cars;
		cars = newCars;
		size *= 2;
	}

public:
	TrafficJam() {
		size = 3;
		cars = new Car[size];
		lastIndex = 0;
	}
	~TrafficJam() {
		delete[] cars;
	}

	void AddCar(Car& car) {
		if (lastIndex == size)
			resize();
		car.CopyDataTo(cars[lastIndex++]);
	}
};

int main() {
	TrafficJam tj;

	Car c1("Toyota", 4, 5);
	Car c2("Ferarri", 2, 2);

	tj.AddCar(c1);
	tj.AddCar(c2);
}
