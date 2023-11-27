#include <iostream>
#include "Employee.h"
#include <string>
#include <fstream>
#include <iomanip>


using namespace std;
const float INVALID = -1000.00;		//constant used for our error checking functions

bool checkString(std::string);	//headers for error checking functions
float checkRate(std::string temp3);
float checkHours(std::string temp4);

int main() {
	ifstream inp;
	string temp1, temp2, temp3, temp4;		//creates 4 strings named temp1, temp2, temp3, temp4
	inp.open("input.txt");					//opens file input.txt

	
	if (!inp)			//checks to ensure input.txt exists
	{
		cout << "input.txt not found" << endl;
		exit(1);
	}
	
	while(!inp.eof())	//loop that runs until it reaches the end of the file
	{
		Employee employee1;				//creates our employee object
		getline(inp, temp1);			//gets 1st line from the file
		if (checkString(temp1))			//calls error-check function checkString
		{
			employee1.setfname(temp1);	//calls setfname if the string is eligible
		}
		else
		{
			employee1.seterror(1);		//declares an error in the string
		}									
		getline(inp, temp2);
		if (checkString(temp2))		//calls error-check function checkString
		{
			employee1.setlname(temp2);	//calls setlname if the string is eligible
		}
		else
		{
			employee1.seterror(1);		//declares an error in the string
		}				
		getline(inp, temp3);
		if (checkRate(temp3) != INVALID)		//calls our errorcheck function checkRate and compares to our INVALID data
		{
			employee1.sethourlyrate(checkRate(temp3));	//assigns value from checkRate to hourlyrate
		}
		else
		{
			employee1.seterror(1);		//declares an error
		}
		getline(inp, temp4);
		if (checkHours(temp4) != INVALID)	//calls our errorcheck function checkHours and compares to our INVALID data
		{
			employee1.sethoursworked(checkHours(temp4));	//assigns value from checkHours to hoursworked
		}
		else
		{
			employee1.seterror(1);		//declares an error in the string
		}
		
		employee1.setgrosspay(employee1.gethourlyrate(), employee1.gethoursworked());
		employee1.display();
	}
	
	
	inp.close();		//closes input file
	return 0;
}

bool checkString(std::string temp1)	//checks to ensure a string is valid for passing to class
{
	if (temp1.length() > 0)	//ensures string has a length greater than 0
		{
			if (temp1.find_first_of(" ") == -1)	//ensures string has no space
			{
				return true;	//true returned if both preconditions are met
			}
			else
			{
				return false;	//false returned with failed precondition
			}
		}
		else
		{
			return false;	//false returned with failed precondition
		}
	
}

float checkRate(std::string temp3)	//checks to make sure the rate float variable is eligible for the class
{
	if (temp3.find_first_not_of(".0123456789") == -1)	//ensures there are only numbers and decimals in the string
		{
			int decimal = 0;	//decimal counter variable
			for (int i = 0; i < temp3.length(); i++)
			{
				if (temp3[i] == '.')	//looks for decimal in the string
				{
					decimal += 1;	//adds one to the value of decimal
				}
			}
			if (decimal == 1)
			{
				float rate = stof(temp3.c_str());	//converts string to number
				if (rate >= 8.25)
				{
					//cout << rate << " per hour" << endl;
					return rate;	//returns float if all preconditions met
				}
			else
				{
					return INVALID;	//failed precondition
				}
			}
		}
	else
	{
		return INVALID;	//failed precondition
	}
}

float checkHours(std::string temp4)	//checks to ensure Hours are eligible for our class
{
	if (temp4.find_first_not_of(".0123456789") == -1)	//ensures there are only numbers and decimals in the string
		{
			int decimal = 0; //decimal counter variable
			for (int i = 0; i < temp4.length(); i++)
			{
				if (temp4[i] == '.') //looks for decimal in the string
				{
					decimal += 1; 	//adds one to the value of decimal
				}
			}
			if (decimal == 1)
			{
				float hours = stof(temp4.c_str()); //converts string to number
				if (hours >= 0.00)
				{
					//cout << rate << " per hour" << endl;
					return hours;	//returns float if all preconditions met
				}
			else
				{
					return INVALID;		//failed precondition
				}
			}
		}
		else
		{
			return INVALID;		//failed precondition
		}
}





