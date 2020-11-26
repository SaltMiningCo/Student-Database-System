#include "StudentUI.h"

string StudentUI::DisplayOptions() {
	string display = "";

	display += "1) View Grades\n";
	display += "2) Log Out\n";

	return display;
}

bool StudentUI::ProcessSelection(string input, Student * associatedStudent) {
	if (input == "1") {
		for (Grade g : associatedStudent->GetGrades()) {
			cout << g.GetCourseID() << endl << g.GetGrade() << endl << g.GetStatus() << endl << endl;
		}

		return false;
	}
	else if (input == "2") {
		return true;
	}
	else {
		cout << "Not a valid selection.\n";

		return false;
	}
}