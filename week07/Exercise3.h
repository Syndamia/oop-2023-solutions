class Thermometer {
	unsigned maxMeasurable;
	unsigned minMeasurable;
	unsigned currentTemperature;

public:
	Thermometer(unsigned maxMeasurable, unsigned minMeasurable, unsigned currentTemperature);
	void Print();

	void SaveText(const char* fileName);
	void LoadText(const char* fileName);

	void SaveBinary(const char* fileName);
	void LoadBinary(const char* fileName);
};
