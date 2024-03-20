#include <iostream>
#include <cstring>

struct DynamicString {
private:
	char* str;
	int size;

	void copyFrom(const DynamicString& other) {
		this->str = new char[other.size + 1];
		strncpy(this->str, other.str, other.size + 1);
		this->size = other.size;
	}

	void free() {
		delete[] str;
	}

public:
	DynamicString(const char* str) {
		size = strlen(str);
		this->str = new char[size + 1];
		strncpy(this->str, str, size + 1);
	}
	~DynamicString() {
		free();
	}

	DynamicString& operator=(const DynamicString& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	const char* GetStr() {
		return str;
	}
};

int main() {
	DynamicString s1("Hello");
	DynamicString s2("World");
	s1 = s2;
	std::cout << s1.GetStr() << std::endl;
}
