//*********************************************************************************************
//*********************************************************************************************
//	D A T E . h

#ifndef DATE_H
#define DATE_H
#include <iostream>

using namespace std;

class Date
{
public:
	Date(); //default constructor; sets m=01, d=01, y	=0001
	Date(unsigned m, unsigned d, unsigned y); //explicit-value constructor to set date equal to input
	//Use 2-digits for month (m) and day (d), and 4-digits for year (y); this function should
	//print a message if a leap year.
	void display();//output Date object to the screen
	int getMonth();//accessor to output the month 
	int getDay();//accessor to output the day  
	int getYear();//accessor to output the year
	void setMonth(unsigned m);//mutator to change the month
	void setDay(unsigned d);//mutator to change the day
	void setYear(unsigned y);//mutation to change the year

	friend ostream& operator<<(ostream& out, Date& dateObj);//overloaded operator<< as a friend function with chaining

private:

    bool verify_year(unsigned y) { return ((y>0) && (y<=9999)); };//function to test the validity of an input for years
    // Inline implementation, it returns 1 if input is greater than 0 but less than or equal to 9999.
	bool verify_day(unsigned d, unsigned m, unsigned y);//function to test the validity of an input for days given valid month and years
	bool verify_month(unsigned m) { return ((m>0) && (m<13)); };//function to test the validity of an input for months
	// Inline implementation, it returns 1 if input is greater than 0 but less than 13
	bool is_leap(unsigned y);//function to test if a year is a leap year given a valid year

	int myMonth, myDay, myYear; //month, day, and year of a Date obj respectively
};


#endif