// Only includes this file if STRING_CLASS_H has not already been defined
#ifndef STRING_CLASS_H
#define STRING_CLASS_H

// Include directives
#include <iostream>
#include <string>

using namespace std;

// Class declaration of string_class
class string_class
{
 
public:
    string_class(); // Default constructor that sets current_string to ""
    string_class(string input); // Explicit-value constructor that sets current_string equal to string input
    bool palindrome(); // Function that tests current_string if it reads the same way forwards as backwards,
    // returns 1 if it does and 0 if it doesnt
    void replace_all(string old_substring, string new_substring); // Function that replaces all instances
    // of old_substring with new_substring within current_string
    
    friend ostream& operator<<(ostream& out, const string_class& SC); // Overloaded << operator that
    // outputs current_string to the ostream specified with chaining
    
private:
    int find_substring(string str, int flag); // helper function that returns the first index number
    // of the instance of str in current_string. If it can not find any instance it returns -1
    // Flag is used to indicate a repeat search after removal of a pervious instance
    void replace_substring(int index, string new_substring, string old_substring); // helper function
    // that replaces old_substring with new_substring within current_string at index
    string current_string; // private string data member
    
};

#endif