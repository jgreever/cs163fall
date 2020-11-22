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
    char choice[2];
    int data = 0;
    char name[100];
    char media[100];
    char desc[300];
    char length[25];
    char isNext[100];
    char rans[] = "R";
    char eans[] = "A";
    cout << "\n\nWould you like to add random int data\n";
    cout << "Or would you like to add an entry?\n";
    cout << "Enter 'R' for random, 'A' for entry: ";
    cin.get(choice, 2, '\n');
    cin.ignore(100, '\n');
    choice[0] = toupper(choice[0]);
    cout << endl;
    if (strcmp(rans, choice) == 0)
    {
        cout << "\n\nAdding data to the tree...\n\n";
        //TODO: Remove the DEBUG cout and insert(50) function call before turning in
        //TODO: These statements are for testing balance in the BST
        cout << "Debug:\n";
        int root_node = 50;
        mainBST->insert(root_node);
        //cout << "\nDisplay Root Node: ";
        //mainBST->display();
        //cout << endl;
        cout << root_node << ", ";
        for (int i = 0; i < 10; ++i)
        {
            int rng = rand() % 100;
            cout << rng << ", ";
            mainBST->insert(rng);
        }
        cout << "\n";
        mainBST->display();
        cout << "\n\nBST Height: " << mainBST->height() << "\n\n";
    }
    else if (strcmp(eans, choice) == 0)
    {
        cout << "\nPlease enter the class name: ";
        cin.get(name, 100, '\n');
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nPlease enter the media name: ";
        cin.get(media, 100, '\n');
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nPlease enter the media description: ";
        cin.get(desc, 300,'\n');
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nPlease enter the media length: ";
        cin.get(length, 25, '\n');
        cin.clear();
        cin.ignore(100, '\n');
        cout << "\nIs there anything that needs to be watched next: ";
        cin.get(isNext, 100, '\n');
        cin.clear();
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