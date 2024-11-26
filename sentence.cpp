// Include directives
#include <iostream>
#include <string>
#include "sentence.h"

using namespace std;

/*********************************************************************************************************************************************************
Name: Default constructor
Pre-Conditon: State of the object has not been initialized
Post-Condition: The object has been initialized to an empty linked list
Description: The default constructor initializes the object to an empty linked list
**********************************************************************************************************************************************************/
sentence::sentence() 
{
    front = 0; // sets front = 0
    back = 0; // sets front = 0
}

/*********************************************************************************************************************************************************
Name: Explicit-value constructor
Pre-Conditon: State of the object has not been initialized
Post-Condition: The object has been initialized to a linked list containing string s
Description: The Explicit-value constructor initializes the list to string s
**********************************************************************************************************************************************************/
sentence::sentence(const string& s) 
{
    front = 0; // sets front = 0
    back = 0; // sets back = 0
    add_back(s); // function call to add_back with string s passed explicitly
}

/*********************************************************************************************************************************************************
Name: Copy constructor
Pre-Conditon: An object is passed by value, an object is returned from a function, or an object is initialized using an object of the same class
Post-Condition: The object makes a deep copy of the original
Description: The copy constructor makes a deep copy of the original object
**********************************************************************************************************************************************************/
sentence::sentence(const sentence& org) 
{
    front = 0; // sets front = 0
    back = 0; // sets back = 0
    word * p = org.front; // initializes a new word pointer to org.front
    while(p != 0) // the loop traverses sentence org
    {
        add_back(p->term); // during each iteration, the value of p->term is added to the back of the current object
        p = p->next;
    }
}

/*********************************************************************************************************************************************************
Name: Destructor
Pre-Conditon: The object has been initialized and went out of scope
Post-Condition: Dynamic memory has been de-allocated and the front = 0 and back = 0
Description: The Destructor de-allocates the dynamic memory of the linked list and sets front and back equal to 0 as it goes out of scope
**********************************************************************************************************************************************************/
sentence::~sentence() 
{
    word * p; // declares a word pointer p
    while(front != 0) // while the linked list is not empty
    {
        p = front->next; // p is set to the node ahead of front
        delete front; // front is de-allocated
        front = p; // front is set equal to p
    }
    back = 0; // once the list is empty back is set equal to 0
    cout << "Destructor called" << endl;
}

/*********************************************************************************************************************************************************
Name: Length
Pre-Conditon: The object has been initialized
Post-Condition: The number of characters contained in the linked list is returned
Description: The length function returns the number of characters contained in the linked list
**********************************************************************************************************************************************************/
int sentence::length()
{
    int count = 0; // sets count equal to zero
    word * p = front; // initializes word pointer p to front
    while(p!=0) // while p is not at the end of the list
    {
        count += p->term.length(); // adds the length of the string stored in term to count
        p = p->next;
    }
    return count; // returns count
}

/*********************************************************************************************************************************************************
Name: add_back
Pre-Conditon: The object has been initialized
Post-Condition: The linked list has string s added to the back of it
Description: The function adds string s to the back of the linked list
**********************************************************************************************************************************************************/
void sentence::add_back(const string & s) 
{
    string s1 = s; // creates a string s1 with the contents of s
    if( (s1.find(" ")!= string::npos) && (s1 != " ") ) // if s1 contains a space but is not equal to only a space
    {
        while(s1.find(" ")!= string::npos) // while s1 still contains a space
        {
            string s2 = s1.substr(0, s1.find(" ")); // s2 equals the portion of the string before the space
            s1.erase(0, s1.find(" ")+1); // the portion of s1 from the begining up to and including the space is removed from s1
            add_back(s2); // recursive function call to add_back with s2 passed explicitly
            add_back(" "); // recursive function call to add_back with a space passed explicitly
        }
    }
    
    if( s1 == "") // if s1 is empty there is nothing to be added, so the function is exited
    {
        return;
    }
    
    if( (front == 0) && (back == 0) ) // if the linked list is empty
    {
        word * p = new word; // word pointer p is equal to a new word
        p->term = s1; // the term of p is set equal to s1
        p->next = 0; // the next of p is set equal to 0
        front = p; // front equals p
        back = p; // back equals p
        return; // exit the function
    }
    else if( (front !=0) && (back!=0) ) // if the linked list is not empty
    {
        word * p = new word; // word pointer p is equal to a new word
        p->term = s1; // the term of p is set equal to s1
        p->next = 0; // the next of p is set equal to 0
        back->next = p; // the next portion of the node before p now points to p
        back = p; // back is set equal to p
        return; // exit the function
    }
    return; // exit the function
}

