#include <iostream>
#include <cstring>
#include <cmath>

struct Flight {
	char takeoffCity[1024];
	char landingCity[1024];

	int takeoffTime;
	int landingTime;

	float flightPrice;
};

void sortByTakeoff(Flight* flights, int N) {
	for (int i = 0; i < N-1; i++) {
		for (int j = 0; j < N-1 - i; j++) {
			if (flights[j].takeoffTime > flights[j+1].takeoffTime) {
				Flight temp = flights[j];
				flights[j] = flights[j+1];
				flights[j+1] = temp;
			}
		}
	}
}

/*
 * Подточка а)
 */

void A(Flight* flights, int N) {
	for (int i = 0; i < N; i++) {
		std::cout << flights[i].takeoffCity << " " << flights[i].landingCity << " " << flights[i].flightPrice << std::endl;
	}
}

/*
 * Подточка б), само за най-евтин полет
 * Това решение е по стила на повечето хора
 * Решението за най-кратък полет е написано с абстракция in-mind
 */
double cheapest(Flight* flights, int N, const char destionationCity[1024], int current, bool* visited, int* flightPath, int fpLength) {
	flightPath[0] = current;

	if (strcmp(flights[current].landingCity, destionationCity) == 0) {
		return flights[current].flightPrice;
	}

	visited[current] = true;

	double cheapestPrice = INFINITY;
	int* tempPath = new int[fpLength - 1];

	for (int i = 0; i < N; i++) {
		if (visited[i] == false
		    && flights[current].landingTime < flights[i].takeoffTime
		    && strcmp(flights[current].landingCity, flights[i].takeoffCity) == 0)
		{
			for (int j = 0; j < fpLength - 1; j++) {
				tempPath[j] = -1;
			}
			double flightsPrice = cheapest(flights, N, destionationCity, i, visited, tempPath, fpLength - 1);

			if (flightsPrice < cheapestPrice) {
				cheapestPrice = flightsPrice;
				for (int j = 1; j < fpLength; j++) {
					flightPath[j] = tempPath[j-1];
				}
			}
		}
	}

	delete[] tempPath;
	visited[current] = false;
	return cheapestPrice + flights[current].flightPrice;
}

void B1(Flight* flights, int N, char cityToTakeoff[1024], char cityToLand[1024]) {
	Flight* flightsWithInit = new Flight[N+1];

	strcpy(flightsWithInit[0].landingCity, cityToTakeoff);
	flightsWithInit[0].takeoffTime = 0;
	flightsWithInit[0].landingTime = 0;
	flightsWithInit[0].flightPrice = 0.0;

	for (int i = 0; i < N; i++) {
		flightsWithInit[i+1] = flights[i];
	}

	bool* visited = new bool[N+1]{ false };
	int* flightPath = new int[N+1]{ -1 };

	cheapest(flightsWithInit, N+1, cityToLand, 0, visited, flightPath, N+1);

	std::cout << "Cheapest" << std::endl;
	for (int i = 1; i <= N; i++) {
		if (flightPath[i] > -1) {
			std::cout << flightsWithInit[flightPath[i]].takeoffCity << " "
			          << flightsWithInit[flightPath[i]].landingCity << " "
			          << flightsWithInit[flightPath[i]].takeoffTime << " "
			          << flightsWithInit[flightPath[i]].flightPrice << std::endl;
		}
	}

	delete[] flightPath;
	delete[] visited;
	delete[] flightsWithInit;
}

/*
 * Подточка б), само за най-евтин полет
 * Решено с абстракция, тоест с една камара помощни функции и структури
 */

Flight newFlight(const char takeoffCity[1024], const char landingCity[1024], int takeoffTime, int landingTime, float flightPrice) {
	Flight nf;
	strcpy(nf.takeoffCity, takeoffCity);
	strcpy(nf.landingCity, landingCity);
	nf.takeoffTime = takeoffTime;
	nf.landingTime = landingTime;
	nf.flightPrice = flightPrice;
	return nf;
}
bool flightLandsOn(const Flight& fl, const char* city) {
	return strcmp(fl.landingCity, city) == 0;
}
bool flightsCanConnect(const Flight& fl1, const Flight& fl2) {
	return fl1.landingTime < fl2.takeoffTime
	       && strcmp(fl1.landingCity, fl2.takeoffCity) == 0;
}
int flightDuration(const Flight& fl) {
	return fl.landingTime - fl.takeoffTime;
}
int flightsInbetweenTime(const Flight& fl1, const Flight& fl2) {
	return fl2.takeoffTime - fl1.landingTime;
}

