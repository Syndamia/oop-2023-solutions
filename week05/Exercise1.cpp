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

	// По принцип логиката трябва да е по-сложна, да се маха пациент по индекс и
	// след това да се изместват останалите, но за целите на задачата това не е нужно
	void RemovePatient() {
		lastIndex--;
	}
};
