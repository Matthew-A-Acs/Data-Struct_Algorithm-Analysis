// include directives
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// -----------------------------------------------------------------------------
// ******* ASSIGNMENT 8a Recursive Functions *******
// Student: Matthew Acs Z23536012
// Total Possible Points: 25
// Due Date: 11/17/2020
// Course: COP 3530 
// Assignment: Assignment 8a
// Professor: Dr. Bullard
// Description: The program tests the functionality of two recursive functions 
// and one iterative function. The function palidrome returns true if the function 
// is a palindrome and false otherwise. The function printReversel returns a reversed 
// string using recursion and the function printIterReverse returns a reversed string 
// using iteration rather than recursion.
// -----------------------------------------------------------------------------

// function prototypes
bool palindrome(string & s);
string printReversel(string & s);
string printIterReverse(string & s);

int main()
{
    string control; // declares string control
    string s; // declares string s
    
    do{
        cout << "----------------------\nPlease enter a string: "; // prompts user for input
        getline(cin, s); // reads input from user into s
        cout << endl;
        
        cout << "---Testing for palindrome---\n"; // outputs a message
        if(palindrome(s)) // if function call to palindrome returns true
            cout << s << " is a palindrome!\n\n"; // output that the string is a palindrome
        else
            cout << s << " is not a palindrome!\n\n"; // output that the string is not a palindrome
        
        cout << "---Reversing string using recursive function---\n"; // outputs a message
        cout << "Reversed string is " << printReversel(s) << endl << endl; // outputs string returned by function call to printReversel
        
        cout << "---Reversing string using iterative function---\n"; // outputs a message
        cout << "Reversed string is " << printIterReverse(s) << endl << endl; // outputs string returned by function call to printIterReverse
        
        cout << "Would you like to try another string? (y or n): "; // prompts user to input
        getline(cin, control); // reads user input into control
    
    }while (control == "y"); // while user inputs "y" continue program
    
    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: palindrome
//Precondition: a string is initialized
//Postcondition: true is returned if the string is a palindrome and flase if it is not
//Description: the function checks if the input is a palindrome using a recursive implementation
///////////////////////////////////////////////////////////////////////////////////////////////
bool palindrome(string & s)
{
    if( (s.length() == 1) || (s.length() == 2) ) // if the length of the string is 1 or 2
    {
        return (s[0] == s[(s.length()-1)]); // return true if the first and last letters are equal else false
    }
    else if ( s[0] == s[(s.length()-1)] ) // else if the first and last letters are equal
    {
        string temp = s.substr(1, (s.length()-2)); // store a substring of s without the first and last letters into temp
        return palindrome(temp); // returns value that function call palindrome returns
    }
    else // otherwise return false
    {
        return false;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: printReversel
//Precondition: a string is initialized
//Postcondition: the reversed string is returned
//Description: the function returns a reversed string using a recursive implementation
///////////////////////////////////////////////////////////////////////////////////////////////
string printReversel(string & s)
{
    if(s.length() == 0) // if the length of the string is 0
    {
        return ""; // return an empty string
    }
    string x = s.substr(0,s.length()-1); // store a substring of s without the last letter into temp
    return s[s.length()-1] + printReversel(x); // returns the last letter of s appended with the value that printReversel returns
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: printIterReverse
//Precondition: a string is initialized
//Postcondition: the reversed string is returned
//Description: the function returns a reversed string using an iterative implementation
///////////////////////////////////////////////////////////////////////////////////////////////
string printIterReverse(string & s)
{
    int i; // declares int i
    string temp; // declares string temp
    stack<char> x; // declares a stack of chars x
    
    for(i = 0; i < s.length(); i++) // traverse all values of i for the length of the string
    {
        x.push(s[i]); // push s[i] onto the stack
    }
    
    for(i = 0; i < s.length(); i++) // traverse all values of i for the length of the string
    {
        temp += x.top(); // append the top of the stack to temp
        x.pop(); // pop a value from the stack
    }
    
    return temp; // return the string temp
}


