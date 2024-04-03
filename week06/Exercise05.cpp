#include <fstream>
#include <iostream>

int main() {
	char fileName[1024];
	std::cin.getline(fileName, 1024);

	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cout << "Couldn't open file!" << std::endl;
		return 1;
	}

	unsigned lines = 0;
	unsigned words = 0;
	char prev = '\0';

	while (!file.eof()) {
		if (file.peek() == '\n') {
			lines++;
		}
		if ((prev == ' ' || prev == '\t' || prev == '\n') && file.peek() != ' ' && file.peek() != '\t' && file.peek() != '\n') {
			words++;
		}

		prev = file.get();
	}
	file.close();

	std::cout << lines << " " << words << std::endl;
}
