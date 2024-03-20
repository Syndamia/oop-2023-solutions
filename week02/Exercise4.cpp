struct Material {
	int id;
	int startingType;
	int endingType;
};

struct MaterialArray {
private:
	Material* elems;
	int size;
	int last;

public:
	MaterialArray(int size) {
		this->size = size;
		elems = new Material[size];
		last = 0;
	}

	void Append(const Material& m) {
		if (size == last) return;
		elems[last++] = m;
	}

	int GetSize() {
		return size;
	}

	Material* GetByID(int id) {
		for (int i = 0; i < last; i++) {
			if (elems[i].id == id) {
				return &elems[i];
			}
		}
		return nullptr;
	}

	Material* GetByStartingType(int type) {
		for (int i = 0; i < last; i++) {
			if (elems[i].startingType == type) {
				return &elems[i];
			}
		}
		return nullptr;
	}
};

struct Machine {
private:
	struct MaterialEfficiency {
		int id;
		float percentage;
	};
	MaterialEfficiency *efficiency;
	int knownMaterials;

	int availableThroughput;

public:
	int ConvertMaterial(int materialID, int quantity) {
		if (availableThroughput == 0) {
			return 0;
		}

		int converts = quantity * GetEfficiency(materialID);
		availableThroughput -= converts;
		// Губим материал, понеже машината се е счупила по средата на обработка
		if (availableThroughput < 0) {
			converts += availableThroughput;
			availableThroughput = 0;
		}
		return converts;
	}

	int WillConvert(int materialID, int quantity) {
		if (availableThroughput == 0) {
			return 0;
		}

		int converts = quantity * GetEfficiency(materialID);
		int newThroughput = availableThroughput - converts;
		if (newThroughput < 0) {
			converts += newThroughput;
		}
		return converts;
	}

	void FixFor(int quantity) {
		availableThroughput += quantity;
	}

	float GetEfficiency(int id) {
		for (int i = 0; i < knownMaterials; i++) {
			if (efficiency[i].id == id) {
				return efficiency[i].percentage;
			}
		}
		return 0;
	}
};

MaterialArray& materialPath(MaterialArray& materials, int startid, int endid) {
	MaterialArray* path = new MaterialArray(materials.GetSize());

	Material* current = materials.GetByID(startid);
	path->Append(*current);
	while(current->id != endid) {
		current = materials.GetByStartingType(current->endingType);
		path->Append(*current);
	}

	return *path;
}

MachineArray& bestMachinePath(MaterialArray& mpath) {

}

int main() {
}
