class Person {
	char* firstName;
	char* middleName;
	char* lastName;
	unsigned id;

	void free();
	void copyFrom(const Person& other);

public:
	Person();
	~Person();
	Person(const Person& other);
	Person& operator=(const Person& other);
	Person(Person&& other);
	Person& operator=(Person&& other);

	void SaveText(const char* outFileName);
	void LoadText(const char* inFileName);
	void SaveBinary(const char* outFileName);
	void LoadBinary(const char* inFileName);
};
