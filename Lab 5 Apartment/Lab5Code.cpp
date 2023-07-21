/******************************************************************************
(Apartment problem) A real estate office handles, say, 50 apartment units.
When the rent is, say, $600 per month, all the units are occupied. However,
for each, say, $40 increase in rent, one unit becomes vacant. Moreover, each
occupied unit requires an average of $27 per month for maintenance. How many
units should be rented to maximize the profit?

Write a program that reads the following from an input file (provided)

	The total number of units.

	The rent to occupy all the units.

	The Amount to maintain a rented unit (maintenance fee).

And prompts the user to enter the following:

	The increase in rent that results in a vacant unit.

The program then outputs the number of units to be rented to maximize the profit.
Algorithm:
	while (profit goes up)
	{
		increase the monthly rent
		decrease number of units rented by one
		calculate the profit which is (rent - maintenance fee) * number of units rented
	}
	output the results (remember to back out the last changes made to monthly rent,
	number of units, and profit above -- why do you need to back out the last changes)
		number of units rented
		monthly rent
		total profit

Malik, Ch 6, Programming Exercise 28 (page 345)
******************************************************************************/
//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
//include any missing standard libraries required to complete the program

using namespace std;

//Global declarations: Constants and type definitions only -- no variables

//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Mikaela Harley -- Lab 5" << endl << endl;

	//Variable declarations
	double units, rent, increase, mainFee, profit, maxProfit = 0;

	fstream input;
	input.open("input.dat");
	if (!input)//If input failed to open the file
	{
		cout << "Could not open the input file." << endl;
		exit(1); //exit the program with a value other than 1
	}

	cout << "Please enter the increase in rent. ";
	cin >> increase;

	input >> units >> rent >> mainFee;

	//Program logic
	profit = (rent - mainFee) * units;

	while (profit > maxProfit)
	{
		maxProfit = profit;
		rent = rent + increase;
		--units;
		profit = (rent - mainFee) * units;
	}
	
	units = units + 1;
	rent = rent - increase;

	cout << "Number of units rented: " << fixed << setprecision(0) << units << endl;
	cout << "New monthly rent: $" << fixed << setprecision(2) << rent << endl;
	cout << "Total profit: $" << fixed << setprecision(2) << maxProfit << endl;


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
