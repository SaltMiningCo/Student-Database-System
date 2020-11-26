#include "UIParentClass.h"

bool shouldQuit(string input) {
	return (input == "quit" || input == "Quit");
}

void UIParent::ServiceUser(Student * associatedStudent) {
	string input = "";

	cin.ignore();

	while (!shouldQuit(input)) {
		cout << DisplayOptions();
		getline(cin, input);

		if (ProcessSelection(input, associatedStudent))
			break;
	}
}