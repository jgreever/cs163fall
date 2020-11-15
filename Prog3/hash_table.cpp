#include "hash_table.hpp"
using namespace std;

table::table(int size)
{
    name = location = hint = NULL;
    hash_table_size = 0;
    hash_table = NULL;

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
    delete []hash_table;
    hash_table_size = 0;
    name = location = hint = NULL;
}

bool table::load_from_file(void)
{
    fstream namefile;
    entry hEntry;
    queue hQueue;
    
    namefile.open("wordlist.txt", ios::in);
    while (namefile.good() && !namefile.eof())
    {
        char tName[100];
        char tLocation[300];
        char tHint[300];
        
        namefile.getline(tName, 100, '|');
        namefile.clear();
        namefile.getline(tLocation, 300, '|');
        namefile.clear();
        namefile.getline(tHint, 300, '\n');
        char aName[strlen(tName) + 1];
        char aLocation[strlen(tLocation) + 1];
        char aHint[strlen(tHint) + 1];
        strcpy(aName, tName);
        strcpy(aLocation, tLocation);
        strcpy(aHint, tHint);
        insert(aName, aLocation, aHint);
    }
    
    return true;
}

int table::insert(char *aName, char *aLocation, char *aHint)
{
    int tempKey = hash_function(aName);
    entry to_add;
    to_add.create_entry(aName, aLocation, aHint);
    if (table::insert(to_add, tempKey) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int table::insert(entry &to_add, int tempKey)
{
    node *temp = new node;
    temp->tEntry.create_entry(to_add);
    temp->next = hash_table[tempKey];
    hash_table[tempKey] = temp;

    return 1;
}

int table::retrieve(char *name_to_find) const
{
    int index = hash_function(name_to_find);
    entry tEntry;
    node *temp = hash_table[index];
    if (temp == NULL)
        return 0;
    temp->tEntry.retrieve(name_to_find, tEntry);
    temp->tEntry.create_entry(tEntry);
    queue qEntry; 
    qEntry.enqueue(tEntry);
    qEntry.display();
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
