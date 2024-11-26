#include "state.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>

using namespace std;

/***********************FUNCTION HEADER ******************************************************************************************************************
Name:  Default Constructor
Pre-Conditon: The count, capacity, and the dynamic array (pop_DB) have not been initialized.
Post-Condition: The count, capacity, and the dynaic array (pop_DB) have been initialized.
Description:  The function initiailizes the state (private data) of the class state_class. It reads the data stored in the datafile "census2020_data.txt"
			  into the dynamic array, pop_DB.  Initially, count is set to 0, capacity to 5, and pop_DB is allocated 5 cells.  If pop_DB become full,
			  double_size is called, which doubles the capacity of pop_DB.

**********************************************************************************************************************************************************/
state_class::state_class()
{
	//intially count, capacity, and pop_DB are initialized with the following values:
	count = 0;
	capacity = 5;
	pop_DB = new population_record[capacity];
    
    ifstream in;
    in.open("census2020_data.txt");
    
    if(in.fail())
    {
        exit(1);
        cout << "Input file failed to open correctly!\n";
    }
    
    int i=0;
    char c[50];
    
    while(!in.eof())
    {
        if(Is_Full())
        {
            double_size();
        }
        
        string temp_state_name = "\0";
        string temp_population = "\0";
        
        getline(in, temp_state_name);
        
        temp_population = temp_state_name;
        
        
        int slength = temp_state_name.length();
        for(int x=0; x<slength; x++)
        {
            if( (static_cast<int>(temp_state_name[x]) >= 48) && (static_cast<int>(temp_state_name[x]) <=57) )
            {
                temp_population = temp_state_name.substr(x, slength-1);
                temp_state_name = temp_state_name.substr(0,x-1);

                break;
            }
        }
        
        pop_DB[i].state_name = temp_state_name;
        pop_DB[i].population = stof(temp_population);
        
        count++;
        i++;
    }
    
    in.close();
}

/******************************************************************************************************************************************************
Name: Copy constructor
Pre-Condition: An object of this class type is being passed by value
Post-Condition A deep copy of the object is made
Description: The copy constructor makes a deep copy of the original object
******************************************************************************************************************************************************/
state_class::state_class(const state_class & org)
{
	count = org.count;
	capacity = org.capacity;
	
	pop_DB = new population_record[capacity];
	
	for(int i=0; i<count; i++)
	    pop_DB[i] = org.pop_DB[i];
}

/******************************************************************************************************************************************************
Name: Destructor
Pre-Condition: The object goes out of scope
Post-Condition: count and capacity are set to 0, and the dynamic memory allocated to pop_DB is returned to free store
Description: The destructor returns the dynamic array pop_DB to free store and resets count and capacity
******************************************************************************************************************************************************/
state_class::~state_class()
{

    count = 0;
    capacity = 0;
    
    delete [] pop_DB;

}

/******************************************************************************************************************************************************
Name: double_size
Pre-Condition: pop_DB, capacity, and count are initialized
Post-Condition: the capacity of pop_DB is doubled
Description: the function doubles the capacity of pop_DB; usually called after pop_DB runs out of space
******************************************************************************************************************************************************/
void state_class::double_size()
{

    capacity*=2;
    
    population_record * temp = new population_record[capacity];
    
    for(int i=0; i<count; i++)
	    temp[i] = pop_DB[i];
	    
    delete [] pop_DB;
    
    pop_DB = temp;

}

/******************************************************************************************************************************************************
Name: operator+
Pre-Condition: pop_DB, count, capacity are initialized
Post-Condition: a user input of a state_name and population are entered into the dynamic array pop_DB
Description: the overloaded operator accepts a user input and inputs it into the array of population_records without chaining
******************************************************************************************************************************************************/
void state_class::operator+(const population_record& r)
{
    if(Is_Full())
    {
        double_size();
    }

    pop_DB[count].population = r.population;
    pop_DB[count].state_name = r.state_name;
    
    count++;
}

/******************************************************************************************************************************************************
Name: Search
Pre-Condition: pop_DB, count, capacity are initialized
Post-Condition: the index of the population_record with state_name == state is returned, if none exists, -1 is returned
Description: the function finds the index of the population_record with the state name state
******************************************************************************************************************************************************/
int state_class::Search(const string& state)
{
	for(int i=0; i<count; i++)
	{
	    if(pop_DB[i].state_name == state)
	    {
	        return i; 
	    }

	}
	return -1;
}