/*********************************************************************************************************************************************************
Name: operator<<
Pre-Conditon: The state of the object has been initialized
Post-Condition: The linked list is output with chaining
Description: The overloaded operator outputs the words contained in the linked list with chaining
**********************************************************************************************************************************************************/
ostream& operator<<(ostream& out, const sentence& org) 
{
    word * p = org.front; // sets word pointer p equal to org.front
    while(p != 0) // the loop traverses the linked list
    {
        out << p->term; // outputs the value in each node
        p = p->next;
    }
    return out; // returns the ostream so that the operator can be used with chaining
}

/*********************************************************************************************************************************************************
Name:operator=
Pre-Conditon: The state of the object has been initialized
Post-Condition: The current object is set equal to a linked list that contains string s
Description: The overloaded operator sets the current object equal to a linked list that contains string s
**********************************************************************************************************************************************************/
void sentence::operator=(const string& s) 
{
    word * p; // declares word pointer p
    while(front != 0) // traverese the list and deletes each node
    {
        p = front->next;
        delete front;
        front = p;
    }
    back = 0; // sets back equal to zero
    
    add_back(s); // function call to add_back with s passed explicitly
}

/*********************************************************************************************************************************************************
Name: operator=
Pre-Conditon: The state of the object has bee initialized
Post-Condition: The object is set equal to a linked list that contains the values of sentence w with chaining
Description: The overloaded operator sets the current object equal to a linked list that contains the values of sentence w with chaining
**********************************************************************************************************************************************************/
sentence& sentence::operator=(const sentence& w) 
{
    word * p; // declares word pointer p
    while(front != 0) // traverese the list and deletes each node
    {
        p = front->next;
        delete front;
        front = p;
    }
    back = 0; // sets back equal to zero
    
    word * p1 = w.front;
    while(p1 != 0) // traverses sentence w
    {
        add_back(p1->term); // adds each term of w to the back of the current object
        p1 = p1->next;
    }
    return *this; // returns the current object so the operator can be used with chaining
}

/*********************************************************************************************************************************************************
Name: operator+
Pre-Conditon: The state of the object has been initialized
Post-Condition: The object has sentence B added to the back of it
Description: The overloaded operator adds sentence B to the back of the current object without chaining
**********************************************************************************************************************************************************/
void sentence::operator+(sentence& B) 
{
    word * p = B.front;
    while(p != 0) // traverses sentence B
    {
        add_back(p->term); // adds each term of B to the back of the current object
        p = p->next;
    }
}

/*********************************************************************************************************************************************************
Name:isEqual
Pre-Conditon: The state of the object has been initialized
Post-Condition: True is returned if the current object is equal to sentence B, otherwise flase is returned
Description: The function returns true if the current object is equal to sentence B, otherwise flase is returned
**********************************************************************************************************************************************************/
bool sentence::isEqual(sentence& B) 
{
    if( B.length() != length() ) // if the length of the current object is not equal to that of sentence B return false
    {
        return false;
    }
    
    word * p = B.front;
    word * p1 = front;
    while(p != 0) // traverses both the current object and sentence B
    {
        if( p->term != p1->term) // compares the terms of both object
        {
            return false; // if the terms are not equal return false
        }
        p = p->next;
        p1 = p1->next;
    }
    
    return true; // if all the terms are equal return true
}

/*********************************************************************************************************************************************************
Name: remove
Pre-Conditon: The state of the object has been initialized
Post-Condition: The object has string s removed from it
Description: The function removes string s from the linked list
**********************************************************************************************************************************************************/
void sentence::remove(const string& s)
{
    string main = ""; // declares string main as an empty string
    word * p = front;
    while(p != 0) // traverses the current object
    {
        main += p->term; // appends main with the terms stored in the current object
        p = p->next;
    }
    
    if(main.find(s) != string::npos) // If s is contained withing main
    {
        main.erase(main.find(s), s.length()); // removes s from main
        *this = main; // sets the current object equal to main
    }
}
