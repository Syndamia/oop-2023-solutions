#include <cstring>

struct PhoneBook {
private:
	char** entries; // Масив от указатели char*
	unsigned allocated;
	unsigned size;

	void resize() {
		allocated *= 2;
		char** moreEntries = new char*[allocated];
		for (int i = 0; i < size; i++) {
			moreEntries[i] = entries[i];
		}
		delete[] entries;
		entries = moreEntries;
	}

	void free() {
		for (int i = 0; i < size; i++) {
			delete[] entries[i];
		}
		delete[] entries;
	}
	void copyFrom(const PhoneBook& other) {
		this->allocated = other.allocated;
		this->size = other.size;
		this->entries = new char*[allocated];
		for (int i = 0; i < size; i++) {
			this->entries[i] = new char[strlen(other.entries[i])+1];
			strcpy(this->entries[i], other.entries[i]);
		}
	}

public:
	PhoneBook() {
		entries = nullptr;
		allocated = size = 0;
	}
	~PhoneBook() {
		free();
	}
	PhoneBook(const PhoneBook& other) {
		copyFrom(other);
	}
	PhoneBook& operator=(const PhoneBook& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	void InsertPerson(const char* entry) {
		if (allocated == size) {
			resize();
		}

		int index = 0;
		while (index < size) {
			if (strcmp(entry, entries[index]) < 0) {
				break;
			}
			index++;
		}

		size++;
		for (int i = size; i > index; i--) {
			entries[i] = entries[i-1];
		}
		entries[index] = new char[strlen(entry)+1];
		strcpy(entries[index], entry);
	}
};