/******************************************************************************************************************************************************
Name: Remove
Pre-Condition: pop_DB, count, capacity are initialized
Post-Condition: all population_records with state_name == state are removed from the dynamic array
Description: the function removes all records with state_name state
******************************************************************************************************************************************************/
void state_class::Remove(const string& state)
{
	int y = Search(state);
	
	while(y != -1)
	{
	    for(int x = y; x<count-1; x++)
	    {
	        pop_DB[x].state_name = pop_DB[x+1].state_name;
	        pop_DB[x].population = pop_DB[x+1].population;
	    }
	    
	    count--;
	    
	    y = Search(state);
	    
	}
}


/******************************************************************************************************************************************************
Name: Print_ALL_To_File
Pre-Condition: pop_DB, count, capacity are initialized
Post-Condition: all records in the dynamic array are printed to the file specified by string filename
Description: the function prints all the records in the dynamic array to the file filename
******************************************************************************************************************************************************/
void state_class::Print_ALL_To_File(const string& filename)
{
	
	ofstream out;
	out.open(filename);
	
	out.precision(0);
    out.setf(ios::fixed);
    
	for(int i=0; i<count; i++)
	{
	    
	    out << setw(20) << left << pop_DB[i].state_name;
	    out << setw(20) << right << pop_DB[i].population << endl;
	    
	}
	
	out.close();
	
}
/******************************************************************************************************************************************************
Name: Print_ALL
Pre-Condition: pop_DB, count, capacity are initialized
Post-Condition: all population_records in the dynamic array are printed to the screen
Description: the function prints all population_records to the screen
******************************************************************************************************************************************************/
void state_class::Print_ALL()
{
    
    cout.precision(0);
    cout.setf(ios::fixed);
    
	for(int i=0; i<count; i++)
	{
	    
	    cout << setw(20) << left << pop_DB[i].state_name;
	    cout << setw(20) << right << pop_DB[i].population << endl;
	    
	}
	
}


/******************************************************************************************************************************************************
Name: Print_Range
Pre-Condition:  pop_DB, count, capacity are initialized
Post-Condition: all population_records with populations that are between min and max (inclusive) are printed to the screen
Description: the function prints the population_records with populations that are between the min and max (inclusive) to the screen
******************************************************************************************************************************************************/
void state_class::Print_Range(const int min, const int max)
{
	cout.precision(0);
    cout.setf(ios::fixed);
    
	for(int i=0; i<count; i++)
	{
	    if( ((pop_DB[i].population > min) && (pop_DB[i].population < max)) )
	    {
	       cout << setw(20) << left << pop_DB[i].state_name;
	       cout << setw(20) << right << pop_DB[i].population << endl; 
	    }
	    
	}
}


/******************************************************************************************************************************************************
Name: State_Count
Pre-Condition: pop_DB, count, capacity are initialized
Post-Condition: returns an int value that specifies the number of states that have populations between min and max (inclusive)
Description: the function returns the number of states that have populations between min and max (inclusive)
******************************************************************************************************************************************************/
int state_class::State_Count(const int min, const int max)
{
    int s_count = 0;
    
	for(int i=0; i<count; i++)
	{
	    if( (pop_DB[i].population > min) && (pop_DB[i].population < max) )
	    {
	       s_count++;
	    }
	    
	}
	
	return s_count;
}

/******************************************************************************************************************************************************
Name: Sort
Pre-Condition: pop_DB, count, capacity are initialized
Post-Condition: the dynamic array of population_records is sorted alphabetically
Description: the function alphabetizes the dynamic array
******************************************************************************************************************************************************/
void state_class::Sort()
{
    int j;
    population_record key;
	for(int i=1; i<count; i++)
	{
	    key = pop_DB[i];
	    j = i-1;
	    
	    while( (j>=0) && (pop_DB[j].state_name > key.state_name) )
	    {
	        pop_DB[j+1] = pop_DB[j];
	        j = j-1;
	    }
	    
	    pop_DB[j+1] = key;
	}

}
