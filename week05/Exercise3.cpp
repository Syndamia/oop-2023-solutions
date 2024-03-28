#include <cstring>

struct Email {
private:
	char address[128];
	char* contents;

	void free() {
		delete[] contents;
	}
	void copyFrom(const Email& other) {
		strcpy(this->address, other.address);

		int contSize = strlen(other.contents);
		this->contents = new char[contSize+1];
		strcpy(this->contents, other.contents);
	}

public:
	Email(char address[128], const char* contents) {
		strcpy(this->address, address);

		int contSize = strlen(contents);
		this->contents = new char[contSize + 1];
		strcpy(this->contents, contents);
	}

	Email() {
		address[0] = '\0';
		contents = nullptr;
	}
	~Email() {
		free();
	}
	Email(const Email& other) {
		copyFrom(other);
	}
	Email& operator=(const Email& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
};
