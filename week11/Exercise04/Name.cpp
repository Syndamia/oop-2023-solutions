#include "Name.h"

unsigned Name::Length() {
	return String::Length() * nameNumber;
}
