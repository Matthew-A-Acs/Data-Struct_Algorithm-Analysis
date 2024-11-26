// Include directives
#include "bqueue.h"
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************************************************************************************************
Name: Default constructor
Pre-Conditon: The object has not been initialized
Post-Condition: The object is initialized to an empty queue
Description: The default constructor initializes the object to an empty queue
**********************************************************************************************************************************************************/
bqueue::bqueue()
{
    front = 0; // sets front equal to zero
}

/*********************************************************************************************************************************************************
Name: Destructor
Pre-Conditon: The object has gone out of scope
Post-Condition: Dynamic memory has been deallocated
Description: The destructor deallocates dynamic memory
**********************************************************************************************************************************************************/
bqueue::~bqueue()
{
    while(front != 0) // while the queue is not empty, remove a node from the queue
    {
        dequeue(); // function call to dequeue
    }
}

/*********************************************************************************************************************************************************
Name: Copy constructor
Pre-Conditon: An object is passed by value, an object is returned from a function, or an object is initialized using an object of the same class
Post-Condition: The object makes a deep copy of the original
Description: The copy constructor makes a deep copy of the original object
**********************************************************************************************************************************************************/
bqueue::bqueue(const bqueue& org)
{
    front = 0; // sets front equal to zero
    bqnode * p = org.front; // p points to the front of org
    do
    {
        enqueue(p->priority); // enqueue the first element of org to the current object
        p = p->prev; // traverse the queue
        
    }while(p!=org.front); // exit loop after entire queue has been traversed
}

/*********************************************************************************************************************************************************
Name: Enqueue
Pre-Conditon: The object has been initialized
Post-Condition: An integer has been added to the queue
Description: The function adds a node to the back of the queue that contains the input
**********************************************************************************************************************************************************/
void bqueue::enqueue(int input)
{
    if(front == 0) // if the queue is empty
    {
        front = new bqnode; // front is equal to a new node
        front->priority = input; // sets priority to input
        front->prev = front; // sets front prev to front
        front->next = front; // sets front next to front
    }
    else if ( (front->prev == front) && (front->next == front) ) // if the queue contains one element
    {
        bqnode * p = new bqnode; // p points to a new node
        p->priority = input; // sets priority to input
        p->prev = front; // sets p prev to front 
        p->next = front; // sets p next to front
        front->prev = p; // sets front prev to p
        front->next = p; // sets front next to p
    }
    else // all other cases
    {
        bqnode * p = new bqnode; // p points to a new node
        p->priority = input; // sets p priority to input
        p->prev = front; // sets p prev to front
        p->next = front->next; // sets p next to front next
        front->next = p; // sets front next to p
        p = p->next; // sets p to p next
        p->prev = front->next; // sets p prev to front next
    }
}

/*********************************************************************************************************************************************************
Name: dequeue
Pre-Conditon: The object has been initialized
Post-Condition: A node has been removed from the front of the queue
Description: The function removes a node from the front of the queue
**********************************************************************************************************************************************************/
void bqueue::dequeue()
{
    if(front == 0) // if the queue is empty
    {
        cout << "Can't dequeue because queue is empty!" << endl; // send message
        return; // exit function
    }
    else if ( (front->prev == front) && (front->next == front) ) // if there is one element in the queue
    {
        delete front; // deallocates dynamic memory
        front = 0; // sets front to zero
    }
    else if ( (front->next)->next == front) // if there are two elements in the queue
    {
        bqnode * p = front; // p points to front
        front = front->prev; // front is equal to front prev
        delete p; // deallocates dynamic memory
        front->next = front; // front next equals front
        front->prev = front; // front prev equals front
    }
    else
    {
        bqnode * p = front; // p points to front
        front = front->prev; // front equals front prev
        front->next = p->next; // front next equals p next
        (front->next)->prev = front; // the back of the queue's prev is set to front
        delete p; // dynamic memory is deallocated
    }
}

/*********************************************************************************************************************************************************
Name: print
Pre-Conditon: The object has been initialized
Post-Condition: The contents of the queue are printed to the screen
Description: The function prints the contents of the queue to the screen
**********************************************************************************************************************************************************/    
void bqueue::print()
{
    if (front == 0) // if Queue is empty
    {
        cout << "Queue is empty!" << endl; // send message
        return; // exit function
    }
    
    bqnode * p = front; // p points to front
    do
    {
        cout << p->priority << " "; // print the element of the node pointed to by p
        p = p->prev; // traverse the queue
        
    }while(p!=front); // stop when entire queue has been printed to screen
    
    cout << endl;
}
