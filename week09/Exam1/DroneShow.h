#include "Drone.h"

class DroneShow {
	char* name; // ок ако има голяма петица и нужните проверки, иначе трябва да е "char name[128]"
	// масив от указатели, ако е nullptr значи няма дрон, иначе има
	// това е по-добра интерпретация от това във всеки дрон да пазим "isEmpty" булева стойност или подобно, понеже
	// пише че на позиция може да *няма* дрон, тоест аргумент е ако има дефолтен дрон пак да кажем, че има
	Drone* drones[1024];

	// Голямата петица не дава директно точки, но отнема
	// Щом имаме динамична памет, тогава ЗАДЪЛЖИТЕЛНО трябва да имаме голяма петица
	void free();
	void copyFrom(const DroneShow& other);
public:
	DroneShow();
	~DroneShow();
	DroneShow(const DroneShow& other);
	DroneShow& operator=(const DroneShow& other);
	DroneShow(DroneShow&& other);
	DroneShow& operator=(DroneShow&& other);

	// +0.15 за метод
	bool isEmpty(int index);
	// +0.50 за конструктор; не са ни дадени ограничения, затова правим възможно най-простия такъв
	DroneShow(const char* name, Drone* drones[1024]);
	// +0.35 за метод
	void play();
};
