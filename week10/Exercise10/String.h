#pragma once

class String {
protected:
	char* str;

	void free();
	void copyFrom(const String& other);

public:
	String();
	virtual ~String();
	String(const String& other);
	String& operator=(const String& other);
	String(String&& other);
	String& operator=(String&& other);

	friend bool operator==(const String& left, const String& right);
	friend bool operator!=(const String& left, const String& right);
	friend String operator+(const String& left, const String& right);
};
