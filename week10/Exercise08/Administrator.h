#pragma once
#include "Moderator.h"

class Administrator : public Moderator {
	int* arr;
	unsigned size;
	unsigned allocated;

	void resize();

	void free();
	void copyFrom(const Administrator& other);

public:
	Administrator();
	~Administrator();
	Administrator(const Administrator& other);
	Administrator& operator=(const Administrator& other);
	Administrator(Administrator&& other);
	Administrator& operator=(Administrator&& other);

	void AddID(int value);
	void RemoveID(int value);
};
