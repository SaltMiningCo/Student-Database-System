#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

#include "Account.h"
#include "Course.h"
#include "Grade.h"
#include "Student.h"
//#include "UniversityAccount.h"

using namespace std;

//Method Declaration
Account login(vector<Account> * accounts) {
    //Variables
    string username;
    string readName;
    string password;

	Account associatedAccount;

    ifstream studentFile("studentInfo.txt");
    bool validName = false;
    bool validPass = false;

    // Student Name Loop
	while (validName == false) {
		// Get the student name
		cout << "Username (type \"quit\" to quit): ";
		getline(cin, username);

		// If the user wants to quit
		if (username == "quit")
			return *(new Account());

		// Look for the student name in the list of accounts
		for (Account account : *accounts) {
			if (account.GetUsername() == username) {
				validName = true;
				associatedAccount = account;
				break;
			}
		}

		// If the name was found, don't loop again. If not, tell the user that the
		// account does not exist
		if (validName == true)
			break;
		else
			printf("%s does not exist\n", username);
	}

	// Password Loop
	while (validPass == false) {
		// Get the password
		cout << "Password: ";
		cin >> password;

		// If the user wants to quit
		if (password == "quit")
			return *(new Account());

		if (password == associatedAccount.GetPassword())
			validPass = true;
	}

	printf("Sucessful Login\n");
	cin.clear();

	return associatedAccount;
}

void registerAccount(vector<Account> * accounts, vector<Student> * universityAccounts) {
    string studentName;
	string password;

	string studentIDStr;
	int studentID;

	Account * newAccount = NULL;

    cout << "Enter Username: ";
	getline(cin, studentName);
	
	cout << endl << "Enter Unique Password: ";
	getline(cin, password);

	// Should be a loop
	bool validID = false;
	Student * associatedStudent = nullptr;

	while (!validID) {
		cout << endl << "Enter Student ID: ";
		getline(cin, studentIDStr);

		// If the user wants to quit
		if (studentIDStr == "quit")
			return;

		studentID = stoi(studentIDStr, nullptr, 10);

		for (auto u : *universityAccounts) {
			if (u.GetUniversityID() == studentID) {
				validID = true;
				associatedStudent = new Student(u.GetGrades(), u.GetMajorGPA(), u.GetMinorGPA(),
					u.GetCreditsTaken(), u.GetUniversityID());
				break;
			}
		}

		cout << "Coult not find student ID\n";
	}

	newAccount = new Account(associatedStudent, studentName, password, studentID, true);
	accounts->push_back(*newAccount);

    cout << "Registration Successful!"
         << endl;
}

