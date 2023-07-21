/*
	Write a program to help a local restaurant automate its breakfast billing system. The 	program should do the following:

	1. Show the customer the different breakfast items offered by the restaurant.

	2. Allow the customer to select more than one item from the menu.

	3. Calculate and print the bill.

	Use an array menuList of type MenuItemType. MenuItemType consists of three components:
		menuItem of type string,
		menuPrice of type double, and
		isOrdered of type bool.

	Your program must contain at least the following functions:

	1. Function getData: This function loads the data into the array menuList.

	2. Function showMenu: This function shows the different items offered by the restaurant and tells the user how to select the items.

	3. Function printCheck: This function calculates and prints the check. (Note that the billing amount should include a 5% tax.)

	Format your output with two decimal places. The name of each item in the output must be left justified. You may assume that the user
	selects only one item of a particular type.

	Algorithm:

		main
		{
			GetData
			do {
				showMenu
			} while not done
			printCheck
		}
*/

//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
struct MenuItemType
{
	string menuItem;
	double menuPrice;
	bool isOrdered = false;
};

const int SIZE=8;

//Function prototypes
void wait();
void getData(MenuItemType myMenuItemType[SIZE]);
int showMenu(MenuItemType myMenuItemType[SIZE]);
double printCheck(MenuItemType myMenuItemType[SIZE]);


int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Mikaela Harley -- Lab 9" << endl << endl;

	//Variable declarations	

	int answer;

	MenuItemType menuList[SIZE];
	
	MenuItemType myMenuItemType;
	
	//Program logic
	getData(menuList);
	do {
		answer=showMenu(menuList);
	} while (answer != 9);
	printCheck(menuList);

	
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

void getData(MenuItemType myMenuItemType[SIZE])
{
		

	fstream menu;
	menu.open("menu.txt");
	if (!menu)//If input failed to open the file
	{
		cout << "Could not open the menu file." << endl;
		exit(1); //exit the program with a value other than 1
	}

	for (int i = 0; i < SIZE; ++i)
	{
		getline(menu, myMenuItemType[i].menuItem);
		menu >> myMenuItemType[i].menuPrice;
		menu.ignore();//prevents reading the \n
	}
	
}

int showMenu(MenuItemType myMenuItemType[SIZE])
{
	int answer;

	cout << "Welcome to Cafe Kobucha! Here is our breakfast menu:" << endl;
	for (int i = 0; i < SIZE; ++i)
	{
		cout << i + 1 << ". " << setw(20) << left << myMenuItemType[i].menuItem;
		cout << fixed << showpoint  << setprecision(2) << '$' << myMenuItemType[i].menuPrice;
		cout << endl;
	}
	
	cout << "9. Print check!" << endl;

	cout << "To choose your item please type in their corresponding number and hitting ENTER." << endl;
	cin >> answer;
	cout << endl;

	if (answer >= 1 && answer <= 8)
	{
		myMenuItemType[answer - 1].isOrdered = true;
			
	}
	



	return answer;
}

double printCheck(MenuItemType myMenuItemType[SIZE])
{
	double total=0.0;
	const double TAX_RATE = 0.05;
	double tax = 0;

	cout << "Here is your receipt: " << endl;
	for (int i = 0; i < SIZE; ++i)
	{
		if (myMenuItemType[i].isOrdered == true)
		{
			cout << setw(20) << left << myMenuItemType[i].menuItem;
			cout << fixed << showpoint << setprecision(2) << '$' << myMenuItemType[i].menuPrice;
			cout << endl;
			total += myMenuItemType[i].menuPrice;
		}

	}
	tax = total * TAX_RATE;
	total += tax;

	cout << setw(20) << left << "Tax" << fixed << showpoint << setprecision(2) << '$' << tax << endl;
	cout << setw(20) << left << "Total amount " << fixed << showpoint << setprecision(2) << '$' << total << endl;


	return total;
}