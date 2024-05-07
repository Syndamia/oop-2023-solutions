#pragma once

class String {
protected:
	char* str;
	unsigned length;

	void free();
	void copyFrom(const String& other);

public:
	String(const char* str);

	String();
	~String();
	String(const String& other);
	String& operator=(const String& other);
	String(String&& other);
	String& operator=(String&& other);

	char& At(unsigned index);
	const char* GetPtr();
};
