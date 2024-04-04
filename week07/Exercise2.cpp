#include <fstream>
#include <iostream>

int main() {
	char fileName[1024];
	std::cin.getline(fileName, 1024);

	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cout << "Couldn't open file!" << std::endl;
		return -1;
	}

	file.seekg(0, std::ios::end);
	int third = file.tellg() / 3;
	file.seekg(2 * third - 1, std::ios::beg);

	while (third <= file.tellg()) {
		std::cout << (char)file.peek();
		file.seekg(-1, std::ios::cur);
	}

	file.close();
}
