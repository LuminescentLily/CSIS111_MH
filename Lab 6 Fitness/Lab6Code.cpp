/*
The cost to become a member of a fitness center is as follows:
	(a) the senior citizens discount is 30%;
	(b) if the membership is bought and paid for 12 or more months, the discount is 15%; and
	(c) if more than five personal training sessions are bought and paid for, the discount on each session is 20%.

Write a menu-driven program that determines the cost of a new membership. Your program must contain
	a function that displays the general information about the fitness center and its charges,
	a function to get all of the necessary information to determine the membership cost, and
	a function to determine the membership cost.

Use appropriate parameters to pass information in and out of a function. (Do not use any global variables.)

Malik, Ch 6, Programming Exercise 25 (page 463)

*/

//Include statements
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
const float MONTHLY_MEMBERSHIP_RATE = 25.00;
const float PERSONAL_SESSION_RATE = 50.00;
const float SENIOR_DISCOUNT = 0.30;
const float PREPAID_DISCOUNT = 0.15;
const float SESSION_DISCOUNT = 0.20;

//Function prototypes
void wait();
double memberCost(bool prepaid, bool seniors, int y);
void genInfo();
void getInfo();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Mikaela Harley -- Lab 6" << endl << endl;

	//Variable declarations
	
	//Program logic
	genInfo();
	getInfo();

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

void genInfo() //a function that displays the general information about the fitness center and its charges
{
	int value = 1;
	while (value > 0 && value <=30)
	{
		cout << '~';
		value++;
	}
	
	cout << "River Fitness Gym";
	value = 1;
	while (value > 0 && value <= 30)
	{
		cout << '~';
		value++;
	}
	cout << endl << endl;
	cout << "Here to get you fit and happy! Today is a new day to start planning for your future. \nDon't wait for your future, make your future!" << endl << endl;
	cout << "The cost to become a member of a fitness center is as follows: " << endl;
	cout << "\t (a) the senior citizens discount is 30%" << endl;
	cout << "\t (b) if the membership is bought and paid for 12 or more months, the discount is 15% and" << endl;
	cout << "\t (c) if more than five personal training sessions are bought and paid for, \n\t the discount on each session is 20%." << endl;
	value = 1;
	while (value > 0 && value <= 93)
	{
		cout << '~';
		value++;
	}
	cout << endl << endl;
	
}

void getInfo() //a function to get all of the necessary information to determine the membership cost
{
	int x = 0, y = 0;
	bool isSenior{ false };
	bool prepaid{ false };
	bool sessions{ false };
	bool done{ false };

	while (x != 4)
	{
		cout << "Membership menu! Please enter a number for your option." << endl;
		if (isSenior == false)
			cout << "1. If you are a Senior Citizen which gives you a discount of 30%." << endl;

		if (prepaid == false)
			cout << "2. If you would like to pay 12 or more months in advance for your membership and receive a discount of 15%." << endl;

		if(sessions == false)
			cout << "3. If you would like you join some Personal Training Sessions. Joining five or more will give you a 20% discount to each." << endl;

		if (done == false)
			cout << "4. If you are done and would like to cash out." << endl;
		cout << "PLease enter the number of your choice: ";
		cin >> x;

		switch (x)
		{
		case 1:
			isSenior = true;
			break;

		case 2:
			prepaid = true;
			break;

		case 3:
			sessions = true;
			if (sessions == true)
			{
				cout << "How many sessions would you like?";
				cin >> y;
			}
			break;

		case 4:
			break;
		}

	}
	cout << "This is the total cost: $" << fixed << setprecision(2) << memberCost(prepaid, isSenior, y) << endl;
}

double memberCost(bool prepaid, bool seniors, int y) //a function to determine the membership cost
{
	double sessions, monthlyCost, totalCost;

	monthlyCost = MONTHLY_MEMBERSHIP_RATE;

	if (prepaid == true)
		monthlyCost *= (1 - PREPAID_DISCOUNT);

	sessions = y * PERSONAL_SESSION_RATE;

	if (y >= 5)
		sessions *= (1 - SESSION_DISCOUNT);

	if (seniors == true)
		monthlyCost *= (1 - SENIOR_DISCOUNT);

	totalCost = (12 * monthlyCost) + sessions;
	
	return totalCost;
}
