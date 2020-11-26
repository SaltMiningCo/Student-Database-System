#include "Course.h"

//string courseName;
//string textbookName;
//string description;
//int courseID;
//
//int credits;
//vector<Student> enrolledStudents;

Course::Course(string name, string newTextbookName, string desc, int newCourseID, int newCredits) {
	courseName = name;
	textbookName = newTextbookName;
	description = desc;

	courseID = newCourseID;
	credits = newCredits;
}

string Course::ToString() {
	string output = "";

	output += courseName + "\n";
	output += textbookName + "\n";
	output += description + "\n";
	output += to_string(courseID) + "\n";
	output += to_string(credits);

	return output;
}