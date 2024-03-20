#include <cstring>

struct TVProgram {
private:
	char name[1024];
	unsigned beginTime;
	unsigned endTime;

	void copyFrom(const TVProgram& other) {
		strncpy(this->name, other.name, 1024);
		this->beginTime = other.beginTime;
		this->endTime = other.endTime;
	}

public:
	TVProgram() {
		name[0] = '\0';
		this->beginTime = this->endTime = 0;
	}

	TVProgram(const char* name, unsigned beginTime, unsigned endTime) {
		strncpy(this->name, name, 1024);
		this->beginTime = beginTime;
		this->endTime = endTime;
	}

	TVProgram(const TVProgram& other) {
		copyFrom(other);
	}

	TVProgram& operator=(const TVProgram& other) {
		if (this != &other) {
			copyFrom(other);
		}
		return *this;
	}
};

struct TVChannel {
private:
	TVProgram* programs;
	unsigned size;
	unsigned lastFreeIndex;

	void free() {
		delete[] programs;
	}

	void resize() {
		TVProgram* biggerArray = new TVProgram[size * 2];
		for (int i = 0; i < size; i++) {
			biggerArray[i] = programs[i]; // По копие, извиква се оператор=
		}
		delete[] programs;
		programs = biggerArray;
		size *= 2;
	}

public:
	TVChannel() {
		size = 1;
		programs = new TVProgram[size];
		lastFreeIndex = 0;
	}
	~TVChannel() {
		free();
	}

	void AddChannel(TVProgram program) { // По копие, извиква се копиращ конструктор
		if (lastFreeIndex == size) {
			resize();
		}

		programs[lastFreeIndex++] = program; // По копие, извиква се оператор=
	}
};

int main() {
	TVChannel fmitv;
	fmitv.AddChannel(TVProgram("Object-oriented programming", 900, 1200));
	fmitv.AddChannel(TVProgram("Geometry", 1315, 1600));
	fmitv.AddChannel(TVProgram("English", 1600, 1755));
}
