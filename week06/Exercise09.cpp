#include <cstring>
#include <fstream>
#include <iostream>

struct Person {
private:
	char name[1024];
	unsigned age;

public:
	Person(const char name[1024], unsigned age) {
		strcpy(this->name, name);
		this->age = age;
	}

	const char* GetName() {
		return name;
	}
	unsigned GetAge() {
		return age;
	}

	void Save(const char* fileName) {
		std::ofstream outFile(fileName, std::ios::binary);
		if (!outFile.is_open()) {
			std::cout << "Couldn't open file!" << std::endl;
			return;
		}

		outFile.write((const char*)&age,  sizeof(age));
		outFile.write((const char*)&name, sizeof(name));
		outFile.close();
	}

	void Load(const char* fileName) {
		std::ifstream inFile(fileName, std::ios::binary);
		if (!inFile.is_open()) {
			std::cout << "Couldn't open file!" << std::endl;
			return;
		}

		inFile.read((char*)&age, sizeof(age));
		inFile.read((char*)&name, sizeof(name));
	}
};

int main() {
	Person p1("Jordan", 22);
	p1.Save("ex9.dat");

	Person p2("Michael", 89);
	p2.Load("ex9.dat");

	std::cout << p2.GetName() << " " << p2.GetAge() << std::endl;
}
