#include "DroneShow.h"
#include <iostream>
#include <fstream>

/* Относно условието с dronesPath.txt, напълно валидна интерпретация е, че просто
 * пренасяме информация от файл на име dronesPath.txt в друг с име, въведено от потребителя.
 * Друга интерпретация е, че пътищата трябва да се изкарат в различни файлове за всеки дрон, или пък
 * да разширим Drone класа, така че да работи с такъв файл или с директен обект който пази пътя.
 *
 * Всички тези са валидни, ако се зачетете в условието, нищо което е директно казано не противоречи,
 * на вас остава да решите кое искате да имплементирайте.
 * На мен ми се струва, че първото изисква възможно най-малко труд, така че това съм направил.
 */
void dronesPathLogic() {
	std::ifstream inFile("dronesPath.txt");
	if (!inFile.is_open()) return;

	char outName[1024];
	std::cin.getline(outName, 1024);

	std::ofstream outFile(outName, std::ios::binary);
	if (!outFile.is_open()) return;

	while(!inFile.eof()) { // за всеки път в dronesPath.txt
		int currentSize = 0;

		// Намираме дължината на сегашния път
		// Възможно е да го напрваим с оразмеряващ се масив в който пълним всички координати, но това ми се струва повече писане
		int startPos = inFile.peek();
		while (inFile.peek() != '\n' && !inFile.eof()) { // докато не сме стигнали края на пътя
			currentSize++;
			double x, y;
			inFile >> x >> y; // "пропускаме" сегашния координат
		}
		inFile.clear(); // Ако сме стигнали края на файла, fail флагът ще бъде вдигнат, така го сваляме
		inFile.seekg(startPos, std::ios::beg); // Намерили сме дължината, но сега ще трябва да изкараме всички координати

		// Не е казано как трябва да изглежда файла в който пишем, затова правим най-простото нещо:
		// първо пишем дължината на пътя (брой координати) и след това толкова на брой координати
		// Имайки предвид, че е двоичен, не можем да имаме разделител ей-така, за да определим кога
		// един път почва и друг свършва.
		outFile.write((char*)&currentSize, sizeof(currentSize));

		while (inFile.peek() != '\n' && !inFile.eof()) {
			double x, y;
			inFile >> x >> y;
			outFile.write((char*)&x, sizeof(x));
			outFile.write((char*)&y, sizeof(y));
		}
	}

	inFile.close();
	outFile.close();
}

int main() {
	char bufferName[1024], bufferGeneratedPath[1024];
	Drone* drones[1024];

	for (int i = 0; i < 1024; i++) {
		std::cin.getline(bufferName, 1024);
		std::cin.getline(bufferGeneratedPath, 1024);
		int position;
		std::cin >> position;
		std::cin.ignore();

		drones[i] = new Drone(bufferName, bufferGeneratedPath, position);
	}

	dronesPathLogic();

	std::cin.getline(bufferName, 1024);
	DroneShow ds(bufferName, drones);
	ds.play();

	for(int i = 0; i < 1024; i++) {
		delete drones[i];
	}
}
