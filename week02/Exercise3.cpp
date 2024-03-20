#include <iostream>
#include <random>

/* Решението изглежда странно, идеята на тази задача беше да се упражни употреба на указатели */

int randBetween(int a, int b) {
	return a + rand() % (b + 1);
}

int min(int a, int b) {
	return (a > b) ? a : b;
}

struct Car {
	int row;
	int col;
	int speed;

	Car(int rows, int cols) {
		row = randBetween(0, rows - 1);
		col = randBetween(0, cols - 1);
		speed = randBetween(4, 6);
	}

	int ForwardCol() {
		return row + speed;
	}

	void MoveForward() {
		col += speed;
		if (speed == 0) {
			speed = 1;
		}
		else if (speed < 8) {
			speed = min(8, randBetween(0, 3));
		}
	}

	bool TryCrash(Car& crashWith) {
		if (ForwardCol() < crashWith.col) return false;

		speed /= 2;
		if (ForwardCol() < crashWith.col) return false;

		crashWith.speed = speed = 0;
		col = crashWith.col - 1;
		return true;
	}
};

struct Highway {
private:
	Car** cars; // Динамично-заделен масив от динамично-заделени коли
	int carsSize;
	int carsCount;

	int rows;
	int cols;

	void initCars() {
		for (int i = 0; i < carsSize; i++) {
			cars[i] = new Car(rows, cols);
		}
		carsCount = carsSize;
	}

	Car** getCar(int row, int col) {
		for (int i = 0; i < carsSize; i++) {
			if (cars[i] != nullptr && cars[i]->row == row && cars[i]->col == col) {
				return &cars[i];
			}
		}
		return nullptr;
	}

	bool moveForward(Car& current, int row, int startCol, int endCol) {
		for (int col = startCol + 1; col < endCol; col++) {
			Car** collidesWith = getCar(row, col);
			if (collidesWith != nullptr && current.TryCrash(**collidesWith)) {
				return false;
			}
		}
		current.MoveForward();
		return true;
	}

public:
	Highway(int rows, int cols, int size) {
		this->rows = rows;
		this->cols = cols;
		this->carsSize = this->carsCount = size;
		cars = new Car*[carsSize];
	}
	~Highway() {
		for (int i = 0; i < carsSize; i++) {
			delete cars[i];
		}
		delete[] cars;
	}

	int SimulateStep() {
		int crashes = 0;
		for (int j = cols - 1; j >= 0; j--) {
			for (int i = 0; i < rows; i++) {
				Car** current = getCar(i, j);
				if (current == nullptr) continue;
				crashes += !moveForward(**current, i, j, (*current)->ForwardCol());

				if ((*current)->col >= cols) {
					delete *current;
					*current = nullptr;
					carsCount--;
				}
			}
		}
		return crashes;
	}

	void Simulate() {
		initCars();

		int iterations = 1, crashes = 0;
		while (carsCount > 0) {
			crashes += SimulateStep();
			iterations++;
		}

		std::cout << "Iters: " << iterations << " Crashes: " << crashes << std::endl;
	}
};

int main() {
	Highway h1(1, 10, 10);
	h1.Simulate();
}
