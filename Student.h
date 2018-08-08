/*****************************************************************************************
Project Name: Lab 6
Name: Kristopher Lowell
Date Completed: 8/8/2018
Purpose: To accept student records, print out which students passed, copy said passing
students and printing the copied records.
*****************************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
	Student();																			// Default constructor
	Student(string studentIDVal, string studentFirstNameVal, int studentGradeVal);		// Parameterized constructor
	Student(const Student &stdnt);														// Copy constructor

	~Student();																			// Destructor

	string getID();																		// Accessor functions
	string getName();
	int getGrade();

	void setID(string IDVal);															// Mutator functions
	void setName(string NameVal);
	void setGrade(int GradeVal);

	const Student operator=(const Student &stdnt);										// Copy assignment operator function

private:
	string studentID;
	string studentFirstName;
	int studentGrade;
};

Student::Student()
{
	//cout << endl << "Default Constructor Being Used." << endl;
	
	studentFirstName = "XXXX";
	studentGrade = 0;
}

Student::Student(string studentIDVal, string studentFirstNameVal, int studentGradeVal)
{
	//cout << endl << "Parameterized Constructor Being Used." << endl;

	studentID = studentIDVal;
	studentFirstName = studentFirstNameVal;
	studentGrade = studentGradeVal;
}

Student::Student(const Student &stdnt)
{
	//cout << endl << "Copy Constructor Being Used." << endl;

	studentID = stdnt.studentID;
	studentFirstName = stdnt.studentFirstName;
	studentGrade = stdnt.studentGrade;
}

Student::~Student()
{
	//cout << endl << "Destructor Being Used." << endl;
	
	studentID.clear();
	studentFirstName.clear();
	studentGrade = 0;
}

string Student::getID() 
{ 
	return studentID; 
}

string Student:: getName() 
{ 
	return studentFirstName; 
}

int Student::getGrade() 
{ 
	return studentGrade; 
}

void Student::setID(string IDVal)
{ 
	studentID = IDVal; 
}

void Student::setName(string NameVal) 
{ 
	studentFirstName = NameVal; 
}

void Student::setGrade(int GradeVal) 
{ 
	studentGrade = GradeVal; 
}

const Student Student::operator=(const Student &stdnt)
{
	//cout << endl << "Copy Assignment Operator Being Used." << endl;
	
	studentID = stdnt.studentID;
	studentFirstName = stdnt.studentFirstName;
	studentGrade = stdnt.studentGrade;
	return *this;
}