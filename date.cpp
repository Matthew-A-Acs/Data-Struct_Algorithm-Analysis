//*********************************************************************************************
//*********************************************************************************************
//	D A T E	. C P P

#include <iostream>
#include "date.h"
#include<iomanip>

using namespace std;

//*************************************************************************************
//Name:	Default constructor
//Precondition: The state of the object (private data) has not been initialized
//Postcondition: The state has been initialized to 01/01/0001
//Description:	This is the default constructor which will be called automatically when
//an object is declared. It will initialize the object to the date 01/01/0001
//*************************************************************************************
Date::Date()
{
    cout << "\nDefault constructor has been called\n";
    myMonth = 1;
    myDay = 1;
    myYear = 1;
    display();
}


//*************************************************************************************
//Name:	Explicit-value constructor
//Precondition: The state of object has not been initialized
//Postcondition: The object has been initialized to the inputs if all 3 inputs are valid.
// Otherwise, the function will output which input/inputs is/are incorrect and initialize
// the object to 01/01/0001. If the input is valid and it is a leap year, the program
// will output a message to indicate that it is.
//Description: The constructor will initialize the object to the inputs if they are valid.
// Else, it will initialize to the date 01/01/0001.
//*************************************************************************************
Date::Date(unsigned m, unsigned d, unsigned y)
{
    int flag = 1;
    int v = 1;
    
    cout << "\nExplicit-value constructor has been called\n";

    if(!verify_month(m))
    {
        cout << "Month = " << setw(2) << setfill('0') << m << " is incorrect\n";
        flag = 0;
    }
    
    if(!verify_day(d, m, y))
    {
        cout << "day = " << setw(2) << setfill('0') << d << " is incorrect\n";
        flag = 0;
    }

    if(!verify_year(y))
    {
        cout << "Year = " << setw(4) << setfill('0') << y << " is incorrect\n";
        flag = 0;
        v = 0;
    }
    
    if(flag)
    {
        myMonth = m;
        myDay = d;
        myYear = y;
        display();
    
        if( is_leap(y) )
            cout << "This is a leap year\n";
    }
    else
    {
        myMonth = 1;
        myDay = 1;
        myYear = 1;
    }

}

//*************************************************************************************
//Name:	Display
//Precondition: The object has been initialized.
//Postcondition: The date contained within the object is output to the screen.
//Description: The function outputs the date to the screen in the format
// xx/xx/xxxx, where any blank xs are filled in by zeros
//*************************************************************************************
void Date::display()
{

    cout << setw(2) << setfill('0') << myMonth 
        << "/" << setw(2) << setfill('0') << myDay 
        << "/" << setw(4) << setfill('0') << myYear << endl;

}

//*************************************************************************************
//Name:	getMonth
//Precondition: the object is initialized
//Postcondition: the value of private data member myMonth is returned
//Description: the function returns the myMonth data member of the object
//*************************************************************************************
int Date::getMonth()
{
    
	return myMonth;

}
 
//*************************************************************************************
//Name:	getDay
//Precondition: the object is initialized
//Postcondition: the value of private data member myDay is returned
//Description: the function returns the myDay data member of the object
//*************************************************************************************
int Date::getDay()
{
    
    return myDay;

}

//*************************************************************************************
//Name:	getYear
//Precondition: the object is initialized
//Postcondition: the value of private data member myYear is returned
//Description: the function returns the myYear data member of the object
//*************************************************************************************
int Date::getYear()
{

	return myYear;

}

//*************************************************************************************
//Name: setMonth
//Precondition: the object is initialized
//Postcondition: the private data member myMonth is changed to the input if the
// input is valid
//Description: the function changes the private data member myMonth to the input
// if the input is valid. Otherwise it will output a message saying that the input
// is invalid
//*************************************************************************************
void Date::setMonth(unsigned m)
{

    if( verify_month(m) )
    {
        if( verify_day(myDay, m, myYear) )
            myMonth = m;
        else
        {
            cout << "Month can't be changed to " << setw(2) << setfill('0') << m << " because ";
            cout << "that month can't have " << myDay << " days!\n";
        }
    }
    else
    {
        cout << "Month = " << setw(2) << setfill('0') << m << " is incorrect\n";
    }

}

