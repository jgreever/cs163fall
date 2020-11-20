/* main.cpp
 *
 * Justin Greever
 * CS163 - Program 4
 * 11/19/2020
 *
 * Media Management (using BSTs)
 *
 */
#include "table.hpp"
using namespace std;

int main()
{
    bst *mainBST = new bst;

    cout << "\n\nAdding data to the tree...\n";
    mainBST->insert(22);
    mainBST->insert(47);
    mainBST->insert(12);
    mainBST->insert(33);
    mainBST->insert(55);
    mainBST->insert(1);

    mainBST->display();

    if (mainBST)
        delete mainBST;

    return 1;
}