/*
	Imagine we are using a two-dimensional array as the basis for creating the game battle- ship. In the game of battleship a ‘~’ character entry in the array represents ocean (i.e., not a ship), a ‘#’ character represents a place in the ocean where part of a ship is present, and a ‘H’ character represents a place in the ocean where part of a ship is present and has been hit by a torpedo. Thus, a ship with all ‘H’ characters means the ship has been sunk. Declare a two-dimensional char array that is 25 by 25 that represents the entire ocean and an If statement that prints “HIT” if a torpedo hits a ship given the coordinates X and Y. Write a C++ program that will read in a file representing a game board with 25 lines where each line has 25 characters corresponding to the description above.

	You should write a function called Fire that will take an X and Y coordinate and print “HIT” if a ship is hit and “MISS” if a ship is missed. If a ship is HIT you should update the array with an ‘H’ character to indicate the ship was hit. If a ship is hit that has already been hit at that location you should print “HIT AGAIN”. You should write a second function called FleetSunk that will determine if all the ships have been sunk. Your C++ program must then call these functions until all the ships have been sunk at which point the program should display “The fleet was destroyed!”.

	Your game loop logic (the main logic of a game) should like like the following:

	do {
		Fire(x, y, gameBoard);
	} while(!FleetSunk(gameBoard));
*/

//Include statements
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables


//Function prototypes
void wait();
void Fire(int&, int&, char gameboard[25][25], ofstream&);
bool FleetSunk(char gameboard[25][25]);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Mikaela Harley -- Lab 8" << endl << endl;

	//Variable declarations
	int x, y;
	char gameboard[25][25];

	fstream ocean;
	ocean.open("ocean.txt");
	if (!ocean)//If input failed to open the file
	{
		cout << "Could not open the game board file." << endl;
		exit(1); //exit the program with a value other than 1
	}

	ofstream displayboard;
	displayboard.open("displayboard.txt");
	if (!displayboard)//If input failed to open the file
	{
		cout << "Could not open the game board file." << endl;
		exit(1); //exit the program with a value other than 1
	}

	//Program logic
	
	for (int i = 0; i < 25; ++i) 
	{
		for (int j = 0; j < 25; ++j) 
		{
			ocean>>gameboard[i][j];
		}
	
	}
	cout << "There are five ships at sea. You must hit them a certain amount of times to sink them. \nOne must be hit 5 times, 2 three times, and 2 two times."<<
		"\nAll must be hit there certain times to sink and for the user to win the game." << endl << endl;
	//ship position in the water --> [8][7,11]
	


	do {
		cout << "PLease enter two numbers to select a target. Ex. 5 6" << endl;
		cin >> x >> y;
		Fire(x, y, gameboard, displayboard);
	} while (!FleetSunk(gameboard));

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			displayboard << gameboard[i][j];
		}
		displayboard << endl;
	}

	cout << "All the ships have sunk! You win!" << endl;

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

void Fire(int& x, int& y, char gameboard[25][25], ofstream& displayboard)
{	
	if (gameboard[x][y] == '~')
	{
		cout << "Your shot missed any ship! Try again." << endl;
	}
	else if (gameboard[x][y] == '#')
	{
		cout << "You have hit a ship! Keep going." << endl;
		gameboard[x][y] = 'H';
	
	}
	else if (gameboard[x][y] == 'H')
	{
		cout << "You hit the same ship again!"<<endl;
	}

}

bool FleetSunk(char gameboard[25][25])
{

	for (int i = 0; i < 25; ++i)
	{
		for (int j = 0; j < 25; ++j)
		{
			if (gameboard[i][j] == '#')
				return false;
		}
		
	}

	return true;
}