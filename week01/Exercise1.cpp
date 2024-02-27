#include <iostream>

struct String {
	char* stringPointer;
	int stringSize;
};

String* concatString(const String& str1, const String& str2) {
	String* biggerString = new String;
	biggerString->stringSize = str1.stringSize + str2.stringSize;
	biggerString->stringPointer = new char[biggerString->stringSize + 1]; // + 1 за да запазим и терминиращата нула

	for (int i = 0; i < str1.stringSize; i++) {
		biggerString->stringPointer[i] = str1.stringPointer[i];
	}

	for (int i = 0; i < str2.stringSize; i++) {
		biggerString->stringPointer[str1.stringSize + i] = str2.stringPointer[i];
	}

	biggerString->stringPointer[biggerString->stringSize] = '\0';
	return biggerString;
}

int main() {
	char str1Holder[] = "Hello";
	char str2Holder[] = "World";

	String str1 = { str1Holder, 5 };
	String str2 = { str2Holder, 5 };

	String* conc = concatString(str1, str2);

	std::cout << conc << std::endl;

	delete[] conc->stringPointer;
	delete conc;
}