struct FlightPath {
	int* flightsIndecies;
	int length;
	int rightmostFreeInd;
};
FlightPath newFlightPath(int size) {
	return { new int[size], size, 0 };
}
void freeFlightPath(FlightPath& fp) {
	delete[] fp.flightsIndecies;
}
void clearFlightPath(FlightPath& fp) {
	for (int i = 0; i < fp.length; i++) {
		fp.flightsIndecies[i] = -1;
	}
}
void copyFlightPath(FlightPath& destination, int start, const FlightPath& source) {
	if (start < 0) return;

	for (int i = 0; i + start < destination.length && i < source.length; i++) {
		destination.flightsIndecies[i + start] = source.flightsIndecies[i];
	}
}
void addToFlightPath(FlightPath& fp, int index) {
	if (fp.rightmostFreeInd == fp.length) return;
	fp.flightsIndecies[fp.rightmostFreeInd++] = index;
}
void printFlightPath(const FlightPath& fp, int start, const Flight* flights) {
	for (int i = start; i < fp.length; i++) {
		if (fp.flightsIndecies[i] > -1) {
			std::cout << flights[fp.flightsIndecies[i]].takeoffCity << " "
			          << flights[fp.flightsIndecies[i]].landingCity << " "
			          << flights[fp.flightsIndecies[i]].takeoffTime << " "
			          << flights[fp.flightsIndecies[i]].flightPrice << std::endl;
		}
	}
}

struct FlightsArray {
	Flight* flights;
	int length;
	int rightmostFreeInd;
};
FlightsArray newFlightArray(int size) {
	return { new Flight[size], size };
}
void freeFlightArray(FlightsArray& fa) {
	delete[] fa.flights;
}
void copyToFlightsArray(FlightsArray& fa, int start, const Flight* flights, int N) {
	for (int i = 0; i + start < fa.length && i < N; i++) {
		fa.flights[i + start] = flights[i];
	}
}
void addToFlightsArray(FlightsArray& fa, const Flight& f) {
	if (fa.length == fa.rightmostFreeInd) return;
	fa.flights[fa.rightmostFreeInd++] = f;
}

double shortest(const FlightsArray& fa, const char destinationCity[1024], int current, bool* visited, FlightPath& bestPath) {
	addToFlightPath(bestPath, current);

	if (flightLandsOn(fa.flights[current], destinationCity)) {
		return flightDuration(fa.flights[current]);
	}

	visited[current] = true;

	double shortestDur = INFINITY;
	FlightPath currentPath = newFlightPath(bestPath.length - 1);

	for (int i = 0; i < fa.length; i++) {
		if (visited[i] == false && flightsCanConnect(fa.flights[current], fa.flights[i]))
		{
			clearFlightPath(currentPath);
			double flightsDur = shortest(fa, destinationCity, i, visited, currentPath)
			                    + flightsInbetweenTime(fa.flights[current], fa.flights[i]);

			if (flightsDur < shortestDur) {
				shortestDur = flightsDur;
				copyFlightPath(bestPath, 1, currentPath);
			}
		}
	}

	freeFlightPath(currentPath);
	visited[current] = false;

	return shortestDur + flightDuration(fa.flights[current]);
}

void B2(Flight* flights, int N, char cityToTakeoff[1024], char cityToLand[1024]) {
	FlightsArray flightsWithInit = newFlightArray(N+1);
	addToFlightsArray(flightsWithInit, newFlight("", cityToTakeoff, 0, 0, 0.0));

	copyToFlightsArray(flightsWithInit, 1, flights, N);

	bool* visited = new bool[N+1]{ false };
	FlightPath shortestPath = newFlightPath(N+1);

	shortest(flightsWithInit, cityToLand, 0, visited, shortestPath);

	std::cout << "Shortest" << std::endl;
	printFlightPath(shortestPath, 1, flightsWithInit.flights);

	freeFlightPath(shortestPath);
	freeFlightArray(flightsWithInit);
	delete[] visited;
}

int main() {
	int N;
	std::cin >> N;

	Flight* flights = new Flight[N];
	for (int i = 0; i < N; i++) {
		std::cin >> flights[i].takeoffCity
		         >> flights[i].landingCity
		         >> flights[i].takeoffTime
		         >> flights[i].landingTime
		         >> flights[i].flightPrice;
	}
	sortByTakeoff(flights, N);

	char cityToTakeoff[1024];
	char cityToLand[1024];
	std::cin >> cityToTakeoff >> cityToLand;

	A(flights, N);
	B1(flights, N, cityToTakeoff, cityToLand);
	B2(flights, N, cityToTakeoff, cityToLand);

	delete[] flights;
}
