// include directives
#include "stack.h"
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************************************************************************************************
Name: Default constructor
Pre-Conditon: The object has not been initialized
Post-Condition: The object is initialized to an empty stack
Description: The default constructor initializes the object to an empty stack
**********************************************************************************************************************************************************/
stack::stack()
{
    top = 0; // sets top equal to zero
}

/*********************************************************************************************************************************************************
Name: Explicit-value constructor
Pre-Conditon: The object has not been initialized
Post-Condition: The object is initialized to a stack that contains string input
Description: The explicit-value constructor initializes the object to contain string input
**********************************************************************************************************************************************************/
stack::stack(const string & input)
{
    top = 0; // sets top equal to zero
    push(input); // calls function push and explicitly passes input
}

/*********************************************************************************************************************************************************
Name: Copy constructor
Pre-Conditon: An object is passed by value, an object is returned from a function, or an object is initialized using an object of the same class
Post-Condition: The object makes a deep copy of the original
Description: The copy constructor makes a deep copy of the original object
**********************************************************************************************************************************************************/
stack::stack(const stack & org)
{
    top = 0; // sets top equal to zero
    stack temp; // declares a new stack object called temp
    
    node * p = org.top; // points to the top of stack org with pointer p
    while(p != 0) // while p is not zero
    {
        temp.push(p->term); // pushes the term p is pointing to onto stack temp    
        p = p->next; // moves p to point to the next node in the stack it is pointing to
    }
    
    p = temp.top; // p is set to point to the top of stack temp
    while(p != 0) // while p is not zero
    {
        push(p->term); // pushes the term p is pointing to onto the current object   
        p = p->next; // moves p to point to the next node in the stack it is pointing to
    }
    
}

/*********************************************************************************************************************************************************
Name: Destructor
Pre-Conditon: The object has been initialized and went out of scope
Post-Condition: Dynamic memory has been de-allocated
Description: The destructor de-allocates all dynamic memory when the object goes out of scope
**********************************************************************************************************************************************************/
stack::~stack()
{
    while(!empty())
    {
        pop();
    }
}

/*********************************************************************************************************************************************************
Name: Push
Pre-Conditon: The object has been initialized
Post-Condition: String input has been pushed onto the stack
Description: Push pushes the input onto the stack
**********************************************************************************************************************************************************/
void stack::push(const string & input)
{
    if(empty()) // If the stack is empty
    {
        top = new node; // declares a new node
        top -> next = 0; // sets the next of the node to zero
        top -> term = input; // sets the term of the input to input
        return; // exits the function
    }
    else // If the stack is not empty
    {
        node * temp = top; // declares a node pointer temp that is equal to top
        top = new node; // declares a new node
        top -> next = temp; // sets the next of the node equal to temp
        top -> term = input; // sets the term of the node equal to input
    }
}

/*********************************************************************************************************************************************************
Name: Pop
Pre-Conditon: The object has been initialized
Post-Condition: The top-most node in the stack is popped
Description: The function removes the top-most node in the stack and de-allocates dynamic memory
**********************************************************************************************************************************************************/
void stack::pop()
{
    if(empty()) // If the stack is empty
    {
        return; // Exit the function because no elements can be removed
    }
    else // If the stack is not empty
    {
        node * temp = top; // declare node pointer temp to equal top
        top = temp->next; // top is equal to the node before the top of the stack
        delete temp; // de-allocates the dynamic memory the temp is pointing to
    }
}

/*********************************************************************************************************************************************************
Name: access_top
Pre-Conditon: the object has been initialized
Post-Condition: the term of the top node in the stack is returned
Description: the function returns the term of the top node in the stack
**********************************************************************************************************************************************************/
string stack::access_top()
{
    if(top!=0) // If the stack is not empty
    {
        return top->term; // return the term of the top node
    }
    else // If the stack is empty
    {
        cerr << "Stack empty: can't return top!"; // Print a message telling the user that the stack is empty
        exit(1); // exit the program
    }
}

/*********************************************************************************************************************************************************
Name: empty
Pre-Conditon: the object has been initialized
Post-Condition: true is returned if top equals zero, else, false is returned
Description: the function returns true if the stack is empty, else, false is returned
**********************************************************************************************************************************************************/
bool stack::empty()
{
    return (top == 0); // returns true if top equals zero, false if otherwise
}

/*********************************************************************************************************************************************************
Name: display
Pre-Conditon: the object has been initialized
Post-Condition: the stack has been output to the screen
Description: the function outputs the contents of the stack to the screen
**********************************************************************************************************************************************************/
void stack::display()
{
    node * p = top; // declare node pointer p and set it equal to top
    while(p!=0) // while p is not at the end of the stack
    {
        cout << p->term; // output the term that p is pointing to
        p=p->next; // set p equal to the next node
    }
}

/*********************************************************************************************************************************************************
Name: operator=
Pre-Conditon: the object has been initialized
Post-Condition: the object has been set equal to the formal parameter
Description: the overloaded operator sets the object equal to another stack object
**********************************************************************************************************************************************************/
void stack::operator=(const stack & org)
{
    stack org1 = org; // declares a new stack that is equal to stack org
    this->~stack(); // destructs the current object
    
    stack temp; // declares a stack temp
    
    node * p = org1.top; // declares node pointer p to be equal to the top of stack org1
    while(p != 0) // while p is not at the end of the stack
    {
        temp.push(p->term); // push the term p is pointing to onto stack temp
        p = p->next; // set p to point to the next node
    }
    
    p = temp.top; // set p equal to the top of stack temp
    while(p != 0) // while p is not at the end of the stack
    {
        push(p->term); // push the term that p is pointing to onto the current object
        p = p->next; // set p to point to the next node
    }
    
}

/*********************************************************************************************************************************************************
Name: length
Pre-Conditon: the object has been initialized
Post-Condition: the length of the stack is returned
Description: the function returns the length of the current stack object
**********************************************************************************************************************************************************/
int stack::length()
{
    int count = 0; // declare count to equal zero
    node * p = top; // declare node pointer p to point to the top of the stack
    while(p!=0) // while p is not at the end of the stack
    {
        count++; // increment count
        p=p->next; // set p to point to the next node
    }
    return count;
}