struct Patient {
	unsigned id;
	char name[1024];
};

struct Hospital {
private:
	Patient* patients;
	unsigned maxPatients;
	unsigned lastIndex;

public:
	Hospital(unsigned maxPatients) {
		this->maxPatients = maxPatients;
		patients = new Patient[maxPatients];
		lastIndex = 0;
	}
	~Hospital() {
		delete[] patients;
	}

	void AddPatient(const Patient& newPatient) {
		if (lastIndex == maxPatients) return;
		patients[lastIndex++] = newPatient;
	}

	void RemovePatient(int index) {
		for (int i = index; i < lastIndex - 1; i++) {
			patients[i] = patients[i+1];
		}
		lastIndex--;
	}
};
