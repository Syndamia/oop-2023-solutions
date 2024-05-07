#include <iostream>
#include <fstream>

void firstRow(const char* fileName) {
	std::ifstream inFile(fileName);
	if (!inFile.is_open()) {
		throw "Couldn't open file!";
	}

	while (!inFile.eof() && inFile.peek() != '\n') {
		inFile.get();
	}
	if (inFile.eof()) {
		inFile.seekg(0, std::ios::end);
		unsigned len = inFile.tellg();
		inFile.close();
		throw len;
	}

	inFile.seekg(0, std::ios::beg);
	while (inFile.peek() != '\n') {
		std::cout << inFile.get();
	}

	inFile.close();
}

int main() {
	char buffer[1024];

	while (true) {
		try {
			std::cin.getline(buffer, 1024);
			firstRow(buffer);
		}
		catch (const char* couldntOpen) {
			std::cout << couldntOpen;
		}
		catch (unsigned fileSize) {
			std::cout << "In " << fileSize << " characters, there is now newline!" << std::endl;
			continue;
		}
		break;
	}
}
