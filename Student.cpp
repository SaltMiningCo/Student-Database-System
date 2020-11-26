#include "Student.h"

Grade Student::GetGrade(int courseID) {
	Grade * matchedGrade = nullptr;

	for (Grade g : courseGrades) {
		if (g.GetCourseID() == courseID) {
			matchedGrade = &g;
			break;
		}
	}

	return *matchedGrade;
}

string Student::ToString() {
	string output = "";

	output += to_string(universityID) + "\n";
	output += to_string(majorGPA) + "\n";
	output += to_string(minorGPA) + "\n";
	output += to_string(creditsTaken) + "\n";
	
	// Output grades
	for (Grade g : courseGrades) {
		output += g.ToString() + "\n";
	}

	// Output courses
	/*output += "Courses:\n";

	for (Course c : courses) {
		output += c.ToString() + "\n";
	}*/

	return output;
}