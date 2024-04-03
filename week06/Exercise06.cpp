#include <fstream>
#include <iostream>

int main() {
	char fileName1[1024];
	std::cin.getline(fileName1, 1024);
	char fileName2[1024];
	std::cin.getline(fileName2, 1024);

	std::fstream file1(fileName1);
	if (!file1.is_open()) {
		std::cout << "Couldn't open file!" << std::endl;
		return 1;
	}

	std::ifstream file2(fileName2);
	if (!file2.is_open()) {
		std::cout << "Couldn't open file!" << std::endl;
		return 1;
	}

	file1.seekg(0, std::ios::end);
	size_t endIndex       = file1.tellg();
	size_t middleIndex    = endIndex / 2;
	size_t latterHalfSize = endIndex - middleIndex;

	file1.seekg(middleIndex, std::ios::beg);
	char* buffer = new char[latterHalfSize];
	file1.read(buffer, latterHalfSize);
	file1.clear();

	file1.seekp(middleIndex, std::ios::beg);
	while (file2.peek() > -1) {
		file1.put(file2.get());
	}
	file1.write(buffer, latterHalfSize);

	delete[] buffer;

	file1.close();
	file2.close();
}
