// CLASSES PROVIDED:  People (Base Class) and Employee (Derived Class)
//
// CONSTRUCTOR for the People class:
//   Customer()
//     Description:		constructor will initialize Customer objects
//     Preconditions:	none
//     Postcondition:	fname and lname  are set to blank
//
// MODIFICATION MEMBER FUNCTIONS for the People class
//   void setfname (const string value)
//     Description:		sets a value to the fname variable
//     Precondition:	musst return a number > 0 when put through length() function
//     Postcondition:	fname has been set to value
//
//   void setfname (const string value)
//     Description:		sets a value to the lname variable
//     Precondition:	must return a number > 0 when put through length() function
//     Postcondition:	lname has been set to value
//
//	 void seterror (const int value)
//		Description:	sets a value to the error variable
//		Precondition:	none
//		Postcondition:	Error has been set to value
//
//  void display (void) const
//		Description:	print out the values read from the file on the screen
//		Precondtion:	none
//		Postcondition:	values print to cout
//
// CONSTANT MEMBER FUNCTIONS for the People class
//   int geterror (void) const
//		Description: return the value of the error variable
//		Preconditions: none
//		Postcondition: value of error is returned
//
//	string getfname (void) const
//		Description: return value of fname
//		Preconditions: none
//		Postconditions: value of fname returned
//
//		string getlname (void) const
//		Description: return value of lname
//		Preconditions: none
//		Postconditions: value of lname returned
//
//	CONSTRUCTOR for the Employee class:
//		Employee()
//			Description: constructor will initialize Employee Objects
//			Precondition: none
//			Postcondition: hourlyrate, hoursworked, and gross pay are set to 0
// MODIFICATION MEMBER FUNCTIONS
//
// MODIFICATION MEMBER FUNCTIONS for the People class
//   void sethourlyrate (const float value)
//     Description:		sets a value to the hourlyrate variable
//     Precondition:	value must be a float number with only one decimal and greater than 8.25
//     Postcondition:	hourlyrate has been set to value
//
//   void sethoursworked (const float value)
//     Description:		sets a value to the hoursworked variable
//     Precondition:	value must be a float greater than 0
//     Postcondition:	hoursworked has been set to value
//
//	 void setgrosspay (const float hoursworked, const float hourlyrate)
//		Description:	calculates gross variable by multiplying the two floats. Time and half calculated if hoursworked is greater than  40
//		Precondition:	hoursworked must be greater than 0 and hourlyrate must be greater than 8.25
//		Postcondition:	Error has been set to value
//
//  void display (void) const
//		Description:	print out the values read from the file on the screen or prints error statement
//		Precondtion:	none
//		Postcondition:	values print to cout
//
// CONSTANT MEMBER FUNCTIONS for the Employee class
//   float gethourlyrate (void) const
//		Description: return the value of the hourlyrate
//		Preconditions: none
//		Postcondition: value of hourlyrate is returned
//
//	float hoursworked (void) const
//		Description: return value of hoursworked
//		Preconditions: none
//		Postconditions: value of hoursworked returned
//
//	float getgrosspay (void) const
//		Description: return value of grosspay
//		Preconditions: none
//		Postconditions: value of grosspay returned

#ifndef EMPLOYEE_H
#define EMPLOYEEh_H
#include <string>
#include <fstream>
class People
{
  public:
    // CONSTRUCTOR
    People();
    

    //CONSTANT MEMBER FUNCTIONS
    int geterror(void) const;
    std::string getfname(void) const;
    std::string getlname(void) const;
    

    // MODIFICATION MEMBER FUNCTIONS
    void setfname(const std::string);
    void setlname(const std::string);
    void seterror(const int);
    void display(void) const;

  private:
  	std::string fname;
  	std::string lname;
    int error;
};

class Employee: public People
{
	public:
		Employee();
		
		//CONSTANT MEMBER FUNCTIONS
		float gethourlyrate(void) const;
		float gethoursworked(void) const;
		float getgrosspay(void) const;
		
		//MODIFICATION MEMBER FUNCTIONS
		void sethourlyrate(const float);
		void sethoursworked(const float);
		void setgrosspay(const float, const float);
		void display(void) const;
	
	private:
		float hourlyrate;
		float hoursworked;
		float grosspay;
		
		
};

#endif