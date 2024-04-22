class StreetList {
	char **streetNames; // динамично-заделен масив от динамично-заделени низове
	int lastUnused;
	int allocated;

	void free();
	void copyFrom(const StreetList& other);

	void resize();

public:
	StreetList();
	~StreetList();
	StreetList(const StreetList& other);
	StreetList& operator=(const StreetList& other);
	StreetList(StreetList&& other);
	StreetList& operator=(StreetList&& other);

	void Add(const char* newString);
};
