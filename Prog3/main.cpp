#include "hash_table.hpp"

int main()
{
    table aTable;
    entry anEntry;
    queue aQueue;
    char aName[100];

    std::cout << "\nLoading hash table from file...\n";
    if (aTable.load_from_file() == true)
        std::cout << "\nHash Table loaded sucessfully!\n";
    else
        std::cout << "\nHash Table failed to load...\n";
    
    std::cout << "\nEnter the name to search for: ";
    std::cin.get(aName, 100, '\n');
    aTable.retrieve(aName);
    
    return 0;
}