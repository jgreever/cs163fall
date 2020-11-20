/* entry.cpp
 * 
 * Justin Greever
 * CS163 - Program 3
 * 11/9/2020
 * 
 * Program 3 - Scavenger Hunt!
 *
 * The entry class is our method of taking the information
 * about an item, repackage it, pass it to the proper 
 * create_entry function (one for Queue, one for Hash Table),
 * then either display the information about the item, or
 * hand the data off to either the hash table class or the 
 * queue class to be added to the search list.
 * 
 * The private data contained in this class are:
 *  char *name;
 *  char *location;
 *  char *hint;
 * 
 * The values passed in from the client/main are just the
 * item name, location, and a hint. The int userChoice/choice
 * is hard coded so that our display function will be able to 
 * determine if it should grab information from the hash table
 * or the queue to output to the user.
 * 
 * Both the hash table and the queue's struct for ther nodes
 * contain 'entry anEntry' which is the only data this class
 * can access, and shields it from other classes.
 *  
 */
#include "hash_table.hpp"
using namespace std;

entry::entry()
{
    this->name = this->location = this->hint = NULL;
}

entry::~entry()
{
    if (this->name)
        delete[] this->name;
    if (this->location)
        delete[] this->location;
    if (this->hint)
        delete[] this->hint;
    this->name = this->location = this->hint = NULL;
}

//this function takes the input from the user/client and passes
//it to the proper function to store in the hash table or queue
int entry::create_entry(const entry &to_add, int choice)
{
    return entry::create_entry(to_add.name, to_add.location, to_add.hint);
}

//this function creates an entry for the queue, NOT the hash table
int entry::create_entry(char *aName)
{
    if (this->name)
        delete[] this->name;
    this->name = new char[strlen(aName) + 1];
    location = hint = NULL;
    strcpy(this->name, aName);
    return 1;
}

//this function creates an entry for the hash table, NOT the queue
int entry::create_entry(char *aname, char *alocation, char *ahint)
{
    if (this->name)
        delete[] this->name;
    if (this->location)
        delete[] this->location;
    if (this->hint)
    delete[] this->hint;
    this->name = new char[strlen(aname) + 1];
    strcpy(this->name, aname);
    this->location = new char[strlen(alocation) + 1];
    strcpy(this->location, alocation);
    this->hint = new char[strlen(ahint) + 1];
    strcpy(this->hint, ahint);
    return 1;
}

int entry::display(int userChoice)
{
    //this displays the data stored in the queue
    if (this->name && userChoice == 1)
    {
        cout << "\nItem name: " << this->name;
        return 1;
    }
    //this displays the information from the hash table
    else if (this->name && userChoice == 2)
    {
        cout << "\nItem name: " << this->name;
        cout << "\nItem location: " << this->location;
        cout << "\nItem hint: " << this->hint;
        return 1;
    }
    return 0;
}