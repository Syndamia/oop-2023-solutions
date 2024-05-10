#include "Street.h"

unsigned numberLength(unsigned num) {
	if (num == 0) return 1;

	unsigned len = 0;
	while (num != 0) {
		len++;
		num /= 10;
	}

	return len;
}

unsigned Street::Length() {
	return String::Length() + numberLength(streetNumber);
}
