#pragma once 

#include <string>

#include "Student.h"
#include "StudentUI.h"

using namespace std;

class Account {
private:
	string username;
	string password;
	int universityID;

	Student *associatedStudent;
	StudentUI *view;

public:
	Account() { };
	Account(Student*, string, string, int, bool);

	void ServiceUser() { view->ServiceUser(associatedStudent); };

	string GetUsername() { return username; };
	string GetPassword() { return password; };

	string ToString();
};