class Printer {
	char* model;
	unsigned printedPages;

	void free();
	void copyFrom(const Printer& other);

public:
	Printer();
	~Printer();
	Printer(const Printer& other);
	Printer& operator=(const Printer& other);
	Printer(Printer&& other);
	Printer& operator=(Printer&& other);
};
