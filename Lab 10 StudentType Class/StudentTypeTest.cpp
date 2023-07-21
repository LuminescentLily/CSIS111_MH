//StudentTypeTest.cpp -- driver used to test StudentType implementation.
//CSIS 111-001
//<cplusplus.com>


//Include statements
#include <iostream>
#include <string>
#include "StudentType.h"

using namespace std;

//Global declarations: Constants and type definitions only -- no variables


//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Mikaela Harley -- Lab 10" << endl << endl;

	//Variable declarations
	StudentType st("First", "Last", 100, 'A');	//declare your StudentType variable

	//Program logic -- set your StudentType instance variables using your set functions
	// then display your student data using your StudentType get functions.

	cout << "Printing out student information:" << endl;
	cout << "\tFirst Name: " << st.getStudentFName() << endl;
	cout << "\tLast Name: " << st.getStudentLName() << endl;
	cout << "\tScore: " << st.getStudentScore() << endl;
	cout << "\tGrade: " << st.getSGrade() << endl;
	cout << endl << endl;

	//Closing program statements
	wait(); //Halts the program until the user is ready to finish
	return 0;
}

//Function Definitions
void wait()
{
	//The following if-statement checks to see how many characters are in cin's buffer
	//If the buffer has characters in it, the clear and ignore methods get rid of them.
	if (cin.rdbuf()->in_avail() > 0) //If the buffer is empty skip clear and ignore
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Clear the input buffer 
	}
	char ch;
	cout << "Press the Enter key to continue ... ";
	cin.get(ch);
}