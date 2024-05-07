#pragma once
#include "String.h"

class FileString : String {
	String fileName; // Така си спестяваме повторно писане на голяма петица

public:
	FileString(const char* fileName);
	void ChangeAt(unsigned index, char newValue);
};
