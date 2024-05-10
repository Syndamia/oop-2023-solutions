#pragma once
#include <iostream>

class Message {
	void copyFrom(const Message& other);
	void free();

protected:
	char* textMessage;

public:
	Message();
	virtual ~Message();
	Message(const Message& other);
	Message& operator=(const Message& other);
	Message(Message&& other);
	Message& operator=(Message&& other);

	unsigned Length();
	// Отговорът е не, няма разлика между operator<< на трите класа
	// В условието е казано, че текстовото съобщение се показва на екрана, но не е казано че другите данни се
	friend std::ostream& operator<<(std::ostream& ostr, const Message& obj);

	virtual unsigned size() = 0;
};
