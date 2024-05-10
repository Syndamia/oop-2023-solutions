#include "Developer.h"

Developer& Developer::operator++() {
	++countProjectsSoonRelease;
	return *this;
}
Developer& Developer::operator++(int) {
	countProjects++;
	return *this;
}
Developer& Developer::operator--() {
	--countProjectsSoonRelease;
	return *this;
}
Developer& Developer::operator--(int) {
	countProjects--;
	return *this;
}

float Developer::Workload() {
	return 1.1 * countProjects + 2.3 * countProjectsSoonRelease;
}
