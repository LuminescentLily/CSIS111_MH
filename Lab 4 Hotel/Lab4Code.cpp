//Hotel.cpp -- brief statement as to the file’s purpose -- See assignment below.
/*	Assignment Description
	The cost of renting a room at a hotel is, say $100.00 per night. For special occasions,
	such as a wedding or conference, the hotel offers a special discount as follows: If
	the number of rooms booked is at least 10, the discount is 10%; at least 20, the discount
	is 20%; and at least 30, the discount is 30%. Also if rooms are booked for at least three
	days, then there is an additional 5% discount.

	Write a program that
		- loads the cost of renting one room and the sales tax rate
			from an input file (provided),
		- prompts the user to enter the number of rooms booked, and
		- prompts the user to enter the number of days the rooms are booked.

	The program outputs to an output file named (output.dat)
		- the cost of renting one room,
		- the discount on each room as a percent,
		- the number of rooms booked,
		- the number of days the rooms are booked,
		- the total cost of the rooms,
		- the sales tax,
		- and the total billing amount.

	Your program must use appropriate named constants to store special values such as various discounts.
*/

//Include statements
#include <iostream>
#include <string>
//include the standard library file needed to read and write files
#include <fstream>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables


//Function prototypes
void wait();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Mikaela Harley -- Lab 4" << endl << endl;

	//Variable declarations
	double roomRate, taxRate, discountRate, salesTax, totalRoomCost;
	int roomsBooked, days;
	double addDiscount, totalBill, totalDiscount;


	//Add an ifstream variable to read the input file "input.dat" and open it.
	//Add an ofstream variable to output the final results to output.dat.
	ifstream input;
	input.open("input.dat");
	if (!input)//If input failed to open the file
	{
		cout << "Could not open the input file." << endl;
		exit(1); //exit the program with a value other than 1
	}

	ofstream output;
	output.open("output.dat");
	if(!output)
	{
		cout << "Could not open the input file." << endl;
		exit(1);
	}

	//Program logic
	/*
		Open and read input.dat to get the cost of renting one room
		  and the sales tax rate.
		Prompt the user to provide the following:
		-the number of rooms booked and
		-the number of days the rooms are booked.
	*/
	input >> roomRate >> taxRate;

	cout << "How many rooms would you like to book?" << endl;
	cin >> roomsBooked;
	cout << endl;
	cout << "How many days would you like to stay?" << endl;
	cin >> days;
	cout << endl;

	// Complete the appropriate calculations
	if (days >= 3)
	{
		addDiscount = 0.05;
	}
	else
	{
		addDiscount = 0;
	}

	//   Calculate the discount rate
	if (roomsBooked < 10)
		discountRate = 0.0;
	else if (roomsBooked < 20)
		discountRate = 0.1;		//10% discount
	else if (roomsBooked < 30)
		discountRate = 0.2;		//20% discount
	else
		discountRate = 0.3;		//30% discount

	//add addDiscount
	totalDiscount = discountRate + addDiscount;

	// Calculate totalRoomCost and salesTax
	totalRoomCost = (days * roomRate); //didn't take discount into account

	salesTax = taxRate * totalRoomCost;

	/*
		Output to output.dat
		- the cost of renting one room,
		- the discount on each room as a percent,
		- the number of rooms booked,
		- the number of days the rooms are booked,
		- the total cost of the rooms,
		- the sales tax,
		- and the total billing amount.
		Your output should look nice and neat
	*/
	
	totalBill = ((totalRoomCost + salesTax) * roomsBooked) - (totalDiscount * totalRoomCost);
	output << roomRate << totalDiscount << roomsBooked << days << totalRoomCost << salesTax << totalBill;

	cout << "Your total is $" << fixed << setprecision(2) << totalBill << '.' << endl;
	cout << "The sales tax is " << fixed << setprecision(2) << salesTax << "%." << endl;

	//Closing program statements
	input.close();
	output.close();
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
