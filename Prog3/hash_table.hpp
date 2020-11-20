/* hash_table.hpp
 * 
 * Justin Greever
 * CS163 - Program 3
 * 11/9/2020
 * 
 * Program 3 - Scavenger Hunt!
 * 
 * This is our hash table class. It contains a struct that holds
 * an entry (item name, location, and hint), and the pointer to 
 * the next item at that index for chaining. This class is 
 * responsible for loading the information from a file and hashing
 * it so it can be stored in it's table properly. We are using 
 * a high prime number for the table size, 12289 in this case, 
 * and using 6151 as our prime that we take the inputs value
 * and mod (%) it by to return a hash key. The hash key is used
 * as the index for storage of the information. The user is able
 * to manually add items to the hash table as well, or instead
 * of loading from a file.
 * 
 * Our hash table uses chaining for collisions. If an item name
 * hashes to the same value as another, it will add it to the
 * index in a new node that can be searched/viewed/deleted 
 * without altering the other nodes in that index.
 */
#include "queue.hpp"

struct node
{
    entry anEntry;
    node *next;
};

class table
{
public:
    //constructor
    table(int size = 12289); //prime number to get a large hash table
    //destructor
    ~table();
    //load from file function
    bool load_from_file();
    //clear all entries in the hash table
    bool clear_table();
    //insert a new entry to the hash table
    int insert(char *name, char *location, char *hint);
    //search and retrieve information about an entry
    int retrieve(char *name_to_find);
    //our magical hash function used to get an index to store items at
    int hash_function(char *key) const;

private:
    node **hash_table;
    int hash_table_size;
};
