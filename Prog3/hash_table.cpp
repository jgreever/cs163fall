/* hash_table.cpp
 * 
 * Justin Greever
 * CS163 - Program 3
 * 11/9/2020
 * 
 * Program 3 - Scavenger Hunt!
 *
 * For the hash table function, there are a few different types
 * of values that can be passed into it. Initialization takes
 * an int value for size (already coded in). Load from File 
 * function has the wordlist.txt file hardcoded for loading to
 * save the user from needing to manually type the file name
 * to test the function. The following functions accept values
 * to be passed by the client/user:
 * 
 *  insert: accepts char name, char location, and char hint to
 *      be passed into it.
 * 
 *  retrieve: accepts a char name_to_find value to search for
 * 
 *  hash_function: accepts a char key (in this case item name)
 *      to be passed in to be hashed.
 * 
 * The private data held in the table class is:
 *  
 *  node **hash_table (this points to our hash table)
 *  int hash_table_size (the actual size of the hash table)
 * 
 */
#include "hash_table.hpp"
using namespace std;

//we create a table of size 'size', in this case 12289
table::table(int size)
{
    hash_table = NULL;
    hash_table_size = 0;

    hash_table = new node *[size];
    for (int i = 0; i < size; ++i)
        hash_table[i] = NULL;
    hash_table_size = size;
}

table::~table()
{
    node *temp = NULL;
    node *temp_next = NULL;
    for (int i = 0; i < hash_table_size; ++i)
    {
        if (hash_table[i])
        {
            temp = hash_table[i];
            while (temp != NULL)
            {
                temp_next = temp->next;
                delete temp;
                temp = temp_next;
            }
            hash_table[i] = NULL;
        }
    }
    delete[] hash_table;
    hash_table_size = 0;
}

//this function loads our data from the file 'wordlist.txt'
//if the user chooses to do so.
bool table::load_from_file()
{
    fstream wlFile;

    wlFile.open("wordlist.txt", ios::in);
    while (wlFile.good() && !wlFile.eof())
    {
        char tName[100];
        char tLocation[300];
        char tHint[300];

        wlFile.getline(tName, 100, '|');
        wlFile.clear();
        wlFile.getline(tLocation, 300, '|');
        wlFile.clear();
        wlFile.getline(tHint, 300, '\n');
        char name[strlen(tName) + 1];
        char location[strlen(tLocation) + 1];
        char hint[strlen(tHint) + 1];
        strcpy(name, tName);
        strcpy(location, tLocation);
        strcpy(hint, tHint);
        table::insert(name, location, hint);
    }

    return true;
}

//this will clear our hash table but NOT delete the table,
//only set each index to NULL. The destructor will delete
//everything.
bool table::clear_table()
{
    node *temp = NULL;
    node *temp_next = NULL;
    for (int i = 0; i < hash_table_size; ++i)
    {
        if (hash_table[i])
        {
            temp = hash_table[i];
            while (temp)
            {
                temp_next = temp->next;
                delete temp;
                temp = temp_next;
            }
            hash_table[i] = NULL;
        }
    }
    return true;
}

//this takes a name, location, and hint from either the
//user or from the file, hashes the name, then stores it
//in the index at the value of the hash key.
int table::insert(char *aName, char *aLocation, char *aHint)
{
    int tempKey = hash_function(aName);
    node *temp = new node();
    temp->anEntry.create_entry(aName, aLocation, aHint);
    temp->next = hash_table[tempKey];
    hash_table[tempKey] = temp;
    return 1;
}

//retrieves the data from the hash table to display to
//the user if they choose to search for an item to display
int table::retrieve(char *name_to_find)
{
    int index = hash_function(name_to_find);
    node *temp = hash_table[index];
    if (temp == NULL)
        return 0;
    temp->anEntry.display(2);
    return 1;
}

//our hash function. It grabs the ASCII value for each
//char in the name, adds them all up, then returns the
//absolute value of the character values and mods (%)
//it by 6151, our other magic prime number. This returns
//the hashKey of the entry for storage in the hash table.
int table::hash_function(char *key) const
{
    int i = 0;
    int charValue = 0;
    int kSize = strlen(key) + 1;

    while (i < kSize)
    {
        charValue = (key[i] - '0') + (charValue * 10);
        charValue += charValue;
        ++i;
    }

    return (abs(charValue) % 6151);
}
