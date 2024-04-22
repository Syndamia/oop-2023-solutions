// Помощна структура за метода moveWithOneStep
struct Coordinate {
	double x;
	double y;
};

class Drone {
	// +0.25 За член данни
	char* id;
	char generatedPath[64];
	// Валидна интерпретация е position да бъде индекс, нищо не му противоречи
	int position;

	// +1.25 За голяма петица
	void free();
	void copyFrom(const Drone& other);
public:
	Drone();
	~Drone();
	Drone(const Drone& other);
	Drone& operator=(const Drone& other);
	Drone(Drone&& other);
	Drone& operator=(Drone&& other);

	// +0.50 За метод
	void printGeneratedPath();
	// +0.50 За метод
	Coordinate moveWithOneStep();

	// Помощна за 2.2, метод play
	Coordinate positionAndMove();
	// Помощна за 3.1
	Drone(const char* id, char generatedPath[64], int position);
};
