//<File name> -- brief statement as to the file’s purpose
//CSIS 111-<Section Number>
//<Sources if necessary>


//Include statements
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//Global declarations: Constants and type definitions only -- no variables
enum Planets { MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO };


//Function prototypes
void wait();
bool ValidPlanet(string, Planets&);
float CalculateWeight(float&, Planets&);

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Mikaela Harley -- Lab 7" << endl << endl;

	//Variable declarations
	Planets planetName;
	string answer;
	float weight;
	
	//Program logic
	do
	{

		cout << "Please enter the name of the planet you would like to use as a reference." << endl;
		cin >> answer;

	} while (!ValidPlanet(answer, planetName));

	cout << "Hello user. How much do you weigh on Earth? ";		//Their weight
	cin >> weight;
	
	CalculateWeight(weight, planetName);

	cout << "Your weight on " << answer << " is " << fixed << setprecision(2) << weight << '.' << endl;


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

//Planet Function
bool ValidPlanet(string answer, Planets& planetName)
{

	if (answer == "Mercury")
	{
		planetName = MERCURY;
		return true;
	}
	if (answer == "Venus")
	{
		planetName = VENUS;
		return true;
	}
	if (answer == "Moon")
	{
		planetName = MOON;
		return true;
	}
	if (answer == "Mars")
	{
		planetName = MARS;
		return true;
	}
	if (answer == "Earth")
	{
		planetName = EARTH;
		return true;
	}
	if (answer == "Jupiter")
	{
		planetName = JUPITER;
		return true;
	}
	if (answer == "Pluto")
	{
		planetName = PLUTO;
		return true;
	}
	if (answer == "Saturn")
	{
		planetName = SATURN;
		return true;
	}
	if (answer == "Uranus")
	{
		planetName = URANUS;
		return true;
	}
	if (answer == "Neptune")
	{
		planetName = NEPTUNE;
		return true;
	}
	else
		cout << "You have entered an invalid planet name. Please enter the name with a captial letter." << endl;
	

	return false;
}

float CalculateWeight(float& weight, Planets& planetName)
{

	{
		switch (planetName)
		{
		case MERCURY://Mercury
			weight = weight * 0.4155;
			break;

		case VENUS://Venus
			weight = weight * 0.8975;
			break;

		case EARTH://Earth
			weight = weight * 1.0;
			break;

		case MOON://Moon
			weight = weight * 0.166;
			break;

		case MARS://Mars
			weight = weight * 0.3507;
			break;

		case JUPITER://Jupiter
			weight = weight * 2.5374;
			break;

		case SATURN://Saturn
			weight = weight * 1.0677;
			break;

		case URANUS://Uranus
			weight = weight * 0.8947;
			break;

		case NEPTUNE: //Neptune
			weight = weight * 1.1794;
			break;

		case PLUTO://Pluto
			weight = weight * 0.0899;
			break;
		}
	}

	return weight;
}
