struct Bee {
	float age;
	char type;
};

struct BeeHive {
private:
	Bee* roaming;
	Bee* eggs;

public:
	BeeHive(int roamingCapacity, int eggCapacity) {
		roaming = new Bee[roamingCapacity];
		eggs = new Bee[eggCapacity];
	}
	~BeeHive() {
		delete[] roaming;
		delete[] eggs;
	}
};
