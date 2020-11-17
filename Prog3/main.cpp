#include "hash_table.hpp"
using namespace std;

int main()
{
    entry anEntry;
    table *mainTable = new table();
    queue *mainQueue = new queue();
    char aName[100];
    char aLocation[300];
    char aHint[300];

    int choice = -1;
    do
    {
        cout << "\n\n********************\n";
        cout << "Scavenger Hunt!\n";
        cout << "********************\n";
        cout << " Main Menu\n";
        cout << "--------------------\n";
        cout << "1. Load item list from file\n";
        cout << "2. Manually add an item\n";
        cout << "3. Search and add item to list\n";
        cout << "4. View all information about an item\n";
        cout << "5. Remove matching item\n";
        cout << "6. Remove all items\n";
        cout << "0. Exit the program\n";
        cout << "********************\n\n";
        cin >> choice;
        cin.ignore(100, '\n');
    
        switch(choice)
        {
            case 1:
                std::cout << "\nLoading hash table from file...\n";
                if (mainTable->load_from_file() == true)
                    std::cout << "\nHash Table loaded sucessfully!\n";
                else
                    std::cout << "\nHash Table failed to load...\n";
                break;

            case 2:
                cout << "Let's add an item manually.\n";
                cout << "Please enter the name of the item: ";
                cin.get(aName, 100, '\n');
                cin.ignore(100, '\n');
                cout << "\nPlease enter the location of the item: ";
                cin.get(aLocation, 300, '\n');
                cin.ignore(100, '\n');
                cout << "\nPlease enter a hint to find the item: ";
                cin.get(aHint, 300, '\n');
                cin.ignore(100, '\n');
                mainTable->insert(aName, aLocation, aHint);
                cout << "\nItem has been added.\n";
                break;

            case 3:
                cout << "\nLet's search and add an item to our list.\n";
                cout << "Please enter the name of the item to search and add:\n";
                cin.get(aName, 100, '\n');
                cin.ignore(100, '\n');
                if (mainTable->retrieve(aName) == 1)
                {
                    mainQueue->enqueue(aName);
                    cout << "\nItem " << aName << " found and added to the list.\n";
                }
                else
                    cout << "\nItem " << aName << " not found in the list. Try again.\n";
                break;

            case 4:
                cout << "\nPlease enter the name of the item to view all information for:\n";
                cin.get(aName, 100, '\n');
                cin.ignore(100, '\n');
                cout << "\nShowing all information for " << aName << "\n";
                mainTable->retrieve(aName);
                break;

            case 5:
                cout << "\nRemoving " << aName << " from the list.\n";
                mainQueue->display();
                if (mainQueue->dequeue() == 1)
                    cout << "\nEntry has been removed.\n";
                else
                    cout << "\nEntry was not removed. Try again.\n";
                break;

            case 6:
                cout << "\nRemoving all items in the list.\n";
                mainTable->clear_table();
                break;

            case 0:
                cout << "\nExiting program. Thank you!\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
                break;

        }
    } while (choice != 0);
     
    return 0;
}