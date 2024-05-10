#include "Publication.h"

std::ostream& operator<<(std::ostream& ostr, const Publication& other) {
	return ostr << "From " << other.authors << " in " << other.journal;
}
