#include <iostream>
#include <cstring>

struct Paper {
private:
	char contents[1024];
	unsigned page;

	void copyFrom(const Paper& other) {
		strncpy(this->contents, other.contents, 1024);
		page = other.page + 1;
	}

public:
	Paper(const char* contents) {
		strncpy(this->contents, contents, 1024);
		page = 1;
	}

	Paper(const Paper& other) {
		copyFrom(other);
	}
};

int main() {
	int N;
	std::cin >> N;

	Paper** papers = new Paper*[N];

	char buffer[1024];
	std::cin.ignore();
	std::cin.getline(buffer, 1024);
	papers[0] = new Paper(buffer);
	for (int i = 1; i < N; i++) {
		papers[i] = new Paper(*papers[0]);
	}

	for (int i = 0; i < N; i++) {
		delete papers[i];
	}
	delete[] papers;
}
