#pragma once
#include <iostream>

class TextDocument {
	char* text;
	unsigned len;

	void free();
	void copyFrom(const TextDocument& other);

public:
	TextDocument();
	~TextDocument();
	TextDocument(const TextDocument& other);
	TextDocument& operator=(const TextDocument& other);
	TextDocument(TextDocument&& other);
	TextDocument& operator=(TextDocument&& other);

	friend std::ostream& operator<<(std::ostream& ostr, const TextDocument& other);
};
