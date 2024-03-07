#include <iostream>
#include <cstring>

struct Person {
private:
	char* firstName;
	char* lastName;
	unsigned int age;
	char* email;

public:
	Person(const char* firstName, const char* lastName, unsigned int age, const char* email) {
		this->firstName = new char[strlen(firstName)];
		strcpy(this->firstName, firstName);

		this->lastName  = new char[strlen(lastName)];
		strcpy(this->lastName, lastName);

		this->age       = age;

		this->email     = new char[strlen(email)];
		strcpy(this->email, email);
	}

	~Person() {
		delete[] firstName;
		delete[] lastName;
		delete[] email;
	}
};

int main() {
	Person p = Person("John", "Doe", 21, "john.doe@email.com");
}
