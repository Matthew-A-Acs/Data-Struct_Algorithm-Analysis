// include directive
#include <iostream>

using namespace std;

// -----------------------------------------------------------------------------
// *******ASSIGNMENT 8b Know_Recursion_and_Lists*******
// Student: Matthew Acs Z23536012
// Total Possible Points: 25
// Due Date: 11/17/2020
// Course: COP 3530 
// Assignment: Assignment 8b
// Professor: Dr. Bullard
// Description: The program uses recursion to output part of a singly linked
// list to the screen. The singly linked list is implemented using a node
// class and two node pointers front and back. Function add_back adds nodes
// to the singly linked list and fun outputs part of the linked list to 
// the screen.
// -----------------------------------------------------------------------------

// declaration of class node
class node
{
    public:
    
    int data; // int data member
    node * next; // node pointer next data member
};

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: fun
//Precondition: a node pointer is initialized
//Postcondition: uses recursion to output parts of the linked list to the screen
//Description: the function recursively outputs parts of the data of the linked list
///////////////////////////////////////////////////////////////////////////////////////////////
void fun(node * start)
{
    if(start == NULL) // if start points to NULL
        return;
        
    cout << start->data; // output data associated with start
    
    if(start->next != NULL) // if next associated with start is not pointing to null
        fun(start->next->next); // call fun with start->next->next
        
    cout << start->data; // output data associated with start
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: add_back
//Precondition: two node pointers front and back are initialized
//Postcondition: a new node is added to the back of a singly linked list maintained by front and back with data x
//Description: the function adds a node to the back of a singly linked list maintained by node pointers front and back
///////////////////////////////////////////////////////////////////////////////////////////////
void add_back(node * & front, node * & back, int x)
{
    if( (front == 0) && (back == 0) ) // if front and back both point to null
    {

        front = new node; // set front equal to a new node
        front->data = x; // set data associated with front to x
        front->next = 0; // set next associated with front to 0
        back = front; // set back equal to front
    }
    else
    {
        
        node * p = new node; // set node pointer p equal to a new node
        p->data = x; // set data associated with p to x
        p->next = 0; // set next associated with p to 0
        back->next = p; // set next associated with back to p
        back = p; // set back equal to p
    }
}

int main()
{
    node* front = 0; // set node pointer front equal to null
    node* back = 0; // set node pointer back equal to null
    
    for (int i = 1; i <= 6; i++) // iterate from i=1 to i=6
    {
        add_back(front, back, i); // call to function add_back
    }
    
    fun(front); // call to function fun with formal parameter front
    return 0;
}



