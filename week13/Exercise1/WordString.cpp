#include "WordString.h"

bool isBlank(char ch) {
	return ch == ' ' || ch == '\n' || ch == '\t';
}

WordString::WordString(const char* str) : String(str), IndexArray() {
	this->size = 1;
	for (int i = 1; str[i] != '\0'; i++) {
		if (isBlank(str[i - 1]) && !isBlank(str[i])) {
			this->size++;
		}
	}

	this->indecies = new int[this->size];

	this->indecies[0] = 0;
	unsigned indeciesI = 1;

	for (int i = 1; str[i] != '\0'; i++) {
		if (isBlank(str[i - 1]) && !isBlank(str[i])) {
			indecies[indeciesI++] = i;
		}
	}
}
