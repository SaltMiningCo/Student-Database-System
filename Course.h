#pragma once 

#include <string>

using namespace std;

class Course {
private:
	string courseName;
	string textbookName;
	string description;
	int courseID;

	int credits;
	//vector<Student> enrolledStudents;

public:
	Course(string, string, string, int, int);
	string ToString();
};