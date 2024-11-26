// Only defines stack_h if it has not already been defined
#pragma once

// include directives
#include <iostream>
#include <string>

using namespace std;

class stack // declares class stack
{
    public:
        stack(); // default constructor: initializes the object to an empty stack
        stack(const string & input); // explicit-value constructor: initializes the object to contain string input
        stack(const stack & org); // copy constructor: makes a deep copy of the original object
        ~stack(); // destructor: de-allocates all dynamic memory when the object goes out of scope
        void push(const string & input); // push: Push pushes the input onto the stack
        void pop(); // pop: removes the top-most node in the stack and de-allocates dynamic memory 
        string access_top(); // access_top: returns the term of the top node in the stack
        bool empty(); // empty: returns true if the stack is empty, else, false is returned
        void display(); // display: outputs the contents of the stack to the screen
        void operator=(const stack & org); // operator=: sets the object equal to another stack object
        int length(); // length: returns the length of the current stack object
    
    private:
    
        class node // declares class node
        {
            public:
                node * next; // data member node pointer next
                string term; // data member string term
        };
        
        node * top; // private data member node pointer top
};

