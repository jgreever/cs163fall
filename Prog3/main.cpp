#include "hash_table.hpp"

int main()
{
    table aTable;
    entry anEntry;
    queue aQueue;
    char aName[100];
    //char aLocation[300];
    //char aHint[300];

    std::cout << "\nLoading hash table from file...\n";
    if (aTable.load_from_file() == true)
        std::cout << "\nHash Table loaded sucessfully!\n";
    else
        std::cout << "\nHash Table failed to load...\n";

    //TODO
    //!Remove below code, used for debugging/testing 
    std::cout << "\nEnter the name to search for: ";
    std::cin.get(aName, 100, '\n');
    aTable.retrieve(aName);
    /*
    std::cout << "\n";
    std::cout << "Name: ";
    std::cin.get(aName, 100, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Location: ";
    std::cin.get(aLocation, 300, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Hint: ";
    std::cin.get(aHint, 300, '\n');
    std::cin.ignore(100, '\n');
    
    anEntry.create_entry(aName, aLocation, aHint);
    anEntry.display();
    std::cout << "\nAn entry created and displayed.\n";

    aQueue.enqueue(anEntry);
    aQueue.display();
    std::cout << "\nA queue entry was created and displayed.\n";

    std::cout << "\nLet's try adding another one!\n";
    
    std::cout << "\n";
    std::cout << "Name: ";
    std::cin.get(aName, 100, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Location: ";
    std::cin.get(aLocation, 300, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Hint: ";
    std::cin.get(aHint, 300, '\n');
    std::cin.ignore(100, '\n');
    
    anEntry.create_entry(aName, aLocation, aHint);
    aQueue.enqueue(anEntry);
    aQueue.display();
    std::cout << "\nA queue entry was created and displayed.\n";

    std::cout <<"\nWe will now dequeue the last item.\n";
    aQueue.dequeue();
    if (aQueue.display() == 0)
        std::cout << "\nThe queue is empty. Nothing to display.\n";
    */
    return 0;
}