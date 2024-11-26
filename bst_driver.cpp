// include directives
#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"

using namespace std;
// -----------------------------------------------------------------------------
// ******* ASSIGNMENT 9 BST *******
// Student: Matthew Acs Z23536012
// Total Possible Points: 25
// Due Date: 12/7/2020
// Course: COP 3530 
// Assignment: Assignment 9
// Professor: Dr. Bullard
// Description: The program test the functionality of a BST class. The class
// contains various functions that give the user the ability to insert and delete
// nodes, print the bst to the sceen/a file, empty the bst, and print a range of nodes.
// -----------------------------------------------------------------------------

// Driver of the program. Intended to test the functionality of the class.
// Driver is in function driver() to better organize the program.
void driver()
{
	
	cout << "**************************************************************" << endl;
	cout << "Test1: default constuctor" << endl;
	cout << "Echo the input datafile (county_data_txt) to the screen from default constuctor" << endl << endl;

	bst  myTree;

	cout << endl << "Print contents of bst inorder to the screen" << endl << endl;
	myTree.print_tree();
	cout << "*************End Test1*****************************************" << endl;
	cout<<endl<<endl;

	cout << "**************************************************************" << endl;
	cout << "Test2: insert" << endl;
	
	myTree.insert("New County", 234658);
	cout <<endl<< "Print contents of bst inorder to the screen" << endl << endl;;
	myTree.print_tree();
	cout << "*************End Test2*****************************************" << endl;
	cout << endl << endl;

	cout << "**************************************************************" << endl;
	cout << "Test3: county_ranges" << endl;
	cout << "Print contents of bst range between B and K inorder to the screen" << endl << endl;;
	myTree.county_ranges("B","K");
	cout << "*************End Test3*****************************************" << endl;
	cout << endl << endl;

	cout << "**************************************************************" << endl;
	cout<<"Test4: del_name"<<endl;
	myTree.del_name("Miami Dade");
	cout << endl << "Print contents of bst inorder, with Miami Dade removed, to the screen" << endl << endl;;
	myTree.print_tree();
	cout << "*************End Test4*****************************************" << endl;
	cout << endl << endl;

	cout << "**************************************************************" << endl;
	cout<<"Test5: sorted_info"<<endl<<endl;
	cout << "Print contents of bst inorder to the output file, county_info.txt, with name and associated population size shown" << endl << endl;
	myTree.sorted_info();
	cout << "*************End Test5*****************************************" << endl;
	cout << endl << endl;

	cout << "**************************************************************" << endl;
	cout << "Test6: empty_tree" << endl << endl;
	myTree.empty_tree();
	cout << endl << "Print contents of an empty bst to the screen" << endl << endl;;
	myTree.print_tree();
	cout << "*************End Test6*****************************************" << endl;
	cout << endl << endl;
	
	return;
}

// Main function
int main()
{
    // Function call to driver()
    driver();
    return 0;
}
