#include <cstring>

struct Checklist {
private:
	bool checked;
	char* contents;

	Checklist* subchecklists;
	unsigned allocated;
	unsigned size;

	void resize() {
		allocated *= 2;
		Checklist* biggerSubs = new Checklist[allocated];
		for (int i = 0; i < size; i++) {
			biggerSubs[i] = subchecklists[i];
		}
		delete[] subchecklists;
		subchecklists = biggerSubs;
	}

	void free() {
		delete[] contents;
		delete[] subchecklists;
	}
	void copyFrom(const Checklist& other) {
		this->checked = other.checked;

		unsigned contSize = strlen(other.contents);
		this->contents = new char[contSize+1];
		strcpy(this->contents, other.contents);

		this->allocated = other.allocated;
		this->size = other.size;
		this->subchecklists = new Checklist[allocated];
		for (int i = 0; i < size; i++) {
			this->subchecklists[i] = other.subchecklists[i];
		}
	}

public:
	Checklist(const char* contents) {
		checked = false;

		unsigned contSize = strlen(contents);
		this->contents = new char[contSize+1];
		strcpy(this->contents, contents);

		this->allocated = 2;
		this->size = 0;
		this->subchecklists = new Checklist[allocated];
	}

	Checklist() {
		checked = false;
		contents = nullptr;
		subchecklists = nullptr;
		allocated = size = 0;
	}
	~Checklist() {
		free();
	}
	Checklist(const Checklist& other) {
		copyFrom(other);
	}
	Checklist& operator=(const Checklist& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	void AddChecklist(const Checklist& newChecklist) {
		if (allocated == size) {
			resize();
		}
		subchecklists[size++] = newChecklist;
	}
	void RemoveChecklist(unsigned index) {
		if (index >= size) return;

		size--;
		for (int i = index; i < size; i++) {
			subchecklists[i] = subchecklists[i+1];
		}
	}

	void SwapRight(unsigned index) {
		if (index >= size-1) return;

		Checklist temp = subchecklists[index];
		subchecklists[index] = subchecklists[index+1];
		subchecklists[index+1] = temp;
	}
	void SwapLeft(unsigned index) {
		if (index == 0 || index >= size) return;

		Checklist temp = subchecklists[index];
		subchecklists[index] = subchecklists[index-1];
		subchecklists[index-1] = temp;
	}
};
