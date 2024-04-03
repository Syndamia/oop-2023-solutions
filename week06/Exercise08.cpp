#include <fstream>

struct FileBuffer {
private:
	char* data;
	size_t size;

	void free() {
		delete[] data;
	}
	void copyFrom(const FileBuffer& other) {
		this->size = other.size;
		this->data = new char[size];
		for (int i = 0; i < size; i++) {
			this->data[i] = other.data[i];
		}
	}

public:
	FileBuffer(const char* fileName) {
		std::ifstream file(fileName);
		if (!file.is_open()) {
			throw "Couldn't open file!";
		}

		file.seekg(0, std::ios::end);
		size = file.tellg();
		data = new char[size];

		file.seekg(0, std::ios::beg);
		file.read(data, size);

		file.close();
	}

	FileBuffer() {
		data = nullptr;
		size = 0;
	}
	~FileBuffer() {
		free();
	}
	FileBuffer(const FileBuffer& other) {
		copyFrom(other);
	}
	FileBuffer& operator=(const FileBuffer& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}
};
