struct ResidentialBuilding {
	float apartmentPrice;
	unsigned floors;
	unsigned peoplePerFloor;
	bool hasBasement;
	bool hasAttic;
	bool hasParking;
};

struct CommercialBuilding {
	float shopPrice;
	unsigned parkingFloors;
	unsigned shopFloors;
	unsigned shopsPerFloor;
};

struct City {
private:
	struct ResidentialPair {
		ResidentialBuilding* residential;
		unsigned tenants;
	};
	struct CommercialPair {
		CommercialBuilding* commercial;
		unsigned shops;
	};

	ResidentialPair* residentials;
	int lastResidential;
	CommercialPair*  commercials;
	int lastCommercial;

	// 0  - no building
	// >0 - index from residentials, starting from 1
	// <0 - index from commercials, starting from -1
	int** city;
	int size;

	bool cityFull() {
		return lastResidential == size * size || lastCommercial == size * size;
	}

public:
	City() {
		size = 5;
		lastResidential = lastCommercial = 0;

		city = new int*[size];
		for (int i = 0; i < size; i++) {
			city[i] = new int[size];
			for (int j = 0; j < size; j++) {
				city[i][j] = 0;
			}
		}

		residentials = new ResidentialPair[size * size];
		commercials  = new CommercialPair[size * size];
	}
	~City() {
		for (int i = 0; i < lastResidential; i++) {
			delete residentials[i].residential;
		}
		delete[] residentials;
		for (int i = 0; i < lastCommercial; i++) {
			delete commercials[i].commercial;
		}
		delete[] commercials;
		for (int i = 0; i < size; i++) {
			delete[] city[i];
		}
		delete[] city;
	}

	void BuildResidential(const ResidentialBuilding& rb, unsigned tenants, int coordX, int coordY) {
		if (cityFull() || city[coordX][coordY] != 0) return;

		residentials[lastResidential] = { new ResidentialBuilding(rb), tenants };
		city[coordX][coordY] = lastResidential + 1;
		lastResidential++;
	}

	void BuildCommercial(const CommercialBuilding& cb, unsigned shops, int coordX, int coordY) {
		if (cityFull() || city[coordX][coordY] != 0) return;

		commercials[lastCommercial] = { new CommercialBuilding(cb), shops };
		city[coordX][coordY] = -(lastCommercial + 1);
		lastCommercial++;
	}

	void DemolishBuilding(int coordX, int coordY) {
		int& index = city[coordX][coordY];
		if (index == 0) {
			return;
		}

		if (index > 0) {
			index -= 1;
			delete residentials[index].residential;
			for (int i = index; i < lastResidential - 1; i++) {
				residentials[i] = residentials[i+1];
			}
			lastResidential--;
			residentials[lastResidential] = { nullptr, 0 };
		}
		else {
			index = -index - 1;
			delete commercials[index].commercial;
			for (int i = index; i < lastResidential - 1; i++) {
				commercials[i] = commercials[i+1];
			}
			lastCommercial--;
			commercials[lastCommercial] = { nullptr, 0 };
		}
		index = 0;
	}
};

int main() {
	City city;
	city.BuildResidential({ 10000.0, 6, 7, true, true, false }, 21, 0, 0);
	city.BuildResidential({ 100000.0, 5, 5, false, true, false }, 10, 2, 2);
	city.BuildCommercial({ 12000.0, 0, 2, 1 }, 1, 2, 3);
	city.DemolishBuilding(2, 3);
	city.BuildCommercial({ 130800.0, 2, 5, 4 }, 8, 2, 3);
}
