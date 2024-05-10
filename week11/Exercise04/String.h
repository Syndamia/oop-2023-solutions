#pragma once

class String {
	char *str;

	void free();
	void copyFrom(const String& other);

public:
	String();
	virtual ~String();
	String(const String& other);
	String& operator=(const String& other);
	String(String&& other);
	String& operator=(String&& other);

	virtual unsigned Length();
};
