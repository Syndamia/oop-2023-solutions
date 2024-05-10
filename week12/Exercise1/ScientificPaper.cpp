#include "ScientificPaper.h"

std::ostream& operator<<(std::ostream& ostr, const ScientificPaper& other) {
	return ostr << (Publication)other << std::endl << (TextDocument)other;
}