//*************************************************************************************
//Name:	setDay
//Precondition: the object is initialized
//Postcondition: the private data member myDay is changed to the input if the
// input is valid
//Description: the function changes the private data member myDay to the input
// if the input is valid. Otherwise it will output a message saying that the input
// is invalid
//*************************************************************************************
void Date::setDay(unsigned d)
{

    if(verify_day(d, myMonth, myYear))
        myDay = d;
    else
    {
        cout << "Day can't be changed to " << setw(2) << setfill('0') << d << " because ";
        cout << "that month can't have " << d << " days!\n";
    }

}

//*************************************************************************************
//Name:	setYear
//Precondition: the object is initialized
//Postcondition: the private data member myYear is changed to the input if the
// input is valid
//Description: the function changes the private data member myYear to the input
// if the input is valid. Otherwise it will output a message saying that the input
// is invalid
//*************************************************************************************
void Date::setYear(unsigned y)
{
    
    if( verify_year(y) )
    {
        if( verify_day(myDay, myMonth, y) )
        {
            myYear = y;
            
            if(is_leap(y))
                "This is a leap year\n";
        }
        else
        {
            cout << "Year can't be changed to " << setw(4) << setfill('0') << y << " because ";
            cout << "that year can't have "; 
            cout << setw(2) << setfill('0') << myMonth 
            << "/" << setw(2) << setfill('0') << myDay << endl;
        }
    }
    else
    {
        cout << "Year = " << setw(4) << setfill('0') << y << " is incorrect\n";
    }

}

//*************************************************************************************
//Name:	operator<<
//Precondition: the object is initialized
//Postcondition: The date contained within the object is output to the ostream
// with chaining.
//Description: the function overloads the << operator with chaining. The operator
// will output the date and then use chaining to output any other date.
//*************************************************************************************
ostream& operator<<(ostream& out, Date& dateObj)
{
    out << setw(2) << setfill('0') << dateObj.myMonth 
        << "/" << setw(2) << setfill('0') << dateObj.myDay 
        << "/" << setw(4) << setfill('0') << dateObj.myYear;

	return out;

}

//*************************************************************************************
//Name:	verify_day
//Precondition: N/A
//Postcondition: If the date given by m/d/y is valid, the function will retrun 1.
// Otherwise, the function will return 0.
//Description: Given a date m/d/y, assuming m is valid and y is valid, the function
// will test the date and return 1 if it is valid or 0 if it is not.
//*************************************************************************************
bool Date::verify_day(unsigned d, unsigned m, unsigned y)
{
    
    if( (d<=31) && ( (m==1) || (m==3) || (m==5) || (m==7) || (m==8) || (m==10) || (m==12) ) )
        return 1;
    else if ( (d<=30) && ( (m==4) || (m==6) || (m==9) || (m==11) ) )
        return 1;
    else if ( (d<=28) && (m==2) )
        return 1;
    else if ( (d<=29) && (m==2) && ( is_leap(y) ) )
        return 1;
    else if ( (d<=31) && ( (m<=0) || (m>=13) ) )
        return 1;
    else
        return 0;
    
}

//*************************************************************************************
//Name:	is_leap
//Precondition: N/A
//Postcondition: If the year is a leap year the function will return 1. If not
// it will return 0.
//Description: The function tests a given year y and returns 1 if it is a leap year.
//*************************************************************************************
bool Date::is_leap(unsigned y)
{
    
    if ( ( y%4 == 0 ) && ( y%100 != 0) )
        return 1;
    else if( y%400 == 0)
        return 1;
    else
        return 0;
    
}