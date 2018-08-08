/*****************************************************************************************
Project Name: Lab 6
Name: Kristopher Lowell
Date Completed: 8/8/2018
Purpose: To accept student records, print out which students passed, copy said passing
students and printing the copied records.
*****************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

int main(int argc, char *argv[])
{
	unsigned numOfRecords = 0;
	char more;

	string entry;
	int grade;

	Student currentStudent;
	vector <Student> records;
	vector <Student> passing;
	vector <Student> copy;

	do
	{
		cout << "How many records? ";		// Accepting entry for how many new records to be entered
		cin >> numOfRecords;

		cout << "Enter student record (studentID <space> studentFirstName <space> studentGrade):" << endl;	// Prompts user for proper format

		for (unsigned i = 0; i < numOfRecords; i++)		// Taking advantage of spaces between data points
		{
			cin >> entry;
			currentStudent.setID(entry);

			cin >> entry;
			currentStudent.setName(entry);

			cin >> grade;
			currentStudent.setGrade(grade);

			cin.ignore(INT_MAX, '\n');			// Using a medium variable to transfer class objects into vector

			records.push_back(currentStudent);
		}

		for (unsigned i = 0; i < records.size(); i++)		// Checking which records are passing
			if (records[i].getGrade() >= 8)
				passing.push_back(records[i]);

		cout << endl << "Pass records" << endl;				// Printing the passing records

		for (unsigned i = 0; i < passing.size(); i++)
			cout << passing[i].getID() << " " << passing[i].getName() << " " << passing[i].getGrade() << endl;

		for (unsigned i = 0; i < passing.size(); i++)		// Copying using the copy assignment operator
		{
			currentStudent = passing[i];
			copy.push_back(currentStudent);
		}

		/*for (unsigned i = 0; i < passing.size(); i++)		// Copying using the copy constructor
		{
			Student copyStudent(passing[i]);
			copy.push_back(copyStudent);
		}*/

		cout << endl << "Copied " << copy.size() << " pass records" << endl;	// Printing the copied records

		for (unsigned i = 0; i < copy.size(); i++)
			cout << copy[i].getID() << " " << copy[i].getName() << " " << copy[i].getGrade() << endl;


		cout << endl << "Any more records? (Y/N) ";			// Prompting and accepting if any more records are to be entered.
		do
		{
			cin >> more;
		} while (more != 'Y' && more != 'y' && more != 'N' && more != 'n');

		passing.clear();									// Clearing the passing and copy vectors
		copy.clear();

	} while (more == 'Y' || more == 'y');					// Loop ends when user enters a 'N' or 'n'

	records.clear();										// Clearing the main records vector for good measure
	
	return 0;
}