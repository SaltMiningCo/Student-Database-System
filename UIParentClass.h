#pragma once

#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

class UIParent {
private:

protected:

public:
	// Gets and handles the user's inputs
	void ServiceUser(Student*);

	virtual string DisplayOptions() = 0;
	virtual bool ProcessSelection(string, Student*) = 0;
};