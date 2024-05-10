#pragma once
#include "Publication.h"
#include "TextDocument.h"
#include <iostream>

class ScientificPaper : Publication, public TextDocument {
	char discipline[512];

public:
	friend std::ostream& operator<<(std::ostream& ostr, const ScientificPaper& other);
	virtual ~ScientificPaper() = default;
};
