/* main.cpp
 *
 * Justin Greever
 * CS163 - Program 4
 * 11/19/2020
 *
 * Media Management (using BSTs)
 *
 */
#include "bst.hpp"

int main()
{
    bst *mainBST = new bst;
    entry mainEntry;
    char name[100];
    char media[100];
    char desc[300];
    char length[25];
    char isNext[100];
    int choice = -1;

    do
    {
        cout << "\n\n********************\n";
        cout << "Scavenger Hunt!\n";
        cout << "********************\n";
        cout << "\nMain Menu\n";
        cout << "--------------------\n";
        cout << "1. Add new media\n";
        cout << "2. Search for media\n";
        cout << "3. Remove a media entry\n";
        cout << "4. Remove all entries for a class\n";
        cout << "5. Display all info for a class\n";
        cout << "6. Get the height of the BST\n";
        cout << "7. Display all entries\n";
        cout << "8. Exit the program\n";
        cout << "********************\n\n";
        cin >> choice;
        cin.ignore(100, '\n');

        switch (choice)
        {
            case 1:
                cout << "\nPlease enter the class name: ";
                cin.get(name, 100, '\n');
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter the media name: ";
                cin.get(media, 100, '\n');
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter the media description: ";
                cin.get(desc, 300, '\n');
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPlease enter the media length: ";
                cin.get(length, 25, '\n');
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nIs there anything that needs to be watched next: ";
                cin.get(isNext, 100, '\n');
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                mainEntry.createEntry(name, media, desc, length, isNext);
                mainBST->insert(mainEntry);
                break;

            case 2:
                media[100] = '\0';
                cout << "\n\nEnter the media name to search for: ";
                cin.get(media, 100, '\n');
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                mainBST->search(media);
                //TODO: Determine the return method (display or pass-back)
                //TODO: and add the code here.
                break;

            case 3:
                media[100] = '\0';
                cout << "\n\nEnter the media name to delete: ";
                cin.get(media, 100, '\n');
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                mainBST->remove_entry(media);
                break;

            case 4:
                name[100] = '\0';
                cout << "\n\nEnter the class name to delete all entries for that class: ";
                cin.get(name, 100, '\n');
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                //TODO: Add function to find and delete all classes by name
                break;

            case 5:
                name[100] = '\0';
                cout << "\n\nEnter the class to display all data for: ";
                cin.get(name, 100, '\n');
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                //TODO: Add code to find and delete all classes via their name
                break;
            
            case 6:
                cout << "\n\nThe height of the BST is: " << mainBST->height();
                break;
            
            case 7:
                cout << "\n\nDisplaying all entries: ";
                mainBST->display_all();
                break;

            case 8:
                cout << "\n\nExiting program, thank you!\n\n";
                break;

            default:
                cout << "\n\nInvalid choice. Please try again.\n\n";
                continue;

            //cout << "\n\nAgain? (1) for yes, (0) for no: ";
            //cin >> choice;
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (choice != 8);

    if (mainBST)
        delete mainBST;

    return 1;
}