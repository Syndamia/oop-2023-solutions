#pragma once
#include "String.h"
#include "IndexArray.h"

class WordString : public String, public IndexArray {
public:
	WordString(const char* str);
};
