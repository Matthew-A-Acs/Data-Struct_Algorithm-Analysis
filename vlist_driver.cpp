// include directives
#include <iostream>
#include <string>
#include "vlist.h" 

using namespace std;

// -----------------------------------------------------------------------------
// ******* ASSIGNMENT 7 VLIST *******
// Student: Matthew Acs Z23536012
// Total Possible Points: 25
// Due Date: 11/10/2020
// Course: COP 3530 
// Assignment: Assignment 7
// Professor: Dr. Bullard
// Description: The program test the functionality of a VLIST class. The class
// uses a vector to manage dynamic memory and store an alphabetically arranged
// list of strings. The class contains a default constructor, destructor, copy
// constructor, isEmpty, search, insert, remove, and print functions. Many functions
// are implemented using vector member functions.
// -----------------------------------------------------------------------------

// Driver of the program. Intended to test the functionality of the class.
// Driver is in function driver() to better organize the program.
void driver()
{

	//Testing default constructor
	cout << "***********************************************************" << endl;
	cout << "Test1:Testing the default constructor for string\n"; 
	vlist String_List;
	cout << endl << endl;
	cout << "*****************End of Test1******************************" << endl;
	//Testing functionality for string list 
	cout << "***********************************************************" << endl;
	cout << "Test2: Testing Insert \n"; 
	String_List.insert("Hello"); 
	String_List.insert("Zebra"); 
	String_List.insert("Good_Bye"); 
	String_List.insert("Space"); 
	String_List.insert("No_One"); 
	String_List.print();
	cout << "*****************End of Test2******************************" << endl;
	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "Test 3: Testing copy constructor for string \n"; 
	vlist Copied_String = String_List; 
	Copied_String.print();
	String_List.print();
	cout << "*****************End of Test3******************************" << endl;
	cout << endl << endl;
	cout << "***********************************************************" << endl;
	cout << "Test 4: Testing Remove for string \n"; 
	cout << "Testing Search and IsEmpty also\n"; 
	String_List.remove("Zebra"); 
	String_List.remove("Good_Bye"); 
	String_List.remove("Hello"); 
	String_List.remove("No_One"); 
	String_List.remove("Space"); 
	String_List.remove("Hello");

	if (String_List.isEmpty())
	{
		cout << "String_List is Empty!"<<endl;
	}
	else
	{
		cout << "String_List is NOT Empty!" << endl;
	}
	cout << "*****************End of Test4******************************" << endl;
	cout << endl << endl;
	cout << "When leave main destructor will be called" << endl;

	return;
}

// Main function
int main()
{
    // Function call to driver()
    driver();
    return 0;
}
