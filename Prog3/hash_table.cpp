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

bool table::load_from_file()
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
    while (namefile)
    {
        char tName[100];
        char tLocation[300];
        char tHint[300];

        namefile.getline(tName, 100, '|');
        namefile.clear();
        namefile.getline(tLocation, 300, '|');
        namefile.clear();
        namefile.getline(tHint, 300, '\n');
        hEntry.create_entry(tName, tLocation, tHint);
        insert(tName, hEntry);
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

int table::insert(char *key_value, const entry &to_add)
{
    int tempKey = hash_function(key_value);
    node *temp = new node;

    if (!temp->hEntry.create_entry(to_add))
    {
        delete temp;
        return 0;
    }
    //TODO
    //!Remove the statement below for cout tempkey
    std::cout << "Hash Key: " << tempKey << "\n"; 
    temp->next = hash_table[tempKey];
    hash_table[tempKey] = temp;
    delete temp;
    return 1;
}

int table::retrieve(char *name_to_find, entry &found) const
{
    int index = hash_function(name_to_find);
    bool success = false;
    node *current = hash_table[index];
    entry hEntry;
    queue hQueue;
    int counter = 0;

    while (current && !success && counter <=10)
    {
        //success = current->hEntry.retrieve(name_to_find, found);
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
    }
    return success;
}

int table::hash_function(char *key) const
{
    int i = 0;
    int charStar_to_int = 0;
    
    while (i <= 6)
    {
        charStar_to_int = (key[i] - '0') + (charStar_to_int * 10);
        ++i;
    }

    //TODO
    //!Remove the cout charStar_to_int below
    std::cout << "Char* to Int: " << charStar_to_int << "\n";
    return (charStar_to_int % 6151);
}
