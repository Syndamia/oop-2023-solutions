struct Ingredient {
	char name[512];
	float amount;
};

class Recipe {
	Ingredient* ingredients;
	unsigned lastIndex;
	unsigned allocated;

	void resize();
	void free();
	void copyFrom(const Recipe& other);

public:
	Recipe();
	~Recipe();
	Recipe(const Recipe& other);
	Recipe& operator=(const Recipe& other);
	Recipe(Recipe&& other);
	Recipe& operator=(Recipe&& other);

	void AddIngredient(const Ingredient& newIng);
	void RemoveIngredient(const char* name);
};
