class Street {
	char* name;
	int number;

	void free();
	void copyFrom(const Street& other);

public:
	Street(const char* name, int number);
	void Print();

	Street();
	~Street();
	Street(const Street& other);
	Street& operator=(const Street& other);
	Street(Street&& other);
	Street& operator=(Street&& other);

	void SaveText(const char* fileName);
	void LoadText(const char* fileName);

	void SaveBinary(const char* fileName);
	void LoadBinary(const char* fileName);
};
