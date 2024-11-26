// include directives
#include "stack.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// -----------------------------------------------------------------------------
// ******* ASSIGNMENT 5 Postfix To Infix *******
// Student: Matthew Acs Z23536012
// Total Possible Points: 25
// Due Date: 10/20/2020
// Course: COP 3530 
// Assignment: Assignment 5
// Professor: Dr. Bullard
// Description: The program converts a input of postfix notation to infix notation.
// It utilizes a stack class and uses error checking to make sure that the
// user enters appropriate inputs. It also allows the user to input as many expressions
// to be converted untill the user exits the program.
// -----------------------------------------------------------------------------

/*********************************************************************************************************************************************************
Name: Rspace
Pre-Conditon: The function has been called and a string has been explicitly passed to it
Post-Condition: All the spaces in string input have been removed
Description: The function removes all spaces in an input
**********************************************************************************************************************************************************/
void Rspace(string & input)
{        
    int nospace = 0; // declare integer nospace and set it equal to zero
    int length = input.length(); // declare integer length and set it equal to the length of the string input
    
    for(int i = 0; i<length; i++) // traverse the length of the string input
    {            

        if(input[i] != ' ') // if a character in input is not a space
        {
            input[nospace] = input[i]; // set input at index nospace equal to input at index i
            nospace++; // increment nospace

        }
    }
    input = input.substr(0,nospace); // input is equal to the substring of input starting at position 0 and having length nospace
    
}

/*********************************************************************************************************************************************************
Name: postfix_to_infix
Pre-Conditon: The function has been called and a string has been explicitly passed to it
Post-Condition: The infix version of the postfix expression in string input has been returned
Description: The function converts a postfix expression to an infix expression
**********************************************************************************************************************************************************/
string postfix_to_infix(const string & input)
{
    if(input.length() == 0) // If the length of the input is zero
    {
        return ""; // return an empty string
    }
    stack s; // declares stack s
    for(int i = 0; i < input.length(); i++) // traverse the length of the input
    {
        char c = input [i];
        if(isalpha(c)) // if c is a letter
        {
            if(input.length() == 1) // if the length of the input is 1
            {
                string temp; // declare string temp
                temp.push_back(c); // push_back char c in temp
                s.push(temp); // push temp onto stack s
                return ("(" + s.access_top() + ")"); // return the letter with parenthesis surrounding it
            }
        
            string temp; // declare string temp
            temp.push_back(c); // push_back char c in temp
            s.push(temp); // push temp onto stack s
        }
        else if( (c == '+') || (c == '-') || (c == '*') || (c == '/') ) // If c is an operator
        {
            string temp; // push temp onto stack s
            temp.push_back(c); // push_back char c in temp
            string temp1 = s.access_top(); // string temp1 equals the top of stack s
            s.pop(); // pop the top element of stack s
            string temp2 = s.access_top(); // string temp2 equals the top of stack s
            s.pop(); // pop the top element of stack s
            s.push("(" + temp2 + " " + temp + " " + temp1 + ")"); // push the expression onto the stack
        }
        else // if invalid input is detected
        {
            cout << "Invalid input!\n"; // output invalid input statement
            return ""; // return an empty string
        }
    }
    return s.access_top(); // return the top of the stack
}

/*********************************************************************************************************************************************************
Name: test
Pre-Conditon: The function has been called and a string has been explicitly passed to it
Post-Condition: If the input is a valid postfix expression, the funciton returns true, else, false
Description: The function returns true if the input is a valid postfix expression, else, false
**********************************************************************************************************************************************************/
bool test(const string & input)
{
    int od_count = 0, op_count = 0; // set int od_count and op_count to zero
    for(int i = 0; i < input.length(); i++) // traverse the input
    {
        char c = input [i];
        if(isalpha(c)) // if c is a letter
        {
            od_count++; // increment od_count
        }
        else if( (c == '+') || (c == '-') || (c == '*') || (c == '/') ) // if c is an operator
        {
            op_count++; // increment op_count
        }
        else // if input is invalid
        {
            cout << "Invalid input!\n"; // output invalid input message
            return 0; // return false
        }
    }
    
    if( (op_count == od_count-1) || ((op_count == 0) && (od_count == 1)) ) // if there is one less operator than operands or there is only one operand
    {
        return 1; // return true
    }
    else if(((op_count == 0) && (od_count == 0))) // if there is zero operators and operands
    {
        return 1; // return true
    }
    else if( (op_count > od_count-1) ) // if there are too many operators
    {
        cout << "Too many operators and not enough operands!\n"; // print error message
        return 0; // return false
    }
    else if( (op_count < od_count-1) ) // if there are too many operands
    {
        cout << "Too many operands and not enough operators!\n"; // print error message
        return 0; // return false
    }
    return 1; // return true
}

int main()
{
    string control; // declare string control
    string input; // declare string input
    cout << "POSTFIX TO INFIX CONVERTER\n(use letters for operands and + - * / for operators)\n(enter one space between each operator/operand)\n";
    do
    {
        cout << "Enter postfix expression: "; // prompts user to enter input
        getline(cin, input); // gets a line of input
        Rspace(input); // calls Rspace
        if(test(input)) // if the input is valid
        {
            input = postfix_to_infix(input); // postfix_to_infix is called
            cout << input; // result is output
        }
        cout << "\nWould you like to convert another expression?(y or n)\n"; // prompts user if they would like to continue
        getline(cin, control); // get a line of input
    } while (control == "y"); // while user enter y, keep running program
}