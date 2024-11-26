// Include directives
#include <iostream>
#include <fstream>
#include <string>
#include "string_class.h"

using namespace std;

// -----------------------------------------------------------------------------
// ******* ASSIGNMENT 3 String_Class *******
// Student: Matthew Acs Z23536012
// Total Possible Points: 25
// Due Date: 9/22/2020
// Course: COP 3530 
// Assignment: Assignment 3
// Professor: Dr. Bullard
// Description: The program tests the functionallity of the string_class ADT. The 
// ADT contains a default constructor, explicit-value constructor, a function that
// tests if the string is a palindrome, a function that replaces all instances
// of a specific string with a string, and the overloaded << operator to output
// the contents of the class.
// -----------------------------------------------------------------------------

// Main driver to test program
int main()
{
	string_class s;

	cout << "****************************************" << endl
		<< "Test#1: tesing default constructor and overloaded operator<< with chaining\n"
		<< s << "1st blank line" << endl << s << "2nd blank line" << endl
		<< "Test#1 Ended" << endl
		<< "****************************************" << endl;
	string_class r("hello");
	cout << "****************************************" << endl
		<< "Test#2: tesing explicit-value constructor and overloaded operator<< with chaining\n"
		<< r << endl << "1st blank line" << endl << r <<endl<< "2nd blank line " << endl
		<< "Test#2 Ended" << endl
		<< "****************************************" << endl;
	cout << "****************************************" << endl
		<< "Test#3: tesing palindrome\n"
		<< "****************************************" << endl;
	string response = "Y";
	string ss;
	while (response == "Y" || response == "y")
	{
		cout << "Enter String: ";
		getline(cin, ss);
		string_class main_string(ss);

		if (main_string.palindrome())
		{
			cout << ss << " is a palindrome\n";
		}
		else
		{
			cout << ss << " is not a palindrome\n";
		}
		cout << "Would you like to try another string? (Y or N):   ";
		getline( cin,response);
	}
	cout << "Test#3 Ended" << endl
		<< "****************************************" << endl;
	cout << "****************************************" << endl
		<< "Test#4: tesing replace_all\n"
		<< "****************************************" << endl;
	response = "y";
	string current, old_substring, new_substring;
	while (response == "Y" || response == "y")
	{
		cout << "Enter value for current_string: ";
		getline(cin, current);
		string_class current_string(current);
		cout << "Enter old_substring: ";
		getline(cin, old_substring);
		cout << "Enter new_substring: ";
		getline(cin, new_substring);
		cout << "Current Value in Current string = " << current << endl;
		current_string.replace_all(old_substring, new_substring);
		cout << "New value in Current String = " << current_string << endl;
		cout<< endl;
		cout << "Would you like to try another string? (Y or N):   ";
		getline(cin, response);
		cout << endl;
	}
	cout << "****************************************" << endl
		<< "End Test#4: tesing replace\n"
		<< "****************************************" << endl;
	return 0;
}