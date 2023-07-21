#include "StudentType.h"
#include <string>
#include <iostream>
using namespace std;

//Your class implementation functions go below
string studentFName;
string studentLName;
int testScore;
char grade;

StudentType::StudentType(std::string f, std::string l, int t , char g)
{
	cout << "Please enter the student's first name: ";
	cin >> f;
	cout << "Please enter the student's last name: ";
	cin >> l;
	cout << "Please enter the student's test score: ";
	cin >> t;
	cout << "Please enter the student's grade: ";
	cin >> g;
	cout<<endl;

	setFirstName(f);
	setLastName(l);
	setTestScore(t);
	setGrade(g);
}

void StudentType::setFirstName(string firstName)
{
	studentFName = firstName;
}

void StudentType::setLastName(string lastName)
{
	studentLName = lastName;
}

void StudentType::setTestScore(int score)
{
	testScore = score;
}

void StudentType::setGrade(char gr)
{
	grade = gr;
}

string StudentType::getFirstName() const
{
	return studentFName;
}

string StudentType::getLastName() const
{
	return studentLName;
}

int StudentType::getTestScore()const
{
	return testScore;
}

char StudentType::getGrade() const
{
	return grade;
}

string StudentType::getStudentFName()
{
	return  getFirstName();
}

string StudentType::getStudentLName()
{
	return getLastName();
}

int StudentType::getStudentScore()
{
	return getTestScore();
}

char StudentType::getSGrade()
{
	return getGrade();
}
