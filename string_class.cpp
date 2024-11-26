// Include directives
#include <iostream>
#include <string>
#include <cctype>
#include "string_class.h"

using namespace std;

/*********************************************************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: current_string has not been initialized
Post-Condition: current_string has been initialized to ""
Description: the default Constructor initializes current_string to the empty string if no explicit value is declared during the instantiation of an object
**********************************************************************************************************************************************************/
string_class::string_class()
{
    
    current_string = ""; // sets current_string equal to the empty string
    
}

/*********************************************************************************************************************************************************
Name:  Explicit-value Constructor
Pre-Conditon: current_string has not been initialized
Post-Condition: current_string has been initialized to string input
Description: the Explicit-value constructor initializes current_string with string input
**********************************************************************************************************************************************************/
string_class::string_class(string input)
{
    
    current_string = input; // sets current_string equal to input
    
}

/*********************************************************************************************************************************************************
Name:  palindrome
Pre-Conditon: current_string has been initialized
Post-Condition: returns 1 if current_string reads the same forwards as backwards, otherwise it returns false
Description: the function returns true if current_string is a palindrome, meaning is is read the same forwards or backwards. Otherwise, it returns
flase
**********************************************************************************************************************************************************/
bool string_class::palindrome()
{
    
    int length = current_string.length(); // sets length equal to the length of the current_string
    
    // if the string is empty return true
    if( (length == 0) )
    {
        return true;
    }
    
    // compares the first letter to the last letter, the second with the second to last, etc., to determine if 
    // the string reads the same forwards as it does backwards
    for(int x=0; x<length; x++)
    {
        if( !(tolower(current_string[x]) == tolower(current_string[length-x-1])) )
        {
            return false; // returns false if it is not the case
        }
        
    }
    
    return true; // Otherwise returns true
    
}

/*********************************************************************************************************************************************************
Name:  replace_all
Pre-Conditon: current_string has been initialized
Post-Condition: all instances of old_substring have been replaced by new_substring within current_string
Description: the function replaces all instances of old_substring with new_substring in current_string
**********************************************************************************************************************************************************/
void string_class::replace_all(string old_substring, string new_substring)
{
    int index=0; // set index to 0
    int flag = 0; // set flag to 0
    
    
    index = find_substring(old_substring, flag); // set index to the return value of the function call find_substring
    
    // While the index is not equal to -1
    while(index!=-1)
    {
        // function call to replace_substring
        replace_substring(index, new_substring, old_substring);
        
        // set flag equal to index + the length of new_substring
        flag = index+new_substring.length();
        
        // set index to the return value of the function call find_substring
        index = find_substring(old_substring, flag);

    }
    
}

/*********************************************************************************************************************************************************
Name:  operator<<
Pre-Conditon: current_string has been initialized
Post-Condition: the string current_string has been output to the ostream with chaining
Description: the function outputs current_string to the ostream with chaining
**********************************************************************************************************************************************************/
ostream& operator<<(ostream& out, const string_class& SC)
{
    
    out << SC.current_string << endl; // outputs current_string to the ostream out
    
    return out; // returns out so te operator can be used with chaining
    
}

/*********************************************************************************************************************************************************
Name:  find_substring
Pre-Conditon: current_string has been initialized and flag has been initialized
Post-Condition: the value of the index where the first instance of str in current_string is
Description: the function finds the index where the first instance of str in current_string is
**********************************************************************************************************************************************************/
int string_class::find_substring(string str, int flag)
{
    
    int str_length = str.length(); // set str_length equal to the length of str
    int length = current_string.length(); // set length equal to the length of current_string
    int z=0;
    
    // if flag is not equal to zero...
    // (Flag indicates if this function has been called already and it did not return -1 last time
    // and the substring was replaced and the function has been called again. This is important because
    // it prevents the function from replacing a part of current_string that has already been replaced)
    if(flag!=0)
    {
            for(int y=flag; y<(length-str_length+1); y++) // for every integer from flag to 1 less than length-str_length+1
        {
            z=0;
            
            for(int x=y; x<(str_length+y); x++) // for every integer from y to 1 less than str_length+y
            {
                
                if( !(current_string[x] == str[z]) ) // if the letter does not match break out of the loop
                {
                    break;
                }
                
                if(z<(str_length-1)) // if z < str_length-1
                {
                    z++; // increment z
                }
                else
                {
                    return y; // else return y
                }
                
            }
        }
    
    }
    
    // This if statement followed by loops and more if statements is nearly identical is form and function to the
    // previous one excpet that it is executed when flag is 0, meaning that it starts comparing the letters of current_string
    // from the beginning rather than the index specified by flag as the previous if statement did
    if(flag==0)
    {
        for(int y=0; y<(length-str_length+1); y++)
        {
            z=0;
            
            for(int x=y; x<(str_length+y); x++)
            {
                
                if( !(current_string[x] == str[z]) )
                {
                    break;
                }
                
                if(z<(str_length-1))
                {
                    z++;
                }
                else
                {
                    return y;
                }
                
            }
        }
    }
    
    return -1;
    
}

/*********************************************************************************************************************************************************
Name:  replace_substring
Pre-Conditon: current_string has been initialized and index has been initialized with
the index of the first instance of old_substring in current_string
Post-Condition: the old_substring is replaced with new_substring in current_string
Description: the function replaces the instance specifed by index of old_substring in current_string with new_substring
**********************************************************************************************************************************************************/
void string_class::replace_substring(int index, string new_substring, string old_substring)
{
    string temp = current_string + new_substring; // set temp to the concatenation of current_string and new_substring
    
    int length = temp.length(); // set length to the length of temp
    
    string temp1; // declares temp1
    
    string temp2; // declares temp2
    
    for(int x=0; x<index; x++) // for all indexs less than the one that old_substring starts at (and >= 0)
    {
        temp1.push_back(current_string[x]); // push_back the letter of current_string at index x to temp1
    }

    
    for(int x = (index+old_substring.length()); x<(current_string.length()); x++) // for all indexes greater than the end of new_substring after replacing and less than 0
    {
        temp2.push_back(current_string[x]); // push_back the letter of current_string at index x to temp2
    }
    
    current_string = temp1 + new_substring + temp2; // set current_string equal to the concatenation of temp1, new_substring, and temp2
    
}
