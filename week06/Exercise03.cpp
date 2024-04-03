#include <fstream>
#include <iostream>

int main() {
	char fileName[1024];
	std::cin.getline(fileName, 1024);

	std::ofstream file(fileName);
	if (!file.is_open()) {
		std::cout << "Couldn't open file!" << std::endl;
		return 1;
	}

	file << "Hello World!";
	file.close();
}
