// Include directives
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "bst.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: empty
//Precondition: a bst object is initialized
//Postcondition: returns true if the bst is empty else false
//Description: the function returns true if the bst is empty, otherwise it returns false
///////////////////////////////////////////////////////////////////////////////////////////////
bool bst::empty()
{
	return (root == 0); // returns true if the bst is empty, else false
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert
//Precondition: a bst object is initialized 
//Postcondition: a node with data members item and population is inserted into the bst
//Description: the function inserts a node with the specified values into the bst
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::insert(const string& item, const double& population)
{

	insert(root, item, population); // function call to the overloaded function insert
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: insert
//Precondition: auxiliary function is called
//Postcondition: a node with data members item and population is inserted into the bst
//Description: the function inserts a node with the specified values into the bst
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::insert(treenode * & loc_ptr, const string& item, const double& population)
{
	if (loc_ptr == 0) // if the pointer is pointing to null
	{
		loc_ptr = new treenode; // create a new treenode
		loc_ptr->lchild = loc_ptr->rchild = 0; // set its rchild and lchild to null
		loc_ptr->county_name = item; // set its county_name to item
		loc_ptr->population_size = population; // set its population_size to population
	}
	else if (loc_ptr->county_name > item) // if item is less than the county_name in the current node
		insert(loc_ptr->lchild, item, population); // function call to insert with lchild specified
	else if (loc_ptr->county_name < item)// if item is greater than the county_name in the current node
		insert(loc_ptr->rchild, item, population); // function call to insert with rchild specified
	else // if the item is in the tree
		cout << "the item is already in the tree\n"; // output a message
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search_tree
//Precondition: the bst is initialized
//Postcondition: returns a treenode pointer to the location of item if it is in the bst
//Description: the function searches for item in the bst
///////////////////////////////////////////////////////////////////////////////////////////////
treenode * bst::search_tree(string item)
{
	return search_tree(root, item); // call to overloaded function search_tree
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: search_tree
//Precondition: call to auxiliary function was made
//Postcondition: returns a treenode pointer to the location of item if it is in the bst
//Description: the function searches for item in the bst
///////////////////////////////////////////////////////////////////////////////////////////////
treenode * bst::search_tree(treenode * loc_ptr, string item)
{
	if (loc_ptr != 0) // if pointer is not pointing to null
	{
		if (loc_ptr->county_name == item) // if item is found
			return loc_ptr; // returns pointer 
		else if (loc_ptr->county_name > item) // if item is less than current node
			return search_tree(loc_ptr->lchild, item); // function call to search_tree with lchild specified
		else // if item is greater than current node
			return search_tree(loc_ptr->rchild, item); // function call to search_tree with rchild specified
	}
	else // pointer is pointing to null
		return loc_ptr; // returns null pointer
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: del_name
//Precondition: the bst is initialized
//Postcondition: a node with item is deleted from the bst
//Description: the function deletes a node from the bst with the specified name
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::del_name(string item)
{
	del_name(root, item); // call to overloaded function del_name
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: del_name
//Precondition: the auxiliary function is called
//Postcondition: a node with item is deleted from the bst
//Description: the function deletes a node from the bst with the specified name
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::del_name(treenode*& loc_ptr, string item)
{

	if (loc_ptr == 0) // pointer is null
		cout << "item not in tree\n";

	else if (loc_ptr->county_name > item) // if item is less than node
		del_name(loc_ptr->lchild, item); // call to del_name with lchild

	else if (loc_ptr->county_name < item) // if item is greater than node
		del_name(loc_ptr->rchild, item); // call ot del_name with rchild

	else
	{
		treenode * ptr; // declares treenode ptr

		if (loc_ptr->lchild == 0) // if lchild is null
		{
			ptr = loc_ptr->rchild; // store r child in pointer
			delete loc_ptr; // delete the node
			loc_ptr = ptr; // set loc_ptr to ptr
		}
		else if (loc_ptr->rchild == 0) // if rchild is null
		{
			ptr = loc_ptr->lchild; // store r child in pointer
			delete loc_ptr; // delete the node
			loc_ptr = ptr; // set loc_ptr to ptr
		}
		else
		{
			ptr = inorder_succ(loc_ptr); // set ptr to inorder succesor
			loc_ptr->county_name = ptr->county_name; // set loc_ptr county_name to ptr county_name
			loc_ptr->population_size = ptr->population_size; // set loc_ptr population_size to ptr population_size
			del_name(loc_ptr->rchild, ptr->county_name); // function call to delete name with subtree specified
		}
	}

}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: inorder_succ
//Precondition: the bst is initialized
//Postcondition: a pointer to the inorder succesor to the current node is returned
//Description: the function finds the inorder succesor to the current node
///////////////////////////////////////////////////////////////////////////////////////////////
treenode * bst::inorder_succ(treenode * loc_ptr)
{

	treenode *ptr = loc_ptr->rchild; // treenode pointer ptr is set to the rchild of the current node

	while (ptr->lchild != 0) // while the left child is not null
	{
		ptr = ptr->lchild; // ptr is set to point to its lchild
	}
	return ptr;
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print_tree
//Precondition: the bst is initialized
//Postcondition: the county names in the bst are output in order
//Description: the function outputs the bst to the screen
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::print_tree()
{
	print_tree(root); // function call to overloaded function print_tree
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: print_tree
//Precondition: call to auxiliary function was made
//Postcondition: the county names in the bst are output in order
//Description: the function outputs the bst to the screen
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::print_tree(treenode * & loc_ptr)
{
	if (loc_ptr != 0) // if the pointer is not null
	{
		print_tree(loc_ptr->lchild); // call to print_tree with lchild specified
		
        cout.precision(0); // stream set to output to zero decimal places
        cout.setf(ios::fixed); // stream set to output to fixed notation
    
		cout << setw(20) << left << loc_ptr->county_name << endl; // outputs county_name to the screen
        
		print_tree(loc_ptr->rchild); // call to print_tree with rchild specified
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: Destructor
//Precondition: the object goes out of scope
//Postcondition: dynamic memory is deallocated
//Description: the destructor deallocates all dynamic memory of an object
///////////////////////////////////////////////////////////////////////////////////////////////
bst::~bst()
{
	while (root != 0)
	{
		del_name(root->county_name); // function call to del_name with root->county_name specified
	}
	cout << "The Destructor called\n"; // outputs message
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: constructor
//Precondition: an object is declared
//Postcondition: the object is initialized with values from a file
//Description: the constructor reads inputs into the bst from a file
///////////////////////////////////////////////////////////////////////////////////////////////
bst::bst()
{
    ifstream in; // opens and input stream
    in.open("county_data.txt"); // bind the stream to the file
    
    string x,item;
    double population;
    int i;
    
    root = 0; // set root equal to null
    
    while(!in.eof()) // while not at end of file
    {
        getline(in, x); // read line into x
        
        for(i=0; i<x.length(); i++) // for loop with x.length iterations
        {
            if( isdigit(x[i]) ) // if x[i] is a digit
            {
                item = x.substr(0,i-1); // store county name into item
                population = stod( x.substr(i,x.length()-i) ); // store population_size into population
                break; // jump from loop
            }
        }
        
        insert(item, population); // functin call to insert
        
        cout.precision(0); // sets output to zero decimal places
        cout.setf(ios::fixed); // sets output to fixed notation
        
        cout << setw(20) << left << item; // echos input
        cout << setw(20) << left << population << endl; // echos input
    }
    
    in.close(); // closes file stream
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: sorted_info
//Precondition: the bst is initialized
//Postcondition: the contents of the bst are output to a file specified
//Description: the function outputs the bst to a file
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::sorted_info()
{
    ofstream out; // declares output file stream out
    out.open("county_info.txt"); // binds stream to file
    sorted_info(out, root); // call to overloaded function sorted_info
    out.close(); // closes the stream
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: sorted_info
//Precondition: call to the auxiliary function is made
//Postcondition: the contents of the bst are output to a file specified
//Description: the function outputs the bst to a file
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::sorted_info(ostream & out, treenode * & loc_ptr)
{
    if (loc_ptr != 0) // if loc_ptr is not null
	{
		sorted_info(out, loc_ptr->lchild); // function call to sorted_info with lchild
		
        out.precision(0); // stream set to output to zero decimal places
        out.setf(ios::fixed); // stream set to output to fixed notation
        
		out << setw(20) << left << loc_ptr->county_name; // outputs county_name
        out << setw(20) << left << loc_ptr->population_size << endl; // outputs population_size
        
		sorted_info(out, loc_ptr->rchild); // function call to sorted_info with rchild
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: empty_tree
//Precondition: the bst is initialized
//Postcondition: the bst is emptied
//Description: the functoin empties the bst by deallocating all nodes
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::empty_tree()
{
    while (root != 0)
	{
		del_name(root->county_name); // function call to del_name
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: county_ranges
//Precondition: the bst is initialized
//Postcondition: all nodes with county names within the range are output
//Description: the function outputs the nodes of a bst within a range
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::county_ranges(const string& min_name, const string& max_name)
{
    county_ranges(root, min_name, max_name); // function call of overloaded county_ranges
}

///////////////////////////////////////////////////////////////////////////////////////////////
//Function Name: county_ranges
//Precondition: the auxiliary function is called
//Postcondition: all nodes with county names within the range are output
//Description: the function outputs the nodes of a bst within a range
///////////////////////////////////////////////////////////////////////////////////////////////
void bst::county_ranges(treenode * & loc_ptr, const string& min_name, const string& max_name)
{
    if (loc_ptr != 0) // is pointer is not null
	{
		county_ranges(loc_ptr->lchild, min_name, max_name); // call to county_ranges with lchild
		
		if( (loc_ptr->county_name >= min_name) && (loc_ptr->county_name <= max_name) ) // if node is in the range
		{
            cout.precision(0); // sets decimal places to zero
            cout.setf(ios::fixed); // fixed point notation
        
	    	cout << setw(10) << left << loc_ptr->county_name << endl; // output county_name
		}
		
		county_ranges(loc_ptr->rchild, min_name, max_name); // call to county_ranges with rchild
	}
}