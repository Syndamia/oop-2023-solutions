#include "TrainNetwork.h"
#include <cstring>
#include <fstream>

TrainNetwork::TrainNetwork(const char id[8], Train trains[512]) {
	strcpy(this->id, id);
	for (int i = 0; i < 512; i++) {
		this->trains[i] = trains[i];
		collided[i] = false;
	}
}

bool TrainNetwork::HaveCollided(int index1, int index2) {
	if (trains[index1].railID != trains[index2].railID) {
		return false;
	}
	if (strcmp(trains[index1].currentRegion, trains[index2].currentRegion) != 0) {
		return false;
	}

	// Остава да проверим дали currentRegion е последния ред във файла

	// Допускаме, че за конкретно railID съществува единствен конкретен файл (единствено съдържание)
	std::ifstream regionFile(trains[index1].regionsFileName);
	if (!regionFile.is_open()) {
		throw "Couldn't open region file!";
	}

	// Обикаляме файла от края към началото и сравняваме всяка буква със съответната от сегашния регион
	// Тоест сравняваме последния ред във файла със сегашния
	regionFile.seekg(-1, std::ios::end); // Често текстови редактори слагат едно \n в края на файла, затова го пропускаме
	                                     // Това и да го направите и да не го е все едно
	int regionIndex = strlen(trains[index1].currentRegion) - 1;
	while (!regionFile.fail() && regionFile.peek() != '\n' && regionIndex >= 0) {
		// Щом последния ред (последната локация) се различава от сегашната, то
		// сегашната ще се намира някъде другаде във файла и ще има колизия
		if (regionFile.peek() != trains[index1].currentRegion[regionIndex]) {
			regionFile.close();
			return true;
		}
		regionIndex--;
		regionFile.seekg(-1, std::ios::cur);
	}

	bool lastLineEqualsCurrent = (regionFile.fail() || regionFile.peek() == '\n') && regionIndex == 0;
	regionFile.close();

	return !lastLineEqualsCurrent;
}

int TrainNetwork::RunTrains() {
	bool anyMovedForward = true;
	while (anyMovedForward) {
		anyMovedForward = false;

		for (int i = 0; i < 512; i++) {
			if (collided[i]) continue;

			for (int j = 0; j < 512; j++) {
				if (j == i) continue;

				if (HaveCollided(i, j)) {
					collided[i] = collided[j] = true;
					break;
				}
			}

			if (collided[i]) continue;

			try {
				trains[i].TransferNextRegion();
				anyMovedForward = true;
			}
			catch (int error) {
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 512; i++) {
		sum += collided[i];
	}
	return sum;
}
