// Include directives
#include <iostream>
#include <vector>
#include <string>
#include "vlist.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: Constructor has not been invoked.
//Postcondition: count = 0; vector size is 9.
//Description: Constructs an instance of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist()
{
    count = 0; // sets count to 0
    DB.reserve(9); // sets the capacity of the vector to 9
	cout << "Default Constructor Invoked" << endl; // outputs a message
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: vlist
//Precondition: A vlist object is being passed by reference.
//Postcondition: A hard copy of a vlist object has been created.
//Description: Creates a hard copy of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::vlist(const vlist & Org)
{
    DB = Org.DB; // uses the overloaded assignment operator for vectors to make a deep copy
    count = Org.count; // sets count equal to Org.count
    cout << "Copy Constructor Invoked" << endl; // outputs a message
}


///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: ~vlist
//Precondition: Destructor has not been invoked.
//Postcondition: array DB deleted.
//Description: Deallocates memory of a vlist object.
///////////////////////////////////////////////////////////////////////////////////////////////
vlist::~vlist()
{
    count = 0; // sets count to 0
    DB.clear(); // elements of vector DB are cleared
    DB.shrink_to_fit(); // the capacity of DB set to 0
    cout << "Destructor Invoked" << endl; // outputs a message
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: isEmpty
//Precondition: The vector has been initialized
//Postcondition: Retuns true if the vlist is empty and false if it is not
//Description: The function returns true if the vlist object is empty and false if it is not
///////////////////////////////////////////////////////////////////////////////////////////////
bool vlist::isEmpty() 
{
    return count == 0; // if the vector is empty, returns true, else false
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search
//Precondition: The vector has been initialized
//Postcondition: An iterator to the position in the vector containing key is returned if found, else it returns an iterator to DB.end()
//Description: The function returns an iterator to the position containing key if it is found, else it returns an iterator to DB.end()
///////////////////////////////////////////////////////////////////////////////////////////////
vector<string>::iterator vlist::search(const string& key)
{
    vector<string>::iterator s = DB.begin(); // iterator s is set to the begining of DB
    int i= 0; // i is set to 0
    for(i = 0; i<count; i++) // iterate i through the vector
    {
        if( *(s+i) == key) // if the element in the vector is equal to vector
        {
            cout << "Item Found " << *(s+i) << endl; // outputs a message
            return (s+i); // returns the iterator pointing to the element containing key
        }
    }
    
    cout << "Item Not Found " << endl; // outputs a message
    return (s+i); // returns the iterator pointing to DB.end()
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert
//Precondition: The vector has been initialized
//Postcondition: Key is inserted into the array alphabetically
//Description: The function inserts key into the array alphabetically
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::insert(const string & key)
{
    vector<string>::iterator s = DB.begin(); // iterator s is set to the begining of DB
    
    int i = 0; // set i equal to 0
    
    for(i = 0; i<count; i++) // iterate i through the vector
    {
        if( *(s+i) >= key) // if the element in the vector is greater than or equal to key
        {
            DB.insert(s+i , key); // insert key into the vector before s+i
            count++; // increment count
            return;
        }
    }
    
    count++; // increment count
    DB.push_back(key); // insert key at the end of the vector
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: remove
//Precondition: The vector has been initialized
//Postcondition: The element containing key in the vector has been removed if it exists
//Description: The function removes key from the vector if it is in the vector
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::remove(const string& key)
{
    vector<string>::iterator s = search(key); // set s equal to the position where key is found
    
    if(s != DB.end()) // if s is not equal to DB.end()
    {
        DB.erase(s); // erase element from the vector
        count--; // decrement count
        return;
    }
    
    cout << "Can't remove item because item is not found!" << endl; // output a message
    return;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print
//Precondition: The vector has been initialized
//Postcondition: The contents of the vector are outputted to the screen
//Description: The function prints the contents of the vector to the screen
///////////////////////////////////////////////////////////////////////////////////////////////
void vlist::print() 
{
    for(int i = 0; i<count; i++) // iterate i through the vector
    {
        cout << DB.at(i) << endl; // output the elements of the vector
    }
    cout << endl;
}

