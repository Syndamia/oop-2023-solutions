#include <iostream>

struct Lightbulb {
	int diameter;
	int length;
	char type[100];
	char series;
};

int main() {
	Lightbulb lb = { 5, 10, "Fluorescent", 'A' };
}
