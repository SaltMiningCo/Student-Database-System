#include "Grade.h"

Grade::Grade(int newCourseID, int newGrade, string status) {
	courseID = newCourseID;
	grade = newGrade;
	courseStatus = status;
}

string Grade::ToString() {
	string output = "";

	output += to_string(courseID) + "\n";
	output += to_string(grade) + "\n";
	output += courseStatus;

	return output;
}