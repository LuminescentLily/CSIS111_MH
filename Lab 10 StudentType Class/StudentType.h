#pragma once

#include <string>

class StudentType
{
private:
	std::string getFirstName() const;
	std::string getLastName() const;
	int getTestScore() const;
	char getGrade() const;

public:
	StudentType(std::string, std::string, int, char);

	std::string getStudentFName();
	std::string getStudentLName();
	int getStudentScore();
	char getSGrade();

	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setTestScore(int score);
	void setGrade(char gr);

};
