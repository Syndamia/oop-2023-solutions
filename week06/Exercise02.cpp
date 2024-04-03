#include <cstring>

struct DynamicString {
private:
	char* str;
	unsigned size;

	void free() {
		delete[] str;
	}
	void copyFrom(const DynamicString& other) {
		this->str = new char[other.size];
		strcpy(this->str, other.str);
		this->size = other.size;
	}

public:
	DynamicString() {
		str = nullptr;
		size = 0;
	}
	~DynamicString() {
		free();
	}
	DynamicString(const DynamicString& other) {
		copyFrom(other);
	}
	DynamicString& operator=(const DynamicString& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
};
