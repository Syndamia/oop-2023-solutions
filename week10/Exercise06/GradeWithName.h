#pragma once
#include "Grade.h"

class GradeWithName : public Grade {
	char* name;

	void free();
	void copyFrom(const GradeWithName& other);

public:
	GradeWithName(unsigned numericValue, const char* name);

	GradeWithName();
	~GradeWithName();
	GradeWithName(const GradeWithName& other);
	GradeWithName& operator=(const GradeWithName& other);
	GradeWithName(GradeWithName&& other);
	GradeWithName& operator=(GradeWithName&& other);
};
