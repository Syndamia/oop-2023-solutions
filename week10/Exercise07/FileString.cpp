#include "FileString.h"
#include <fstream>

FileString::FileString(const char* fileName) : String() {
	this->fileName = fileName; // Конвертиращ конструктор!

	std::ifstream inFile(fileName);
	if (!inFile.is_open()) {
		throw "Couldn't open file!";
	}

	while (!inFile.eof() && inFile.peek() != '\n') {
		inFile.get();
	}

	if (inFile.eof()) {
		inFile.seekg(0, std::ios::end);
		this->length = inFile.peek();
	}
	else {
		this->length = inFile.peek() - 1;
	}

	inFile.seekg(0, std::ios::beg);
	str = new char[this->length + 1];
	inFile.getline(str, this->length);
	str[this->length] = '\0';

	inFile.close();
}

void FileString::ChangeAt(unsigned index, char newValue) {
	std::fstream file(fileName.GetPtr());
	if (!file.is_open()) {
		throw "Couldn't open file!";
	}

	file.seekp(index, std::ios::beg);
	file.put(newValue);
	str[index] = newValue;

	file.close();
}
