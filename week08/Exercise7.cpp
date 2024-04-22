#include "Exercise7.h"
#include <cstring>

void UserError::free() {
	delete[] className;
	delete[] propertyName;
}

void UserError::copyFrom(const UserError& other) {
	this->className = new char[strlen(other.className) + 1];
	strcpy(this->className, other.className);
	this->propertyName = new char[strlen(other.propertyName) + 1];
	strcpy(this->propertyName, other.propertyName);
}

UserError::UserError() {
	className = propertyName = nullptr;
	createdCount++;
}

UserError::~UserError() {
	free();
}

UserError::UserError(const UserError& other) {
	copyFrom(other);
	createdCount++;
}

UserError& UserError::operator=(const UserError& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

UserError::UserError(UserError&& other) {
	this->className = other.className;
	other.className = nullptr;
	this->propertyName = other.propertyName;
	other.propertyName = nullptr;
}

UserError& UserError::operator=(UserError&& other) {
	if (this != &other) {
		free();

		this->className = other.className;
		other.className = nullptr;
		this->propertyName = other.propertyName;
		other.propertyName = nullptr;
	}
	return *this;
}

UserError::UserError(const char* className, const char* propertyName) {
	this->className = new char[strlen(className) + 1];
	strcpy(this->className, className);
	this->propertyName = new char[strlen(propertyName) + 1];
	strcpy(this->propertyName, propertyName);
	createdCount++;
}

std::ostream& operator<<(std::ostream& ostr, const UserError& right) {
	return ostr << "Invalid user info in class " << right.className << " at " << right.propertyName << "!" << std::endl;
}

int UserError::GetCreatedCount() {
	return createdCount;
}

NumberInput::NumberInput(int min, int max) {
	std::cout << "Enter number [" << min << ", " << max << "]: ";
	std::cin >> value;
	if (value < min || max < value) {
		throw UserError("NumberInput", "constructor");
	}
}

int NumberInput::GetValue() {
	return value;
}

int main() {
	while(true) {
		try {
			NumberInput a(5, 10);
			std::cout << a.GetValue() * 2 << std::endl;
			break;
		}
		catch (const UserError& error) {
			std::cout << error;
		}
	}
	std::cout << UserError::GetCreatedCount() << std::endl;
}
