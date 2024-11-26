// include directives
#include <iostream>
#include "bqueue.h"

using namespace std;

// -----------------------------------------------------------------------------
// ******* ASSIGNMENT 6 BQUEUE *******
// Student: Matthew Acs Z23536012
// Total Possible Points: 25
// Due Date: 10/27/2020
// Course: COP 3530 
// Assignment: Assignment 6
// Professor: Dr. Bullard
// Description: The program test the functionality of a doubly-linked circular
// queue of integers class. The class can enqueue integers, dequeue, and print.
// It is implementd with a default constructor, a copy  constructor, and a destructor.
// -----------------------------------------------------------------------------

// Driver of the program. Intended to test the functionality of the class.
// Driver is in function driver() to better organize the program.
void driver()
{
    bqueue k;
    
    k.enqueue(60);
    k.print();
    k.enqueue(20);
    k.enqueue(30);
    k.print();
    k.enqueue(10);
    k.print();
    k.enqueue(50);
    k.enqueue(40);
    k.print();
    bqueue j = k;
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    j.print();
    j.dequeue();
    j.dequeue();
    
    return; 
}

// Main function
int main()
{
    // Function call to driver()
    driver();
    
    return 0;
}