#pragma once
#include "DynamicArray.hpp"

class String : DynamicArray<char> {
	// Не можем да имаме полиморфно += (виж DynamicArray.hpp), но пак трябва да го имплементираме
	// по някакъв начин.
	virtual DynamicArray& operator+=(const DynamicArray& other) override;

public:
	virtual char& operator[](int index) override;
	virtual const char& operator[](int index) const override;
	String& operator+=(const String& other);
};
