#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include "Employee.h"


using namespace std;

// PEOPLE CONSTRUCTOR
People::People()
{
	fname = "blank";
	lname = "blank";
	error = 0;
}

//PEOPLE MODIFICATION MEMBER FUNCTIONS
void People::setfname(const string temp1)
{
	if (temp1.length() > 0 && temp1.find_first_of(" ") == -1)
	{
		fname = temp1;
	}
	else
	{
		error = 1;
	}
}

void People::setlname(const string temp2)
{
	if (temp2.length() > 0 && temp2.find_first_of(" ") == -1)
	{
		lname = temp2;
	}
	else
	{
		error = 1;
	}
}

void People::seterror(const int temp)
{
	if (temp == 1 || temp == 0)
	{
		error = temp;
	}
}

void People::display(void) const
{
	cout << "Fname: " << fname;
	cout << "\nLname: " << lname;
}

// PEOPLE Constant member functions

int People::geterror(void) const
{
	return error;
}


string People::getfname(void) const
{
	return fname;
}

string People::getlname(void) const
{
	return lname;
}

//EMPLOYEE CONSTRUCTOR
Employee::Employee()
{
	hourlyrate = 0;
	hoursworked = 0;
	grosspay = 0;
	seterror(0);
}

//EMPLOYEE MODIFICATION MEMBERS
void Employee::sethourlyrate(const float temp)
{
	if (temp >= 8.25)
	{
		hourlyrate = temp;
	}
	else
	{
		seterror(1);
	}
}

void Employee::sethoursworked(const float temp)
{
	if (temp >= 0)
	{
		hoursworked = temp;
	}
	else
	{
		seterror(1);
	}
}

void Employee::setgrosspay(const float rate, const float work)
{
	if(work >= 0 && rate >= 8.25)
	{
		if (work > 40)
		{
			grosspay = ((rate * 40) + ((work-40) * (rate*1.5)));
			
		}
		else
		{
			grosspay = work * rate;
		}
	}
	else
	{
		seterror(1);
	}
}

void Employee::display(void) const
{
	if (geterror() == 0)
	{
		string name = getlname() + ", "  + getfname();
		cout << fixed;
		cout << setprecision(2);
		cout << name << setw(20) << grosspay << endl;	
	}
	else
	{
		cout << "This record contains bad data, cannot process" << endl;
	}

}

//EMPLOYEE CONSTANT MEMBER FUNCTIONS
float Employee::gethourlyrate(void) const
{
	return hourlyrate;
}

float Employee::gethoursworked(void) const
{
	return hoursworked;
}

float Employee::getgrosspay(void) const
{
	return grosspay;
}


