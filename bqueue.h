// Prevents from being included twice in a program
#pragma once

using namespace std;

// Declaration of class bqnode
class bqnode
{
    public:
    
    int priority; // the data member that holds inputs
    bqnode *prev, *next; // bqnode pointers that point to the previous and next nodes in the queue
};

// Declaration of class bqueue
class bqueue
{
    public:
    
    bqueue(); // Default constructor
    ~bqueue(); // Destructor
    bqueue(const bqueue&); // Copy Constructor
    void enqueue(int); // Enqueues an input into the queue
    void dequeue(); // Dequeues an input from the queue
    void print(); // Prints the queue to the screen
    
    private:
    
    bqnode *front; // Pointer used to maintain the queue
};