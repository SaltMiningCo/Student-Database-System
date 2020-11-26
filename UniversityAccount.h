#pragma once 

#include <vector>

#include "Course.h"

 class UniversityAccount {
protected:
	vector<Course> courses;
	int universityID;

public:
	UniversityAccount(int);

	int GetUniversityID() { return universityID; };

	virtual string ToString() { return ""; };
};