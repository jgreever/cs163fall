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
    char name[100];
    char media[100];
    char desc[300];
    char length[25];
    char isNext[100];
    cout << "\nPlease enter the class name: ";
    cin.get(name, 100, '\n');
    cin.ignore(100, '\n');
    cout << "\nPlease enter the media name: ";
    cin.get(media, 100, '\n');
    cin.ignore(100, '\n');
    cout << "\nPlease enter the media description: ";
    cin.get(desc, 300, '\n');
    cin.ignore(100, '\n');
    cout << "\nPlease enter the media length: ";
    cin.get(length, 25, '\n');
    cin.ignore(100, '\n');
    cout << "\nIs there anything that needs to be watched next: ";
    cin.get(isNext, 100, '\n');
    cin.ignore(100, '\n');
    mainBST->insert(name, media, desc, length, isNext);
    cout << "\nData: ";
    mainBST->display();

    if (mainBST)
        delete mainBST;

    return 1;
}