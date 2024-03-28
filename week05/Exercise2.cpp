struct FloatArray {
private:
	float* arr;
	unsigned size;

	void free() {
		delete[] arr;
	}
	void copyFrom(const FloatArray& other) {
		this->size = other.size;
		this->arr = new float[size];
		for (int i = 0; i < size; i++) {
			this->arr[i] = other.arr[i];
		}
	}

public:
	FloatArray(unsigned size) {
		this->size = size;
		arr = new float[size];
	}
	~FloatArray() {
		free();
	}
	FloatArray(const FloatArray& other) {
		copyFrom(other);
	}
	FloatArray& operator=(const FloatArray& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	float GetElem(unsigned index) {
		if (index >= size) return 0.0;

		return arr[index];
	}
	void SetElem(unsigned index, float value) {
		if (index >= size) return;

		arr[index] = value;
	}
};
