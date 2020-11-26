#include "Account.h"
#include "StudentUI.h"

Account::Account(Student* newStudent, string newUsername, string newPassword, int newUniversityID, bool isStudent) {
	username = newUsername;
	password = newPassword;
	universityID = newUniversityID;

	associatedStudent = newStudent;

	if (isStudent)
		view = new StudentUI();
}

string Account::ToString() {
	string output = "";

	output += username + "\n";
	output += password + "\n";
	output += to_string(universityID);

	return output;
}