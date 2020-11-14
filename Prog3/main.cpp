#include "queue.hpp"

int main()
{
    entry anEntry;
    queue aQueue;
    char name[100];
    char location[300];
    char hint[300];

    std::cout << "\n";
    std::cout << "Name: ";
    std::cin.get(name, 100, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Location: ";
    std::cin.get(location, 300, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Hint: ";
    std::cin.get(hint, 300, '\n');
    std::cin.ignore(100, '\n');
    /*
    anEntry.create_entry(name, location, hint);
    anEntry.display();
    std::cout << "\nAn entry created and displayed.\n";

    aQueue.enqueue(anEntry);
    aQueue.display();
    std::cout << "\nA queue entry was created and displayed.\n";

    std::cout << "\nLet's try adding another one!\n";
    
    std::cout << "\n";
    std::cout << "Name: ";
    std::cin.get(name, 100, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Location: ";
    std::cin.get(location, 300, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Hint: ";
    std::cin.get(hint, 300, '\n');
    std::cin.ignore(100, '\n');
    */
    anEntry.create_entry(name, location, hint);
    aQueue.enqueue(anEntry);
    aQueue.display();
    std::cout << "\nA queue entry was created and displayed.\n";

    std::cout <<"\nWe will now dequeue the last item.\n";
    aQueue.dequeue();
    if (aQueue.display() == 0)
        std::cout << "\nThe queue is empty. Nothing to display.\n";
    return 0;
}