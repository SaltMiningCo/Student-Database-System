#pragma once

#include "UIParentClass.h"

class StudentUI : public UIParent {
private:

public:
	StudentUI() {};

	string DisplayOptions();
	virtual bool ProcessSelection(string input, Student*);
};