#include "Location.h"

unsigned Location::size() {
	return (Length() + 1) + sizeof(lattitude) + sizeof(longitude);
}
