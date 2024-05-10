#pragma once
#include <iostream>

class Publication {
	char authors[1024];
	char journal[256];

public:
	friend std::ostream& operator<<(std::ostream& ostr, const Publication& other);
	virtual ~Publication() = default;
};
