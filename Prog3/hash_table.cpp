#include "hash_table.hpp"
using namespace std;

table::table(int size)
{
    hash_table = new node *[size];
    for (int i = 0; i < size; ++i)
        hash_table[i] = NULL;
    hash_table_size = size;
}

table::~table()
{
    node *temp, *temp_next;
    for (int i = 0; i < hash_table_size; ++i)
    {
        if (hash_table[i])
        {
            temp = hash_table[i];
            while (!temp)
            {
                temp_next = temp->next;
                delete temp;
                temp = temp_next;
            }
            hash_table[i] = NULL;
        }
    }
    delete[] hash_table;
}

bool table::load_from_file(void)
{
    /*
    char tName[100];
    char tLocation[300];
    char tHint[300];
    */

    fstream namefile;
    entry hEntry;
    queue hQueue;

    /*
    FILE *htList = fopen("wordlist.txt", "rb");
    fseek(htList, 0, SEEK_END);
    long fsize = ftell(htList);
    fseek(htList, 0, SEEK_SET);
    char *string = new char(fsize + 1);
    fread(string, fsize, 1, htList);
    fclose(htList);
    string[fsize] = 0;
    */
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
        
        //hEntry.create_entry(tName, tLocation, tHint);
        insert(tName, tLocation, tHint);
    }
    /*
    namefile.open("wordlist.txt", ios::in);
	if(!namefile.good())
		return false;
    while (namefile.peek() != EOF)
    {
        entry nEntry;
        namefile.get(tName, 100, '|');
        namefile.get(tLocation, 300, '|');
        namefile.get(tHint, 300, '\n');

        nEntry.create_entry(tName, tLocation, tHint);
        table::insert(tName, nEntry);
    }
    */
    return true;
}

int table::insert(char *name, char *location, char *hint)
{
    int tempKey = hash_function(name);
    node *temp = new node;

    if (!temp)
    {
        delete temp;
        return 0;
    }
    if (temp->name)
        delete []temp->name;
    temp->name = NULL;
    temp->name = new char[strlen(name) +1];
    strcpy(temp->name, name);
    if (temp->location)
        delete []temp->location;
    temp->location = NULL;
    temp->location = new char[strlen(name) + 1];
    strcpy(temp->location, location);
    if (temp->hint)
        delete []temp->hint;
    temp->hint = NULL;
    temp->hint = new char[strlen(hint) + 1];
    strcpy(temp->hint, hint);

    //TODO
    //!Remove the statement below for cout tempkey
    std::cout << "Hash Key: " << tempKey << "\n";

    temp->next = hash_table[tempKey];
    hash_table[tempKey] = temp;
    delete temp;
    return 1;
}

int table::retrieve(char *name_to_find) const
{
    int index = hash_function(name_to_find);
    //bool success = false;
    node *current = hash_table[index];
    if (!current)
    {
        delete current;
        current = NULL;
        return 0;
    }
    //entry hEntry;
    //queue hQueue;
    cout << "\n\n";
    cout << "\nItem: " << current->name;
    cout << "\nLocation: " << current->location;
    cout << "\nHint: " << current->hint;
    cout << "\n\n";
        //success = current->hEntry.retrieve(name_to_find, found);
        /*
        if (current->hEntry.retrieve(name_to_find, found) == 1)
        {
            if (hQueue.enqueue(hEntry) == 1)
            {
                counter += 1;
                success = true;
                return success;
            }
            else
            {
                success = false;
                return success;
            }
        }
        current = current->next;
        */
    return 1;
}

int table::hash_function(char *key) const
{
    int i = 0;
    int charValue = 0;
    int kSize = strlen(key) - 1;
    
    while (i < kSize)
    {
        charValue = (key[i] - '0') + (charValue * 10);
        ++i;
    }

    //TODO
    //!Remove the cout charStar_to_int below
    std::cout << "Char* to Int: " << charValue << "\n";
    return (abs(charValue) % 6151);
}
