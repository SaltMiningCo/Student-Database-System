#pragma once

#include <string>

using namespace std;

class Grade {
private:
	int courseID;
	int grade;
	string courseStatus;

public:
	Grade(int, int, string);

	int GetCourseID() { return courseID; };
	int GetGrade() { return grade; };
	string GetStatus() { return courseStatus; };

	string ToString();
};