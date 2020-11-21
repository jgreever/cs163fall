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
    table *mainTable = new table;
    srand(time(0));
    int choice = 0;
    int data = 0;
    char name[100];
    char media[100];
    char desc[300];
    char length[25];
    char isNext[100];

    cout << "\n\nWould you like to add random int data\n";
    cout << "Or would you like to add an entry?\n";
    cout << "Enter '1' for random, '2' for entry: ";
    cin >> choice;
    cin.ignore(100, '\n');
    if (choice == 1)
    {
        cout << "\n\nAdding data to the tree...\n";
        for (int i = 0; i < 10; ++i)
        {
            int rng = rand() % 100;
            cout << "\nDEBUG: " << rng << "\n";
            mainBST->insert(rng);
        }
        mainBST->display();
        cout << "\n\nBST Height: " << mainBST->height() << "\n\n";
    }
    else if (choice == 2)
    {
        cout << "\nPlease enter the class name: ";
        cin.get(name, 100, '\n');
        cin.ignore(100, '\n');
        cout << "\nPlease enter the media name: ";
        cin.get(media, 100, '\n');
        cin.ignore(100, '\n');
        cout << "\nPlease enter the media description: ";
        cin.get(desc, 300,'\n');
        cin.ignore(100, '\n');
        cout << "\nPlease enter the media length: ";
        cin.get(length, 25, '\n');
        cin.ignore(100, '\n');
        cout << "\nIs there anything that needs to be watched next: ";
        cin.get(isNext, 100, '\n');
        cin.ignore(100, '\n');
        mainTable->insert(name, media, desc, length, isNext);
        data = rand() % 100;
        mainBST->insert(mainTable, data);
        mainBST->display();
    }
    
    if (mainBST)
        delete mainBST;
    if (mainTable)
        delete mainTable;

    return 1;
}