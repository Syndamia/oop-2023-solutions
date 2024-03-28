#include <iostream>
#include <random>

int rand(int min, int max) {
	return rand() % max + min;
}

struct WaterMeter {
private:
	double usedWater;

public:
	WaterMeter() {
		usedWater = 0.0;
	}

	void AddWater(double amount) {
		usedWater += amount;
	}
	void Print() {
		std::cout << usedWater;
	}
};

struct Building {
private:
	WaterMeter* meters;
	unsigned size;

	void free() {
		delete[] meters;
	}
	void copyFrom(const Building& other) {
		this->size = other.size;
		this->meters = new WaterMeter[size];
		for (int i = 0; i < size; i++) {
			this->meters[i] = other.meters[i];
		}
	}

public:
	Building(unsigned size) {
		this->size = size;
		meters = new WaterMeter[size];
	}

	Building() {
		meters = nullptr;
		size = 0;
	}
	~Building() {
		free();
	}
	Building(const Building& other) {
		copyFrom(other);
	}
	Building& operator=(const Building& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	void SimulateDay() {
		for (int i = 0; i < size; i++) {
			meters[i].AddWater(rand(0, 999) / 100.0);
		}
	}
	void SimulateMonth() {
		WaterMeter** reports = new WaterMeter*[5];
		for (int i = 0; i < 5; i++) {
			reports[i] = new WaterMeter[size];
		}

		for (int day = 0; day <= 30; day++) {
			SimulateDay();
			if (day % 5 == 0 && day > 0) {
				unsigned reportIndex = day / 5 - 1;
				for (int i = 0; i < size; i++) {
					reports[reportIndex][i] = meters[i];
				}
			}
		}

		for (int meterI = 0; meterI < size; meterI++) {
			for (int reportI = 0; reportI < 5; reportI++) {
				reports[reportI][meterI].Print();
				std::cout << " ";
			}
			std::cout << std::endl;
		}
	}
};
