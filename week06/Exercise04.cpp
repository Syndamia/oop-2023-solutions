#include <fstream>
#include <iostream>

// Отивайки в края и тръгвайки към началото
void Method1(std::ifstream& file) {
	file.seekg(0, std::ios::end);
	size_t endPos = file.tellg();

	while (!file.fail() && file.peek() != '\n') {
		file.seekg(-1, std::ios::cur);
	}
	file.clear();

	if (file.tellg() > 0) {
		file.seekg(1, std::ios::cur);
	}
	size_t lineLength = endPos - file.tellg() + 1;

	char* buffer = new char[lineLength + 1];
	file.getline(buffer, lineLength);
	buffer[lineLength] = '\0';

	std::cout << buffer << std::endl;

	delete[] buffer;
}

// Започвайки от началото и ходейки към края
void Method2(std::ifstream& file) {
	file.seekg(0, std::ios::end);
	size_t lastIndex = file.tellg();

	file.seekg(0, std::ios::beg);
	size_t lastNewLine = 0;

	while (!file.eof()) {
		if (file.get() == '\n') {
			lastNewLine = file.tellg();
		}
	}
	file.clear();

	file.seekg(lastNewLine, std::ios::beg);
	size_t lineLength = lastIndex - file.tellg() + 1;

	char* buffer = new char[lineLength + 1];
	file.getline(buffer, lineLength);
	buffer[lineLength] = '\0';

	std::cout << buffer << std::endl;

	delete[] buffer;
}

int main() {
	char fileName[1024];
	std::cin.getline(fileName, 1024);

	std::ifstream file(fileName);
	if (!file.is_open()) {
		std::cout << "Couldn't open file!" << std::endl;
		return 1;
	}

	Method1(file);
	Method2(file);

	file.close();
}
