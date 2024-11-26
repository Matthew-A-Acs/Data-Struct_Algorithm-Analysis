//*********************************************************************************************
//*********************************************************************************************
//	D A T E	D R I V E R . C P P

#include <iostream>
#include "date.h"

using namespace std;

// -----------------------------------------------------------------------------
// ******* ASSIGNMENT 2 DATE ClASS *******
// Student: Matthew Acs Z23536012
// Total Possible Points: 25
// Due Date: 9/15/2020
// Course: COP 3530 
// Assignment: Assignment 2
// Professor: Dr. Bullard
// Description: The program test the functionallity of the Date ADT. The 
// ADT has a default constructor, explicit-value constructor, display function,
// accessor functions for the month day and year, and mutator functions
// for the month day and year. The << is also overloaded with chaining.
// -----------------------------------------------------------------------------

int main()
{

	Date myDate;
	Date herDate(11, 14, 1953);
	Date test1Date(25, 1, 1982); //should generate error message that bad month
	Date test22Date(2, 29, 2020); //ok, should say leep year
	Date test3Date(2, 30, 2021); //should generate error message that bad day
	Date test4Date(1, 25, 0000); //should generate error message that bad year
	Date test5Date(80, 40, 0000); //should generate error message that bad month, day and year

	herDate.display();
	cout << herDate.getMonth() << endl;
	cout << herDate.getDay() << endl;
	cout << herDate.getYear() << endl;
	myDate.setMonth(11);
	myDate.setDay(12);
	myDate.setYear(2015);
	cout << "myDate: " << myDate << " test22Date: " << test22Date << " herDate: " << herDate << endl;

	return 0;

}
