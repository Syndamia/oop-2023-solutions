#include <iostream>

struct Packet {
	int time;
	int temperature;
	int pressure;
	int humidity;
	int elevation;
};

void sortByTime(Packet* data, int N) {
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N-1 - i; j++) {
			if (data[j].time > data[j+1].time) {
				Packet temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
}

int getValue(const Packet& packet, char specifier) {
	switch (specifier) {
		case 't': return packet.temperature;
		case 'p': return packet.pressure;
		case 'h': return packet.humidity;
		case 'e': return packet.elevation;
	}
	return 0;
}

int main() {
	int N;
	std::cin >> N;

	Packet* data = new Packet[N];
	for (int i = 0; i < N; i++) {
		std::cin >> data[i].time
		         >> data[i].temperature
		         >> data[i].pressure
		         >> data[i].humidity
		         >> data[i].elevation;
	}

	char wantedValue;
	std::cin >> wantedValue;

	sortByTime(data, N);
	std::cout << getValue(data[0], wantedValue);

	for (int i = 1; i < N; i++) {
		std::cout << " " << (getValue(data[i], wantedValue) - getValue(data[0], wantedValue));
	}
	std::cout << std::endl;

	delete[] data;
}
