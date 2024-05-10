#pragma once
#include "DynamicArray.hpp"

class Numbers : DynamicArray<int> {
	// Не можем да имаме полиморфно += (виж DynamicArray.hpp), но пак трябва да го имплементираме
	// по някакъв начин.
	virtual DynamicArray& operator+=(const DynamicArray& other) override;

public:
	virtual int& operator[](int index) override;
	virtual const int& operator[](int index) const override;
	Numbers& operator+=(const Numbers& other);
};

