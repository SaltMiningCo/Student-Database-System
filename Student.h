#pragma once 

#include <vector>

#include "Grade.h"
#include "UniversityAccount.h"

using namespace std;

class Student : UniversityAccount {
private:
	vector<Grade> courseGrades;
	double majorGPA;
	double minorGPA;
	int creditsTaken;

public:

	Student(vector<Grade> grades, double majGPA, double minGPA, int credits, int ID) : UniversityAccount(ID) {
		courseGrades = grades;
		majorGPA = majGPA;
		minorGPA = minGPA;
		creditsTaken = credits;
	}

	int GetUniversityID() { return universityID; };

	Grade GetGrade(int);
	vector<Grade> GetGrades() { return courseGrades; };

	double GetMajorGPA() { return majorGPA; };
	double GetMinorGPA() { return minorGPA; };
	int GetCreditsTaken() { return creditsTaken; };

	string ToString();
};