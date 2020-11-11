#include "queue.hpp"

int main()
{
    entry anEntry;
    queue aQueue;
    table aTable;

    char name[100];
    char location[300];
    char hint[300];

    std::cout << "Name: ";
    std::cin.get(name, 100, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Location: ";
    std::cin.get(location, 300, '\n');
    std::cin.ignore(100, '\n');
    std::cout << "Hint: ";
    std::cin.get(hint, 300, '\n');
    std::cin.ignore(100, '\n');

    anEntry.create_entry(name, location, hint);
    aQueue.enqueue(anEntry);

    aQueue.display();

    return 0;
}