// include directives
#include <vector> 
#include <string>

using namespace std;

// Prevents from being included twice in a program
#ifndef vlist_H
#define vlist_H

// Declaration of class vlist
class vlist
{
public:
	vlist(); // Default constructor
	vlist(const vlist&); // Copy Constructor
	~vlist(); // Destructor
	bool isEmpty(); // Checks if DB is empty
	vector<string>::iterator search(const string&); // Returns an iterator to the location where key is found in DB
	void insert(const string&); // Inserts a string into DB in alphabetical order
	void remove(const string&); // Removes a string from DB that matches key
	void print(); // Prints the contents of DB to the screen
private:
	vector<string> DB; // Vector used to maintain the alphabetical list of strings
	int count; // keeps track of the number of elements in DB
};

#endif


