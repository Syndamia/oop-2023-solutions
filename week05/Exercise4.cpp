struct Receipt {
private:
	float* prices;
	unsigned allocated;
	unsigned size;

	void resize() {
		allocated *= 2;
		float* morePrices = new float[allocated];
		for (int i = 0; i < size; i++) {
			morePrices[i] = prices[i];
		}
		delete[] prices;
		prices = morePrices;
	}

	void free() {
		delete[] prices;
	}
	void copyFrom(const Receipt& other) {
		this->allocated = other.allocated;
		this->size = other.size;

		this->prices = new float[allocated];
		for (int i = 0; i < size; i++) {
			this->prices[i] = other.prices[i];
		}
	}

public:
	Receipt() {
		allocated = 2;
		size = 0;
		prices = new float[allocated];
	}
	~Receipt() {
		free();
	}
	Receipt(const Receipt& other) {
		copyFrom(other);
	}
	Receipt& operator=(const Receipt& other) {
		if (this != &other) {
			free();
			copyFrom(other);
		}
		return *this;
	}

	void AddItemPrice(float price) {
		if (price < 0.0) return;

		if (this->allocated == this->size) {
			resize();
		}
		this->prices[size++] = price;
	}

	void RemoveItemPrice(unsigned index) {
		if (index >= size) return;

		size--;
		for (int i = index; i < size; i++) {
			this->prices[i] = this->prices[i+1];
		}
	}
};
