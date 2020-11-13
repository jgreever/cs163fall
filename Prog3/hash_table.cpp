#include "hash_table.hpp"

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
        if (!hash_table[i])
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
    return 1;
}

int table::retrieve(char *name_to_find, entry &found) const
{
    int index = hash_function(name_to_find);
    bool success = false;
    node *current = hash_table[index];

    while (current && !success)
    {
        success = current->hEntry.retrieve(name_to_find, found);
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
