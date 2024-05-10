#include "TextDocument.h"
#include <cstring>

void TextDocument::free() {
	delete[] text;
}

void TextDocument::copyFrom(const TextDocument& other) {
	this->len = other.len;
	this->text = new char[len + 1];
	strcpy(this->text, other.text);
}

TextDocument::TextDocument() {
	this->text = nullptr;
}

TextDocument::~TextDocument() {
	free();
}

TextDocument::TextDocument(const TextDocument& other) {
	copyFrom(other);
}

TextDocument& TextDocument::operator=(const TextDocument& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

TextDocument::TextDocument(TextDocument&& other) {
	this->len = other.len;
	this->text = other.text;
	other.text = nullptr;
}

TextDocument& TextDocument::operator=(TextDocument&& other) {
	if (this != &other) {
		free();

		this->len = other.len;
		this->text = other.text;
		other.text = nullptr;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& ostr, const TextDocument& other) {
	return ostr << other.text;
}
