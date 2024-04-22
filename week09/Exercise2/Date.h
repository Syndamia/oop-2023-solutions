#pragma once

class Date {
	unsigned day;
	unsigned month;
	unsigned year;

public:
	Date();
	Date(unsigned day, unsigned month, unsigned year);

	void print();

	void StoreText(const char* outFileName);
	void StoreBinary(const char* outFileName);
	void LoadText(const char* inFileName);
	void LoadBinary(const char* inFileName);
};
