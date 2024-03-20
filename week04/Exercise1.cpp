#include <cstring>

struct Smartphone {
private:
	char brand[129];
	char model[513];
	unsigned manufacturingYear;
	float cameraResolution;

public:
	const char* GetBrand() {
		return brand;
	}
	void SetBrand(const char* newValue) {
		if (newValue[0] == '\0' || strlen(newValue) > 128) {
			throw "Brand cannot be empty string or longer than 128 characters!";
		}
		strcpy(brand, newValue);
	}

	const char* GetModel() {
		return model;
	}
	void SetModel(const char* newValue) {
		if (newValue[0] == '\0' || strlen(newValue) > 512) {
			throw "Model cannot be empty string or longer than 512 characters!";
		}
		strcpy(model, newValue);
	}

	unsigned GetManufacturingYear() {
		return manufacturingYear;
	}
	void SetManufacturingYear(unsigned newValue) {
		if (newValue < 2000 || 2024 < newValue) {
			throw "Manufacturing year cannot be before 2000 or after 2024!";
		}
		manufacturingYear = newValue;
	}

	float GetCameraResolution() {
		return cameraResolution;
	}
	void SetCameraResolution(float newValue) {
		if (newValue < 0.0) {
			throw "Camera resolution cannot be negative!";
		}
		cameraResolution = newValue;
	}
};
