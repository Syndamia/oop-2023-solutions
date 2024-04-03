#include <fstream>
#include <iostream>

int main() {
	int m, n;
	std::cin >> m >> n;

	char fileName[1024];
	std::cin.ignore();
	std::cin.getline(fileName, 1024);

	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cout << "Couldn't open file!" << std::endl;
		return 1;
	}

	unsigned lineIndex = 1;
	while (!file.eof()) {
		if (file.peek() == '\n') {
			lineIndex = 1;
			file.get();
			std::cout << std::endl;
			continue;
		}

		if (m <= lineIndex && lineIndex <= n) {
			std::cout << (char)file.peek();
		}

		lineIndex++;
		file.get();
	}
	std::cout << std::endl;

	file.close();
}