void ReadAllFromFile(vector<Account> * accounts, vector<Student> * universityAccounts, vector<Course> * courses) {
	// Read university accounts from university account file
	ifstream uniAccountFile("UniversityAccountInfo.txt");

	while (!uniAccountFile.eof()) {
		string universityIDstr = "";
		string majorGPAstr = "";
		string minorGPAstr = "";
		string creditsTakenstr = "";
		vector<Grade> * courseGrades = new vector<Grade>;

		getline(uniAccountFile, universityIDstr);

		if (universityIDstr == "")
			break;

		getline(uniAccountFile, majorGPAstr);
		getline(uniAccountFile, minorGPAstr);
		getline(uniAccountFile, creditsTakenstr);

		// Get grades
		while (!uniAccountFile.eof()) {
			string courseIDstr = "";
			string gradestr = "";
			string courseStatus = "";

			getline(uniAccountFile, courseIDstr);

			if (courseIDstr == "~")
				break;

			getline(uniAccountFile, gradestr);
			getline(uniAccountFile, courseStatus);

			int courseID = stoi(courseIDstr, nullptr, 10);
			int grade = stoi(gradestr, nullptr, 10);

			courseGrades->push_back(*(new Grade(courseID, grade, courseStatus)));
		}

		int universityID = stoi(universityIDstr, nullptr, 10);
		double majorGPA = atof(majorGPAstr.c_str());
		double minorGPA = atof(minorGPAstr.c_str());
		int creditsTaken = stoi(creditsTakenstr, nullptr, 10);

		universityAccounts->push_back(*(new Student(*courseGrades, majorGPA, minorGPA, creditsTaken, universityID)));
	}

	uniAccountFile.close();

	// Write courses from courses file
	ifstream coursesFile("Courses.txt");

	while (!coursesFile.eof()) {
		string courseName = "";
		string textbookName = "";
		string description = "";
		string courseIDstr = "";
		string creditsstr = "";

		getline(coursesFile, courseName);

		if (courseName == "")
			break;

		getline(coursesFile, textbookName);
		getline(coursesFile, description);
		getline(coursesFile, courseIDstr);
		getline(coursesFile, creditsstr);

		int courseID = stoi(courseIDstr, nullptr, 10);
		int credits = stoi(creditsstr, nullptr, 10);

		courses->push_back(*(new Course(courseName, textbookName, description, courseID, credits)));
	}

	coursesFile.close();

	// Read accounts from Account Info file
	ifstream accountFile("AccountInfo.txt");

	while (!accountFile.eof()) {
		string username = "";
		string password = "";
		string universityIDstr = "";

		getline(accountFile, username);

		if (username == "")
			break;

		getline(accountFile, password);
		getline(accountFile, universityIDstr);

		int universityID = stoi(universityIDstr, nullptr, 10);
		Student * associatedStudent = nullptr;

		for (auto u : *universityAccounts) {
			if (u.GetUniversityID() == universityID) {
				associatedStudent = new Student(u.GetGrades(), u.GetMajorGPA(), u.GetMinorGPA(), 
					u.GetCreditsTaken(), u.GetUniversityID());
				break;
			}
		}

		accounts->push_back(*(new Account(associatedStudent, username, password, universityID, true)));
	}

	accountFile.close();
}

void WriteAllToFile(vector<Account> * accounts, vector<Student> * universityAccounts, vector<Course> * courses) {
	//Write accounts to Account Info file
	ofstream accountFile("AccountInfo.txt");

	for (Account a : *accounts)
		accountFile << a.ToString() << "\n";

	accountFile.close();

	// Write university accounts to university account file
	ofstream uniAccountFile("UniversityAccountInfo.txt");

	for (auto u : *universityAccounts) 
		uniAccountFile << u.ToString() << "~\n";

	uniAccountFile.close();

	// Write courses to courses file
	ofstream coursesFile("Courses.txt");

	for (Course c : *courses)
		coursesFile << c.ToString() << "\n";

	coursesFile.close();
}

void InputLoop(vector<Account> * accounts, vector<Student> * universityAccounts, vector<Course> * courses) {
	while (true)
	{
		Account * activeAccount = nullptr;
		string choice = "";

		cout << "Welcome to the Student Database!"
			<< endl;

		// Not logged into an account
		while (activeAccount == nullptr) {
			cout << "Would you like to Login, Register a new account, or Quit?"
				<< endl;
			//cin >> choice;
			getline(cin, choice);

			// Convert choice to lowercase so it's easier to create an if-else block
			transform(choice.begin(), choice.end(), choice.begin(), ::tolower);

			// Login
			if (choice == "login") {
				activeAccount = &login(accounts);
			}
			// Register new account
			// Yes I know it's redundant
			else if (choice == "register" || choice == "register account" || choice == "register new account" || choice == "register a new account") {
				registerAccount(accounts, universityAccounts);
			}
			//Failsafe
			else if (choice == "quit") {
				cout << "Goodbye";
				return;
			}
			else {
				cout << "Invalid Option"
					<< endl;
			}
		}

		// Logged into an account
		activeAccount->ServiceUser();
	}
}

int main(){ 
	vector<Account> * accounts = new vector<Account>;
	vector<Student> * universityAccounts = new vector<Student>;
	vector<Course> * courses = new vector<Course>;

	ReadAllFromFile(accounts, universityAccounts, courses);
        
	InputLoop(accounts, universityAccounts, courses);
    
	WriteAllToFile(accounts, universityAccounts, courses);

    return 0;
}


