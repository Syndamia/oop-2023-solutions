struct Bus {
	unsigned int passengerCapacity;
	unsigned int mileage;
};

struct BusWarehouse {
private:
	Bus* buses;
	int maxSize;
	int lastIndex;

public:
	BusWarehouse(int maxSize) {
		this->maxSize = maxSize;
		buses = new Bus[maxSize];
		lastIndex = 0;
	}

	~BusWarehouse() {
		delete[] buses;
	}

	void AddBus(const Bus& bus) {
		if (maxSize == lastIndex) return;
		buses[lastIndex++] = bus;
	}
};

int main() {
	Bus b1 = { 20, 100000 };
	Bus b2 = { 50,  90812 };

	BusWarehouse bw = BusWarehouse(2);
	bw.AddBus(b1);
	bw.AddBus(b2);
}
