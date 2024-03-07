#include <iostream>
#include <cstring>

struct Alarm {
private:
	char modelName[1024];
	unsigned int pin;
	float modelRevision;

public:
	const char* getModelName() {
		return modelName;
	}
	void setModelName(const char* newModel) {
		for (int i = 0; newModel[i] != '\0'; i++) {
			if (newModel[i] < 'A' || newModel[i] > 'Z')
				return;
		}

		strcpy(modelName, newModel);
	}

	unsigned int getPin() {
		return pin;
	}
	void setPin(unsigned int newPin) {
		if (newPin > 9999) return;

		pin = newPin;
	}

	float getModelRevision() {
		return modelRevision;
	}
	void setModelRevision(float newRevision) {
		if (newRevision <= 0)
			return;

		modelRevision = newRevision;
	}
};

int main() {
	TODO
}
