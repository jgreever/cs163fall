#include "hash_table.hpp"
using namespace std;

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
        insert(name, location, hint);
    }

    return true;
}

bool table::clear_table()
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
    return true;
}

int table::insert(char *aName, char *aLocation, char *aHint)
{
    int tempKey = hash_function(aName);
    node *temp = new node();
    temp->anEntry.create_entry(aName, aLocation, aHint, 2);
    temp->next = hash_table[tempKey];
    hash_table[tempKey] = temp;
    return 1;
}

int table::retrieve(char *name_to_find)
{
    int index = hash_function(name_to_find);
    node *temp = hash_table[index];
    if (temp == NULL)
        return 0;
    temp->anEntry.display();
    return 1;
}

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
