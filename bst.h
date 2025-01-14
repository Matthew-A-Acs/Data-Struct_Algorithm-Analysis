// include directives
#include <iostream>
#include <string>

using namespace std;

// Prevents from being included twice in a program
#pragma once

class treenode // declaration of class used as node in bst
{
public:
	string county_name; // string data member of node
    double population_size; // double data member of node
	treenode* lchild, * rchild; //left and right children pointers 
};

class bst // declaration of bst class
{
public:
	bst(); //store the data file (“county_data.txt”) into initial bst. 
	~bst();//de-allocates dynamic memory allocate for tree bool empty();
	bool empty(); //return true if bst is null; otherwise false is retured. 
	void insert(const string& item, const double& population); //auxiliary function.
	void insert(treenode*&, const string& item, const double& population); //inserts an item into 
              //the bst; this function is invoked, in main, by the auxiliary function described above.
	void del_name(string item); //auxiliary function. 
	void del_name(treenode*& loc_ptr, string item); //function deletes an item from the bst; this 
                           //function is invoked, in main, by the auxiliary function described above. 
    treenode* search_tree(string item); //auxiliary fucntion
	treenode* search_tree(treenode*, string item); //returns a pointer to the node in bst with a  
                  //county name county name that matches item; this function is invoked, in main, by 
                  //the auxiliary function describes above.
	treenode* inorder_succ(treenode*); //returns a pointer to the inorder successor, based on county 
                                          //name. 
	void county_ranges(const string& min_name, const string& max_name); //auxiliary function.
	void county_ranges(treenode*&, const string& min_name, const string& max_name); //prints all 
                            //the county names to the screen that lie between min_name and max_name, 
                            //inclusive. 
	void print_tree();//auxiliary function. 
	void print_tree(treenode*&);//prints each county record to the screen sorted by county name.
	void sorted_info();//auxiliary function.
	void sorted_info(ostream&, treenode*&);//prints each county record to a file called 
                                             //“county_info.txt” sorted by county name”.
	void empty_tree();//de-allocate all nodes that were allocated to the bst
	
private:
	treenode* root; // private data member treenode pointer root
};